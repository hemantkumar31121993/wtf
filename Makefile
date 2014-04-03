executable: compiler compiler_debug

compiler:
	yacc -d compiler.y
	lex compiler.l
	gcc lex.yy.c y.tab.c -ly -ll -o compiler
	
compiler_debug:
	yacc -d compiler_debug.y
	lex compiler_debug.l
	gcc lex.yy.c y.tab.c -ly -ll -o compiler_debug
	
clean:
	rm lex.yy.c y.tab.c y.tab.h compiler compiler_debug
