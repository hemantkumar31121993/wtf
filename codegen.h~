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
	| Argument 1   |
	|--------------|
	| Argument 2   |
	|--------------|
	|	       |
	|--------------|
	| Argument N-1 |
	|--------------|
	| Argument N   |
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
		
		else if(node->nodetype == BODY) {
			codegen(fp,node->ptr1);
			int i = codegen(fp,node->ptr2), k = getreg(fp), n = getreg(fp);
			fprintf(fp,"MOV R%d, BP\nMOV R%d, 2\nSUB R%d, R%d\nMOV [R%d], R%d\n",k,n,k,n,k,i);
			freereg(fp);
			freereg(fp);
			freereg(fp);
			return -1;
		}
		else if(node->nodetype == NUM) {
			int i = getreg(fp);
			fprintf(fp,"MOV R%d, %d\n",i,node->value);
			return i;
		}
	
		else if(node->nodetype == ID) {

			if(node->ptr1 == NULL) {
				int i = getreg(fp), k;
				if( node->gentry != NULL)	//for global variable
					fprintf(fp,"MOV R%d, [%d]\n",i,node->gentry->binding);
				else {
					k = node->lentry->binding;
						//for arguments of the function
					if( node->lentry->magic) {
						//for the reference parameter
						int l = getreg(fp);
						int m = getreg(fp);
						int n = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",n,k);
						fprintf(fp, "ADD R%d, R%d\n",l,n);
						fprintf(fp, "MOV R%d, [R%d]\n",m,l);
						fprintf(fp, "MOV R%d, [R%d]\n",i,m);
						freereg(fp);
						freereg(fp);
						freereg(fp);
					} else {
						//for normal parameter and local variables
						int l = getreg(fp);
						int n = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",n,k);
						fprintf(fp, "ADD R%d, R%d\n",l,n);
						fprintf(fp, "MOV R%d, [R%d]\n",i,l);
						freereg(fp);
						freereg(fp);
					}
				}
				return i;
			} else {
				int i = getreg(fp);
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1);
				fprintf(fp,"MOV R%d, %d\n",k,node->gentry->binding);
				fprintf(fp,"ADD R%d, R%d\n",k,j);
				fprintf(fp,"MOV R%d, [R%d]\n",i,k);
				freereg(fp);
				freereg(fp);
				return i;
			}
		}
		
		else if(node->nodetype == FUNCTION) {
			/*-------------------------------------------------------------------------------------------------
			* As per the standard condition, all the current registers used by the callee is pushed in the stack
			* and freed. Now the values in the arguments has to calculated and must be saved in the registers
			* and register are allocated serially.
			*-------------------------------------------------------------------------------------------------*/
			int argCount = 0;
			
			struct Tnode * args = node->arglist;
			struct ArgStruct *fargs, *dummy;
			fargs = dummy = node->gentry->arglist;
			
			while(args != NULL) { argCount++; args = args->sibling; }
			int currentRegCount = getregCount();
			int i = currentRegCount;
			
			/* Creating the environment for function call */
			
			//saving the registers
			while(i>=0) { 
				fprintf(fp, "PUSH R%d\n",i);
				//freereg();
				i--;
			}
			setregCount(0);
			
			//pushing the arguments
			i = -1;
			args = node->arglist;
			while(args != NULL) {
				if(dummy->ptrType == 0) {
					i=codegen(fp, args);
					fprintf(fp, "PUSH R%d\n",i);
					freereg(fp);
				} else {
					if(args->gentry != NULL) {
						//for global variable
						if(args->ptr1 == NULL) {
							//normal variable
							fprintf(fp, "PUSH %d\n",args->gentry->binding); 
						} else {
							//array element
							i = codegen(fp, args->ptr1);
							int j = getreg(fp);
							fprintf(fp, "MOV R%d, %d\n",j,args->gentry->binding);
							fprintf(fp, "ADD R%d, R%d\n",j,i);
							fprintf(fp, "PUSH R%d\n",j);
							freereg(fp);
							freereg(fp);
						}
					} else {
						//for local variable and arguments
						int b = args->lentry->binding;
						//for arguments to the functions
						if(args->lentry->magic) {
							//reference argument
							i = getreg(fp);
							int k = getreg(fp);
							int m = getreg(fp);
							fprintf(fp, "MOV R%d, BP\n",i);
							fprintf(fp, "MOV R%d, %d\n",m,b);
							fprintf(fp, "ADD R%d, R%d\n",i,m);
							fprintf(fp, "MOV R%d, [R%d]\n",k,i);
							fprintf(fp, "PUSH R%d\n",k);
							freereg(fp);
							freereg(fp);
							freereg(fp);
						} else {
							//normal argument
							i = getreg(fp);
							int m = getreg(fp);
							fprintf(fp, "MOV R%d, BP\n",i);
							fprintf(fp, "MOV R%d, %d\n",m,b);
							fprintf(fp, "ADD R%d, R%d\n",i,m);
							fprintf(fp, "PUSH R%d\n",i);
							freereg(fp);
							freereg(fp);
						}
					}
				}
				dummy = dummy->next;
				args = args->sibling;
			}
			
			fprintf(fp, "PUSH R0\n");	//creating space for return value;
			
			/* function call */
			fprintf(fp, "CALL %s\n", node->name);
			
			/* returned from function call */
			setregCount(currentRegCount + 1);
			int k = currentRegCount + 1;
			
			/*saving the return value to a register R'k' */
			fprintf(fp, "MOV R%d, [SP]\n", k);
			
			/* cleaning up the arguments pushed and return value */
			/*i = argCount;
			while(i>=0) {
				fprintf(fp, "POP R%d\n",(k+1));
				i--;
			} --OBSELETE*/
			fprintf(fp, "MOV R%d, SP\nMOV R%d, %d\nSUB R%d, R%d\nMOV SP, R%d\n", (k+1),(k+2),(argCount + 1),(k+1),(k+2),(k+1));
			
			i=0;
			while(i<=currentRegCount) {
				fprintf(fp, "POP R%d\n", i);
				i++;
			}
			
			/* return the register number in which the return value of the function has been stored */
			return k; 
			
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
				if(node->ptr1->gentry != NULL) {
					//asignment to global variable
					int i = codegen(fp,node->ptr2);
					fprintf(fp,"MOV [%d], R%d\n",node->ptr1->gentry->binding,i);
					freereg(fp);
					
				} else {
					int k = node->ptr1->lentry->binding;
					if(node->ptr1->lentry->magic) {
						//assignment to reference parameter
						int i = codegen(fp,node->ptr2);
						int l = getreg(fp);
						int m = getreg(fp);
						int n = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",m,k);
						fprintf(fp, "ADD R%d, R%d\n",l,m);
						fprintf(fp, "MOV R%d, [R%d]\n",n,l); 
						fprintf(fp, "MOV [R%d], R%d\n",n,i);
						freereg(fp);
						freereg(fp);
						freereg(fp);
						freereg(fp);
					
					} else {
						//assignment to normal parameter and local variables
						int i = codegen(fp,node->ptr2);
						int l = getreg(fp);
						int m = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",m,k);
						fprintf(fp, "ADD R%d, R%d\n",l,m);
						fprintf(fp, "MOV [R%d], R%d\n",l,i);
						freereg(fp);
						freereg(fp);
						freereg(fp);
					}
				}
			} else {
				//asignment to array element(global)
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1->ptr1);
				int l = codegen(fp,node->ptr2);
				fprintf(fp,"MOV R%d, %d\n",k,node->ptr1->gentry->binding);
				fprintf(fp,"ADD R%d, R%d\n",k,j);
				fprintf(fp,"MOV [R%d], R%d\n",k,l);
				freereg(fp);
				freereg(fp);
				freereg(fp);
			}
			
			return -1;
		}
	
		else if(node->nodetype == READ) {
			if(node->ptr1->ptr1 == NULL) {
				if(node->ptr1->gentry != NULL) {
					//reading a global variable
					int i = getreg(fp);
					fprintf(fp,"IN R%d\n",i);
					fprintf(fp,"MOV [%d], R%d\n",node->ptr1->gentry->binding,i);
					freereg(fp);
					
				} else {
					int k = node->ptr1->lentry->binding;
					if(node->ptr1->lentry->magic) {
						//read to reference parameter
						int i = codegen(fp,node->ptr2);
						int l = getreg(fp);
						int m = getreg(fp);
						int n = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",m,k);
						fprintf(fp, "ADD R%d, R%d\n",l,m);
						fprintf(fp, "MOV R%d, [R%d]\n",n,l); 
						fprintf(fp, "MOV [R%d], R%d\n",n,i);
						freereg(fp);
						freereg(fp);
						freereg(fp);
						freereg(fp);
					
					} else {
						//read to normal parameter and local variables
						int i = codegen(fp,node->ptr2);
						int l = getreg(fp);
						int m = getreg(fp);
						fprintf(fp, "MOV R%d, BP\n",l);
						fprintf(fp, "MOV R%d, %d\n",m,k);
						fprintf(fp, "ADD R%d, R%d\n",l,m);
						fprintf(fp, "MOV [R%d], R%d\n",l,i);
						freereg(fp);
						freereg(fp);
						freereg(fp);
					}
				}
				
			} else {
				//reading an array element
				int k = getreg(fp);
				int j = codegen(fp,node->ptr1->ptr1);
				int i = getreg(fp);
				fprintf(fp,"IN R%d\n",i);
				fprintf(fp,"MOV R%d, %d\n",k,node->ptr1->gentry->binding);
				fprintf(fp,"ADD R%d, R%d\n",k,j);
				fprintf(fp,"MOV [R%d], R%d\n",k,i);
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
			int i = codegen(fp,node->ptr1);
			
			if(node->ptr3 == NULL){
				int l = getlabel();
				fprintf(fp,"JZ R%d, LABEL%d\n",i,l);
				freereg(fp);
				codegen(fp,node->ptr2);
				fprintf(fp,"LABEL%d:",l);
				return -1;
			}
			else{
				int l=getlabel();
				int m=getlabel();
				fprintf(fp,"JZ R%d, LABEL%d\n",i,l);
				freereg(fp);
				codegen(fp,node->ptr2);
				fprintf(fp,"JMP LABEL%d\n",m);
				fprintf(fp,"LABEL%d: ",l);
				codegen(fp,node->ptr3);
				fprintf(fp,"LABEL%d: ",m);	
			}
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
