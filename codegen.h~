/*---------------------------------------------------------------------------------
codegen : generates the code for given subtree rooted at node
	  return the register number which is reserved for this node else -1

The code for a function call is very cool thing in code generation. For this the callee
has to push all its current register, arguements to the function, blank space for return
value.
So the state of stack just before function call is somthing like this

SP -->	|--------------|
	| Register Rk  |
	|--------------|
	| Register Rk-1|
	|--------------|
	|	       |
	|--------------|
	| Register R0  |
	|--------------|
	| Argument N   |
	|--------------|
	| Argument N-1 |
	|--------------|
	|	       |
	|--------------|
	| Argument 2   |
	|--------------|
	| Argument 1   |
	|--------------| 

After the return from the function call, callee has to pop out the arguments from the
stack and restore the registers.
------------------------------------------------------------------------------------*/
#include "y.tab.h"

int codegen(FILE * fp, struct Tnode *node) {
	if(node != NULL) {
		if(node->nodetype == SLIST) {
			codegen(fp,node->ptr1);
			codegen(fp,node->ptr2);
			return -1;
		}
		else if(node->nodetype == NUM) {
			int i = getreg(fp);
			fprintf(fp,"MOV R%d %d\n",i,node->value);
			return i;
		}
	
		else if(node->nodetype == ID) {
			if(node->ptr1 == NULL) {
				int i = getreg(fp);
				fprintf(fp,"MOV R%d [%d]\n",i,node->gentry->binding);
				return i;
			} else {
				int i = getreg(fp);
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1);
				fprintf(fp,"MOV R%d %d\n",k,node->gentry->binding);
				fprintf(fp,"ADD R%d R%d\n",k,j);
				fprintf(fp,"MOV R%d [R%d]\n",i,k);
				freereg(fp);
				freereg(fp);
				return i;
			}
		}
		
		else if(node->nodetype == FUNCTION) {
			
			
		}
		else if(node->nodetype == PLUS) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"ADD R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
		
		else if(node->nodetype == SUBT) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"SUB R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
	
		else if(node->nodetype == PROD) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"MUL R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
	
		else if(node->nodetype == GT) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"GT R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
	
		else if(node->nodetype == LT) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"LT R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
	
		else if(node->nodetype == EQ) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"EQ R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
		else if(node->nodetype == AND) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"MUL R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
		
		else if(node->nodetype == OR) {
			int i = codegen(fp,node->ptr1);
			int j = codegen(fp,node->ptr2);
			fprintf(fp,"ADD R%d, R%d\n",i,j);
			freereg(fp);
			return i;
		}
		
		else if(node->nodetype == NOT) {
			int i = codegen(fp,node->ptr1);
			fprintf(fp,"EQ R%d 0\n",i);
			return i;
		}
	
		else if(node->nodetype == ASG) {
			//printf("SEG FAULT");
			if(node->ptr1->ptr1 == NULL) {
				//asignment to normal variable
				int i = codegen(fp,node->ptr2);
				fprintf(fp,"MOV [%d] R%d\n",node->ptr1->gentry->binding,i);
				freereg(fp);
				return -1;
			} else {
				//asignment to array element
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1->ptr1);
				int l = codegen(fp,node->ptr2);
				fprintf(fp,"MOV R%d %d\n",k,node->ptr1->gentry->binding);
				fprintf(fp,"ADD R%d R%d\n",k,j);
				fprintf(fp,"MOV [R%d] R%d\n",k,l);
				freereg(fp);
				freereg(fp);
				freereg(fp);
				return -1;
			}
		}
	
		else if(node->nodetype == READ) {
			if(node->ptr1->ptr1 == NULL) {
				//asignment to normal variable
				int i = getreg(fp);
				fprintf(fp,"IN R%d\n",i);
				fprintf(fp,"MOV [%d] R%d\n",node->ptr1->gentry->binding,i);
				freereg(fp);
				return -1;
				
			} else {
				//asignment to array element
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1->ptr1);
				int i = getreg(fp);
				fprintf(fp,"IN R%d\n",i);
				fprintf(fp,"MOV R%d %d\n",k,node->ptr1->gentry->binding);
				fprintf(fp,"ADD R%d R%d\n",k,j);
				fprintf(fp,"MOV [R%d] R%d\n",k,i);
				freereg(fp);
				freereg(fp);
				freereg(fp);
				return -1;
			}
		}
	
		else if(node->nodetype == WRITE) {
			int i = codegen(fp,node->ptr1);
			fprintf(fp,"OUT R%d\n",i);
			freereg(fp);
			return -1;
		}
	
		else if(node->nodetype == IF) {
			int l = getlabel();
			int i = codegen(fp,node->ptr1);
			fprintf(fp,"JZ R%d, LABEL%d\n",i,l);
			freereg(fp);
			codegen(fp,node->ptr2);
			fprintf(fp,"LABEL%d:",l);
			return -1;
		}
	
		else if(node->nodetype == WHILE) {
			int l = getlabel();
			int m = getlabel();
			fprintf(fp,"LABEL%d:",l);
			int i = codegen(fp,node->ptr1);
			fprintf(fp,"JZ R%d, LABEL%d\n",i,m);
			freereg(fp);
			codegen(fp,node->ptr2);
			fprintf(fp,"JMP LABEL%d\n",l);
			fprintf(fp,"LABEL%d:",m);
			return -1;
		}
	}
	return -1;
}
