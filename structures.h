
/*--------------------------------------------------------------------------------------
ArgStruct : Structure for the creating the argument list of the function at declaration.
the attribute ptrType is set to 1 when argument had to be passed by reference (Call by Reference)
0 otherwise.
----------------------------------------------------------------------------------------*/
struct ArgStruct{
	char *name;
	int type;
	int ptrType;
	struct ArgStruct *next;
};
	

/*------------------------------------------------------------------
Gsymbol : Structure to create the global symbol table for the program.
This table have to presered till the last and if dynamic linking is supported
by the compiler then global symbol table have to be preserved even after the compilation
--------------------------------------------------------------------*/
struct Gsymbol {
	char *name;		
	int type;
	int size;
	int binding;
	struct ArgStruct *arglist;
	struct Gsymbol *next;
};


/*-----------------------------------------------------------------------------
Lsymbol : Structure to create the local symbol table for a function
This is need only for the code generation of the function after that it can be
discarded. The binding field in Lsybol is logical offset from BP. The magic field
equal to 1 indicates that the value at the memory is an absolute memory address
else it contains just a numerical value (used for Call by Reference).
------------------------------------------------------------------------------*/
struct Lsymbol {
	char *name;		
	int type;
	int binding;
	int magic;
	struct Lsymbol *next;
};



/*----------------------------------------------------------------------------------
Varlist : Structure for creating the varialbe list for global declaration. 
If an identifier is function then arglist points to the argument list of the function.
-----------------------------------------------------------------------------------*/
struct VarList {
	char * name;
	int size;
	struct ArgStruct *arglist;
	struct VarList * next;
};


/*------------------------------------------------------------------------------------
Tnode : structure to create Abstract Syntax Tree of the program.
sibling field is used to create a list of arguments for function call.
-------------------------------------------------------------------------------------*/
struct Tnode {
	int type;
	int nodetype;
	char * name;
	int value;
	struct Tnode * arglist;
	struct Tnode *ptr1, *ptr2, *ptr3;
	struct Tnode * sibling;
	struct Gsymbol * gentry;
	struct Lsymbol * lentry;	
};



