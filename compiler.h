#include "y.tab.h"
#include "structures.h"
/* Line number of current token */
extern int yyline;

//predefined values to denote the node types, must not conflict with yacc generated token values
#define VOID 2156
#define SLIST 4862
#define BODY 5896
#define FUNCTION 7426

/*----------------------------------------------------------------------
Register Allocation : Register is allocated starting from R0 to R8.
getreg is used to reserve a register. freereg frees the last used register.
If current count of reserved registers increses from 8 then, oldest register
is pushed into the stack and when freed the oldest register is popped from
stack.

BUG :: THIS LIMITS THE COUNT OF THE ARGUMENTS PASSED TO THE FUNCTION TO 8.
NEED TO BE FIXED OR FIND A NEW WAY TO DO IT! 
----------------------------------------------------------------------*/
int reg = 0;

int getregCount() {
	return reg;
}

void setregCount(int v) {
	reg = v;
}

int getreg(FILE *fp) {
	reg++;
	if(reg >= 8) 
	{
		fprintf(fp,"PUSH R%d\n",(reg-1)%8);
	}
	return (reg-1)%8;
}

void freereg(FILE *fp){ 
	if(reg >= 8) 
	{
		fprintf(fp,"POP R%d\n",reg%8);
		reg--;
	}
	else if(reg == 0) ;
	else reg--;
}


/*---------------------------------------------------------------------------------
Label Generation : it is very easy to generate the labels. 
----------------------------------------------------------------------------------*/
int label = 0;
int getlabel() {
	return label++;
}


/*-------------------------------------------------------------------------------
Global Variables
symtable : global symbol table
symtableLast : pointer to last entry of global symbol table

lsymtable : local symbol table
lsymtableLast : pointer to last entry of local symbol table
lvarType : the type of local variable

fargTable : argument list of function
fargTableLast : pointer to last entry of argument table
fstart, fend : control variables

vstart, vend : list creation (helping) variables for global symbol table
--------------------------------------------------------------------------------*/

struct Gsymbol *symtable, *symtableLast;

struct Lsymbol *lsymtable, *lsymtableLast ;
int lvarType = 0;

struct ArgStruct *fargTable, *fargTableLast, *fstart, *fend;
char * fname;

struct VarList *vstart, *vend ;

/* Initiates all the tables */
void initCompiler() {
	symtable = NULL;
	symtableLast = NULL;
	vstart = vend = NULL;
	fargTable = fargTableLast = NULL;
	fstart = fend = NULL;
	lsymtable = lsymtableLast = NULL;
}

/*--------------------------------------------------------------------------------
Global Symbol Table query functions
Ginstall : installs the variable 
Gcheck : checks if given identifier name exists or not
Glookup : returns the pointer to the entry in global symbol table for given 
	  identifier name
--------------------------------------------------------------------------------*/
struct Gsymbol *Gcheck(char *name) {
	struct Gsymbol * p;
	p = symtable;
	while(p != NULL) {
		if(!(strcmp(p->name,name)))
			return p;
		p = p->next;
	}
	return NULL;
}

void Ginstall(char *name,int type,int size,struct ArgStruct *arglist) {

	if(Gcheck(name) == NULL) {
		struct Gsymbol * p = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
		p->name = name;
		p->type = type;
		p->size = size;
		if(symtableLast == NULL) {
			p->binding = 0;
		} else {
			p->binding = symtableLast->binding + symtableLast->size;
		}
		p->arglist = arglist;
		p->next = NULL;
	
		if(symtable == NULL) {
			symtable = p;
			symtableLast = p;
		} else {
			symtableLast->next = p;
			symtableLast = p;
		}
	} else {
		printf("ERROR : line %d : Multiple Declaration of variable %s\n",yyline,name);
		exit(1);
	}
}

struct Gsymbol *Glookup(char *name) {
	struct Gsymbol * p;
	p = symtable;
	while(p != NULL) {
		printf("%s ",p->name);
		if(!(strcmp(p->name,name)))
			return p;
		p = p->next;
	}
	
	printf(" ERROR : line %d : identifier %s is not declared.\n",yyline,name);
	exit(1);
	return NULL;
}

