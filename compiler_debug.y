%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "compiler.h"
	#include "codegen.h"
	
	extern FILE * yyin;
	FILE * outfile;
	
	//Error Handling function
	void yyerror(const char * str) { fprintf(stderr,"Syntax Error: %s\n",str); }
	
	//wrapping the input after the end of file marker
	int yywrap() { return 1; }
	
	int main(int argc, char * argv[]) {
	
		if(argc < 2) {
			printf("Usage: ./compiler <filename>\n");
			return 0;
		}
		
		FILE * fp = fopen(argv[1],"r");
		outfile = fopen("program.sim", "w");
		
		if(!fp) {
			printf("Error 404 : File not Found. Go and Search for it :p\n");
			return 1;
		}
		
		yyin = fp;
		
		initCompiler();
		
		/* creating the file context */
		fprintf(outfile, "START\nMOV SP, 2048\nMOV BP, SP\nJMP MAIN\n");
		yyparse();
		fprintf(outfile, "EXIT:\nHALT\n");
		
		return 1;
	}
%}


%union{ 
	struct Tnode *node;
	int ival;
	char *ch;
}


%type <node> slist expr stat arglist body fbody

%token <ival> NUM 
%token <ch> ID 
%token <node> PLUS PROD SUBT ASG GT LT EQ AND OR NOT READ WRITE IF WHILE
%token MAIN RETURN INTEGER BOOLEAN __TRUE __FALSE DECL ENDDECL __BEGIN END __EXIT THEN ELSE ENDIF DO ENDWHILE

%right ASG
%nonassoc OR
%nonassoc AND
%nonassoc NOT
%nonassoc GT LT EQ
%left PLUS SUBT 
%left PROD

%start program



%%
program :	Gdeclaration {printf("Declaration Complete");}Fdefinition MainBlock
	;

Gdeclaration :	DECL Gdeclist ENDDECL	{ 	struct Gsymbol * p = symtable;
						printf("\nSymbol Table: \n");
						if(p ==NULL){printf("Pnull ");}
						while(p != NULL) {
							printf("%s,%d,%d,%d--> ",p->name,p->size,p->binding,p->type);
							p = p->next;
							
						}
						printf("\n");
					}
	;
Gdeclist :	
	|	 Gdeclist INTEGER Gvarlist ';'	{	struct VarList * p;
							while(vstart != NULL) {
								Ginstall(vstart->name,INTEGER,vstart->size,vstart->arglist);
								p = vstart;
								vstart = vstart->next;
								free(p);
							}
							vstart = NULL;
							vend = NULL;
						}
	|	 Gdeclist BOOLEAN Gvarlist ';'	{	struct VarList * p;
							while(vstart != NULL) {
								Ginstall(vstart->name,BOOLEAN,vstart->size,vstart->arglist);
								p = vstart;
								vstart = vstart->next;
								free(p);
							}
							vstart = NULL;
							vend = NULL;
						}
	;
	
Gvarlist:	ID				{insertVar($1,1,0);}
	|	ID '[' NUM ']'			{insertVar($1,$3,0);}
	|	ID '(' FargDef ')'		{insertVar($1,0,1);}
	|	ID ',' Gvarlist			{insertVar($1,1,0);}
	|	ID '[' NUM ']' ',' Gvarlist	{insertVar($1,$3,0);}
	|	ID '(' FargDef ')' ',' Gvarlist {insertVar($1,0,1);}
	;	
	
FargDef :	
	|	FargDef INTEGER Farglist ';'	{
							//create arg list of integer types
							while(fstart != NULL) {
								fstart->type = INTEGER;
								faddArg(fstart);
								fstart = fstart->next;
							}
						}
	|	FargDef BOOLEAN	Farglist ';'	{
							//create arg list of boolean types
							while(fstart != NULL) {
								fstart->type = BOOLEAN;
								faddArg(fstart);
								fstart = fstart->next;
							}
						}
	;
	
