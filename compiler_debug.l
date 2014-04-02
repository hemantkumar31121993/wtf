%{
	#include<stdio.h>
	#include<string.h>
	int yyline=0;
	#include"y.tab.h"
%}

%%
[0-9]+		{printf(" NUM"); yylval.ival=atoi(yytext); return NUM; } 
"read"		{printf(" READ"); return READ; }
"write"		{printf(" WRITE"); return WRITE; }
"if"		{printf(" IF"); return IF; }
"then"		{printf(" THEN");return THEN; }
"else"		{printf(" ELSE");return ELSE; }
"endif"		{printf(" ENDIF");return ENDIF;}
"while"		{printf(" WHILE");return WHILE; }
"do" 		{printf(" DO");return DO;}
"endwhile"	{printf(" ENDWHILE");return ENDWHILE;}

"decl"		{printf(" DECL");return DECL;}
"enddecl"	{printf(" ENDECL");return ENDDECL;}

"begin"		{printf(" BEGIN");return __BEGIN; }
"end"		{printf(" END");return END;}

"integer"	{printf(" INTEGER");return INTEGER;}
"boolean" 	{printf(" BOOLEAN");return BOOLEAN;}

"main"		{printf(" MAIN"); return MAIN; }
"return"	{printf(" RETURN"); return RETURN;}

"&"		{printf( " &"); return *yytext;}

[a-z]+		{printf(" ID`%s`",strdup(yytext));yylval.ch=strdup(yytext); return ID; }		//regex for both normal and array variable
[\[\]\{\}]		{return *yytext; }

"+"		{printf(" PLUS");return PLUS;}
"-"		{printf(" MINUS");return SUBT;}
"*"		{printf(" MULT");return PROD;}
"="		{printf(" ASG");return ASG;}
"("		{printf(" LB");return *yytext; }
")"		{printf(" RB");return *yytext; }
">"		{printf(" GT");return GT; }
"<"		{printf(" LT");return LT; }
"=="		{printf(" EQ");return EQ; }
"@t"		{printf(" TRUE");return __TRUE; }
"@f"		{printf(" FALSE");return __FALSE;}
";"		{printf(" DELIM");return *yytext;}
","		{printf(" ,");return *yytext; }
[\n]		{yyline++;}
[ \t]		;
