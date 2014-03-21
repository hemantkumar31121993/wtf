executable: compiler

compiler:
	yacc -d compiler.y
	lex compiler.l
	gcc lex.yy.c y.tab.c -ly -ll -o compiler
	
clean:
	rm lex.yy.c y.tab.c y.tab.h compiler