Farglist: 	ID				{	finsertVar($1,0); }
	|	'&' ID				{	finsertVar($2,1); }
	|	Farglist ',' ID	 		{	
							finsertVar($3,0);
						}
	|	Farglist ',' '&' ID		{
							finsertVar($4,1);
						}
	;
	
/*-----------------------------------------------------------------------------------
The caller of the function has to push the arguments before calling the function.
The schema which is being used here is that the last argument to the funtion will be
pushed first and then so on. 

So the state of stack before call of the function
	
	|--------------|
	| Argument 1   |
	|--------------|
	| Argument 2   |
	|--------------|
	| Argument 3   |
	|--------------|
	|	       |
	|--------------|
	| Argument N-2 |
	|--------------|
	| Argument N-1 |
	|--------------|
SP --->	| Argument N   |
	|--------------|

Therefore, it is convinient to first create the list of arguments last to first then pushing
the first element first and then so on.
----------------------------------------------------------------------------------------*/
Fdefinition :			{ lsymtable = lsymtableLast = NULL; fargTable = fargTableLast = NULL; }
	
	|	Fdefinition INTEGER ID '(' FargDef ')' '{' ldeclaration fbody '}' 
						{	
							
							if(func_typecheck($3,fargTable,INTEGER,$9->ptr2->type)){
								struct Gsymbol * f = Glookup($3);
								
								int k = getLocalVarCount() - getArgCount();  //local vars only
								
								int i = 0;
								
								fprintf(outfile, "%s:\n",$3);
								//setting up the base pointer
								fprintf(outfile, "PUSH BP\nMOV BP, SP\n");
								
								//pushing space for local vairables

								if(k>0)
									fprintf(outfile, "MOV R0, SP\nMOV R1, %d\nADD R0, R1\nMOV SP, R0\n",k);
								
								//codegeneration of functione body
								codegen(outfile, $9);
								
								//resetting the SP and BP
								fprintf(outfile, "MOV SP, BP\n");
								fprintf(outfile, "POP BP\n");
								
								//return 
								fprintf(outfile,"RET\n");	
							}
							lsymtable = lsymtableLast = NULL;
							fargTable = fargTableLast = NULL;

						}
	
	|	Fdefinition BOOLEAN ID '(' FargDef ')' '{' ldeclaration fbody '}'	
						{
							if(func_typecheck($3,fargTable,BOOLEAN,$9->ptr2->type)){
								struct Gsymbol * f = Glookup($3);
								
								int k = getLocalVarCount() - getArgCount();
								
								int i = 0;
								
								fprintf(outfile, "%s:\n",$3);
								//setting up the base pointer
								fprintf(outfile, "PUSH BP\nMOV BP, SP\n");
								
								//pushing space for local vairables
								
								if(k>0)
									fprintf(outfile, "MOV R0, SP\nMOV R1, %d\nADD R0, R1\nMOV SP, R0\n",k);
								
								//codegeneration of functione body
								codegen(outfile, $9);
								
								//resetting the SP and BP
								fprintf(outfile, "MOV SP, BP\n");
								fprintf(outfile, "POP BP\n");
								
								//return 
								fprintf(outfile,"RET\n");	
							}
							lsymtable = lsymtableLast = NULL;
							fargTable = fargTableLast = NULL;
					
						}
	;
	
MainBlock :	INTEGER MAIN '(' ')' '{' ldeclaration fbody '}'	
						{ 
							fprintf(outfile,"MAIN :\n");
							printf("I got a main");
							//TODO: push the local variables in the stack
							int k = getLocalVarCount();
							int i = 0;
					
							//pushing space for local vairables
							if(k>0)
								fprintf(outfile, "MOV R0, SP\nMOV R1, %d\nADD R0, R1\nMOV SP, R0\n",k);
							
							//codegeneration of functione body
							codegen(outfile, $7);
					
							if(k>0)
								fprintf(outfile, "MOV R0, SP\nMOV R1, %d\nSUB R0, R1\nMOV SP, R0\n",k);
							
							//EXIT 
							fprintf(outfile,"JMP EXIT\n");
						}
	;