/*----------------------------------------------------------------------------------------------------
insertVar : creates a list of variables, helps in creating the global symbol table
----------------------------------------------------------------------------------------------------*/
void insertVar(char * name,int size,int isFunc) {
	struct VarList * var = (struct VarList *)malloc(sizeof(struct VarList));
	var->name = name;
	var->size = size;
	if(isFunc) {
		var->arglist = fargTable;
		fargTable = NULL;
	} else {
		var->arglist = NULL;
	}
	var->next = NULL;
	if(vstart == NULL) {
		vstart = var;
	} else {
		var->next = vstart;
		vstart = var;
	}
	
}


/*----------------------------------------------------------------------------------------------------
Functions to create nodes for Abstract Syntax Tree
TreeCreate : returns a node
type_check : checks if the children are compatible to the current node or not
----------------------------------------------------------------------------------------------------*/
struct Tnode *TreeCreate(int type,int nodetype, int value,char * name, struct Tnode * arglist, struct Tnode * ptr1, struct Tnode * ptr2, struct Tnode * ptr3) {
	if(type_check(nodetype,ptr1 ,ptr2 ,ptr3)) {
		struct Tnode *p;
		p = (struct Tnode *)malloc(sizeof(struct Tnode));
		p->type=type;
		p->nodetype=nodetype;
		p->value=value;
		p->name=name;
		p->arglist=arglist;
		p->ptr1=ptr1;
		p->ptr2=ptr2;
		p->ptr3=ptr3;
		p->sibling = NULL;
		return p;
	} else {
		printf("\n ERROR : line %d : %d SYNTAX ERROR : OPERANDS ARE NOT COMPATIBLE TO THE OPERATOR.",yyline,nodetype);
		exit(1);
	}
}

int type_check(int nodetype, struct Tnode *ptr1 ,struct Tnode *ptr2 ,struct Tnode *ptr3)
{
	switch(nodetype)
	{
		case ID   : return( (ptr1 == NULL) || (ptr1->type == INTEGER) );
		
		case PLUS : return(ptr1->type == INTEGER && ptr2->type == INTEGER);
		
		case PROD : return(ptr1->type == INTEGER && ptr2->type == INTEGER);

		case IF	  : return(ptr1->type == BOOLEAN && ptr2->type == VOID );

		case WHILE : return(ptr1->type == BOOLEAN && ptr2->type == VOID && ptr3 == NULL);

		case ASG : return(
					(ptr1->nodetype == ID && ptr1->type == INTEGER && ptr2->type == INTEGER)
					||
					(ptr1->nodetype == ID && ptr1->type == BOOLEAN && ptr2->type == BOOLEAN)
				);
		
		case READ : return (ptr1->type == INTEGER && ptr2 == NULL);

		case GT :  return(ptr1->type == INTEGER && ptr2->type == INTEGER);

		case LT : return(ptr1->type == INTEGER && ptr2->type == INTEGER);

		case EQ : return(ptr1->type == INTEGER && ptr2->type == INTEGER);
		
		case AND : return(ptr1->type == BOOLEAN && ptr2->type == BOOLEAN);
		
		case OR : return(ptr1->type == BOOLEAN && ptr2->type == BOOLEAN);
		
		case NOT : return(ptr1->type == BOOLEAN);
		
		case WRITE : return(ptr1->type == INTEGER);
	}
}

/*----------------------------------------------------------------------------------------------------
Local Symbol Table
linstall : creates local symbol table for a function
lcheck : checks if a identifier with given name exits
Llookup : returns the pointer to the entry in local symbol table
getLocalVarCount : returns the count of local variables of the functions
----------------------------------------------------------------------------------------------------*/
int lcheck(char * n) {
	struct Lsymbol * t = lsymtable;
	while(t != NULL) {
		//printf("%s ",t->name);
		if(!strcmp(n, t->name)) {
			return 0;
		}
		t = t->next;
	}
	return 1;
}
void linstall(char *name, int type) {
	if(lcheck(name)) {
		struct Lsymbol * p = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
		p->name = name;
		p->type = type;
		p->magic = 0;
		if( lsymtable == NULL) {
			p->binding = 1;
			lsymtable = lsymtableLast = p;
		} else {
			p->binding = lsymtableLast->binding + 1;
			lsymtableLast->next = p;
			lsymtableLast = p;
		}
	} else {
		printf("ERROR : line %d : Variable %s has been defined twice in same scope.\n",yyline,name);
		exit(1);
	}
}

