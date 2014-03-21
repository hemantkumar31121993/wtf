%{
	#include<stdio.h>
	#include<string.h>
	int yyline=0;
	#include"y.tab.h"
%}

%%
[0-9]+		{yylval.ival=atoi(yytext); return NUM; } 
"read"		return READ;
"write"		return WRITE;
"if"		return IF;
"then"		return THEN;
"endif"		return ENDIF;
"while"		return WHILE;
"do" 		return DO;
"endwhile"	return ENDWHILE;

"decl"		return DECL;
"enddecl"	return ENDDECL;

"begin"		return __BEGIN; 
"end"		return END;

"integer"	return INTEGER;
"boolean" 	return BOOLEAN;

"main"		return MAIN;
"return"	return RETURN;

"&"		return *yytext;

[a-z]+		{yylval.ch=strdup(yytext); return ID; }
[\[\]\(\)\{\}]	return *yytext;

"+"		return PLUS;
"-"		return SUBT;
"*"		return PROD;
"="		return ASG;
">"		return GT;
"<"		return LT;
"=="		return EQ;
"@t"		return __TRUE;
"@f"		return __FALSE;
";"		return *yytext;
","		return *yytext;
[\n]		{yyline++;}
[ \t]		;