ldeclaration : DECL localdeclList ENDDECL	{ 
							argsToLocalVars(fargTable); 
							printf("Local Symbol table");
							struct Lsymbol *r = lsymtable;
							while(r != NULL) {
								printf("%s|%d|%d-->",r->name,r->type,r->magic);
								r = r->next;
							}
						}
	;
	
		
localdeclList :	 {lvarType = 0; }
	|	localdeclList INTEGER {lvarType = INTEGER;} localvarlist ';' {}
	
	|	localdeclList BOOLEAN {lvarType = BOOLEAN;} localvarlist ';' {}
	;
	
localvarlist 	:	ID 			{ linstall($1, lvarType); }
		|	localvarlist ',' ID	{ linstall($3, lvarType); }
		;
	
fbody	:	__BEGIN body END	{$$=$2;}
	;
	
body	:	 slist RETURN expr ';' 	{$$=TreeCreate(VOID,BODY,-1,NULL,NULL,$1,$3,NULL);}
	;
	
slist	:			{$$=TreeCreate(VOID,SLIST,-1,NULL,NULL,NULL,NULL,NULL);}	
	|	slist stat	{$$=TreeCreate(VOID,SLIST,-1,NULL,NULL,$1,$2,NULL);}
	;

stat	:	ID ASG expr ';'			{	
							struct Lsymbol * l = Llookup($1);
							if( l != NULL) {
								printf("Local Lookup");
								struct Tnode *nid =TreeCreate(l->type,ID,-1,$1,NULL,NULL,NULL,NULL);
								nid->lentry = l;
								nid->gentry = NULL;
								$$=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,$3,NULL);
							} else {
								printf("global lookup");
								struct Gsymbol * v = Glookup($1);
								struct Tnode *nid=TreeCreate(v->type,ID,-1,$1,NULL,NULL,NULL,NULL);
								nid->gentry = v;
								nid->lentry = NULL;
								$$=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,$3,NULL);
							}
						}
	
	|	ID '[' expr ']' ASG expr ';'	{
							struct Gsymbol * v = Glookup($1);
							struct Tnode *nid = TreeCreate(INTEGER,ID,-1,$1,NULL,$3,NULL,NULL);
							nid->gentry = v;
							$$=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,$6,NULL);
						}
						
	|	READ '(' ID ')' ';'		{	
							struct Lsymbol * l = Llookup($3);
							if( l != NULL) {
								printf("Local Lookup");
								struct Tnode *nid =TreeCreate(l->type,ID,-1,$3,NULL,NULL,NULL,NULL);
								nid->lentry = l;
								nid->gentry = NULL;
								$$=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
							} else {
								printf("global lookup");
								struct Gsymbol * v = Glookup($3);
								struct Tnode *nid=TreeCreate(v->type,ID,-1,$3,NULL,NULL,NULL,NULL);
								nid->gentry = v;
								nid->lentry = NULL;
								$$=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
							}
						}
						
	|	READ '(' ID '[' expr ']' ')' ';'	{	
							struct Gsymbol * v = Glookup($3);
							struct Tnode *nid = TreeCreate(INTEGER,ID,-1,$3,NULL,$5,NULL,NULL);
							nid->gentry = v;
							$$=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
						}
	
	|	WRITE '(' expr ')' ';'			{$$=TreeCreate(VOID,WRITE,-1,NULL,NULL,$3,NULL,NULL);}
	|	IF expr THEN slist ENDIF ';'		{$$=TreeCreate(VOID,IF,-1,NULL,NULL,$2,$4,NULL);}
	|	IF expr THEN slist ELSE slist ENDIF ';'		{$$=TreeCreate(VOID,IF,-1,NULL,NULL,$2,$4,$6);}
	|	WHILE expr DO slist ENDWHILE ';' 	{$$=TreeCreate(VOID,WHILE,-1,NULL,NULL,$2,$4,NULL);}
	;