struct Lsymbol * Llookup(char * n) {
	struct Lsymbol * t = lsymtable;
	while(t != NULL) {
		printf("%s ",t->name);
		if(!strcmp(n, t->name)) {
			return t;
		}
		
		t = t->next;
	}
	/*printf(" ERROR : line %d : identifier %s is not declared.\n",yyline,n);
	exit(1); */
	return NULL;
}

int getLocalVarCount() {
	int i = 0;
	struct Lsymbol * t = lsymtable;
	while(t != NULL) {
		i++;
		t = t->next;
	}
	return i;
}

/*-----------------------------------------------------------------------------------------------------
Agrument list creater functions

finsertVar : creates an untyped list of function arguments
faddArg : adds an typed argument to argument list of functions
------------------------------------------------------------------------------------------------------*/
void finsertVar(char * name, int ptrType) {
	struct ArgStruct * arg = (struct ArgStruct *)malloc(sizeof(struct ArgStruct));
	arg->name = name;
	arg->ptrType = ptrType;
	arg->next = NULL;
	if(fstart == NULL) {
		fstart = fend = arg;
	} else {
		fend->next = arg;
		fend = arg;
	}
}

void faddArg(struct ArgStruct * arg) {
	if(fargTable == NULL) {
		fargTable = fargTableLast = arg;
	} else {
		fargTableLast->next = arg;
		fargTableLast = arg;
	}
}


/*-----------------------------------------------------------------------------------------------------
Function Validators

func_typecheck : checks is there any differnce between the function declaration and function definition
		with name equivalance

argCompatibleToFunc : during function call checks if arguments supplied is compatible to function or not
------------------------------------------------------------------------------------------------------*/
int func_typecheck(char *name,struct ArgStruct *fargTable,int rettype,int type){
	struct Gsymbol *p = Glookup(name);
	struct ArgStruct *q=fargTable;
	int flag=1;
	if(p==NULL){
		flag=0;
		printf("No such function exist");
	}
	else if(rettype != type){
		flag=0;
		printf("Return Type doesn't matches");
	}
	else{
		struct ArgStruct *arglist=p->arglist;
		while(arglist!=NULL && q!=NULL){
			if(arglist->name==q->name && arglist->ptrType==q->ptrType && arglist->type==q->type){
				arglist=arglist->next;
				q=q->next;
			}
			else { printf("Argument doesn't match"); flag=0; return flag;}
		}
		if(arglist==NULL && q==NULL) return flag;
	}
	return flag;
}
		
int argCompatibleToFunc(struct Gsymbol * f, struct Tnode * args) {
	int flag = 1;
	struct ArgStruct * arglist = f->arglist;
	while( arglist != NULL && args != NULL) {
		if(arglist->type != args->type) {
			break;
		}
		if( (arglist->ptrType == 1 ) && ( args->nodetype != ID)) {
			printf("ERROR : line %d : Reference Arguments to function %s must be an identifier.\n",yyline,f->name);
			return 0;
		}
		arglist = arglist->next;
		args = args->sibling;
	}
	
	if(arglist != NULL && args !=NULL) {
		printf("ERROR : line %d : Arguments to function %s mismatched.\n",yyline,f->name);
		return 0;
	}
	
	if( (arglist != NULL || args != NULL)) {
		printf("ERROR : line %d : Length of arguments to function %s mismatched.\n", yyline,f->name);
		return 0; 
	}
	return 1;
}	

/*-----------------------------------------------------------------------------------------------------
argsToLocalVars : forcefully inserts the arguments of the function in local symbol table with negative 
binding value, so that they can be easily be reference relative to BP 
------------------------------------------------------------------------------------------------------*/
void argsToLocalVars(struct ArgStruct * args) {
	printf("Converting args to local vars");
	int binding = -2;
	struct ArgStruct * dummy = args;
	while(dummy != NULL) {
		binding--;
		dummy = dummy->next;
	}
	
	while(args != NULL) {
		struct Lsymbol * l = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
		l->name = args->name;
		l->type = args->type;
		l->binding = binding;
		l->magic = args->ptrType;
		
		l->next = lsymtable;
		lsymtable = l;		
		binding++;
		args = args->next;
	}
}