/*--------------------------------------------------------------------------------------------------------
this will create a list of arguments which have to pass to the function
using sibling of Tnode to create the linked list of arguments to pass to the function

The argument list will be created with first argument at the fist
e.g. if function is karl is called with thee arguments, karl(A,B,C).
then the argument list will be
	 ____      ____      ____
	|_A_| --> |_B_| --> |_C_| --> null
	
--------------------------------------------------------------------------------------------------------*/

arglist :	expr			{	$1->sibling = NULL; 
						$$ = $1;
					}
					
	|	expr ',' arglist	{	$1->sibling = $3;
						$$ = $1;
					}
	;

expr	:       NUM     	        {$$=TreeCreate(INTEGER,NUM,$1,NULL,NULL,NULL,NULL,NULL);}
	
	|	__TRUE			{$$=TreeCreate(BOOLEAN,NUM,1,NULL,NULL,NULL,NULL,NULL);}
	
	|	__FALSE			{$$=TreeCreate(BOOLEAN,NUM,0,NULL,NULL,NULL,NULL,NULL);}

	|	ID			{	
						struct Lsymbol * l = Llookup($1);
						if( l != NULL) {
							printf("Local Lookup");
							$$=TreeCreate(l->type,ID,($1[0]-'a'),$1,NULL,NULL,NULL,NULL);
							$$->lentry = l;
							$$->gentry = NULL;
						} else {
							printf("global lookup");
							struct Gsymbol * v = Glookup($1);
							$$=TreeCreate(v->type,ID,($1[0]-'a'),$1,NULL,NULL,NULL,NULL);
							$$->gentry = v;
							$$->lentry = NULL;
						}
					}
	|	ID '[' expr ']'		{	struct Gsymbol * v = Glookup($1);
						$$=TreeCreate(v->type,ID,($1[0]-'a'),$1,NULL,$3,NULL,NULL); 
						$$->gentry = v;
					}	
					
	|	ID '(' arglist ')'	{	struct Gsymbol *v = Glookup($1);
						struct ArgStruct *k = v->arglist;
						struct Tnode * arg = $3;
						while(arg != NULL && k!= NULL) {
							printf("%s|%d|%d",arg->name,arg->type,k->ptrType);
							arg = arg->sibling;
							k = k->next;
						}
						//the ArgList pointer is used to point to arguments
						if(argCompatibleToFunc(v, $3)) {
							$$=TreeCreate(v->type,FUNCTION,-1,$1,$3,NULL,NULL,NULL);
							$$->gentry = v;
						}
					}
					
	|	ID '('	')'		{	struct Gsymbol *v = Glookup($1);
						$$=TreeCreate(v->type,FUNCTION,-1,$1,NULL,NULL,NULL,NULL);
						$$->gentry = v;
					}				
	
	|	'(' expr ')'		{$$=$2;}
	|	expr PLUS expr		{$$=TreeCreate(INTEGER,PLUS,-1,NULL,NULL,$1,$3,NULL);}
	|	expr SUBT expr		{$$=TreeCreate(INTEGER,SUBT,-1,NULL,NULL,$1,$3,NULL);}
	|	expr PROD expr		{$$=TreeCreate(INTEGER,PROD,-1,NULL,NULL,$1,$3,NULL);}
	|	expr GT expr 		{$$=TreeCreate(BOOLEAN,GT,-1,NULL,NULL,$1,$3,NULL);}
	|	expr LT expr	 	{$$=TreeCreate(BOOLEAN,LT,-1,NULL,NULL,$1,$3,NULL);}
	|	expr EQ expr 		{$$=TreeCreate(BOOLEAN,EQ,-1,NULL,NULL,$1,$3,NULL);}
	|	expr AND expr 		{$$=TreeCreate(BOOLEAN,AND,-1,NULL,NULL,$1,$3,NULL);}
	|	expr OR expr 		{$$=TreeCreate(BOOLEAN,OR,-1,NULL,NULL,$1,$3,NULL);}
	|	NOT expr 		{$$=TreeCreate(BOOLEAN,NOT,-1,NULL,NULL,$1,NULL,NULL);}
	;
%%


