/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     ID = 259,
     PLUS = 260,
     PROD = 261,
     SUBT = 262,
     ASG = 263,
     GT = 264,
     LT = 265,
     EQ = 266,
     AND = 267,
     OR = 268,
     NOT = 269,
     READ = 270,
     WRITE = 271,
     IF = 272,
     WHILE = 273,
     MAIN = 274,
     RETURN = 275,
     INTEGER = 276,
     BOOLEAN = 277,
     __TRUE = 278,
     __FALSE = 279,
     DECL = 280,
     ENDDECL = 281,
     __BEGIN = 282,
     END = 283,
     __EXIT = 284,
     THEN = 285,
     ELSE = 286,
     ENDIF = 287,
     DO = 288,
     ENDWHILE = 289
   };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define PROD 261
#define SUBT 262
#define ASG 263
#define GT 264
#define LT 265
#define EQ 266
#define AND 267
#define OR 268
#define NOT 269
#define READ 270
#define WRITE 271
#define IF 272
#define WHILE 273
#define MAIN 274
#define RETURN 275
#define INTEGER 276
#define BOOLEAN 277
#define __TRUE 278
#define __FALSE 279
#define DECL 280
#define ENDDECL 281
#define __BEGIN 282
#define END 283
#define __EXIT 284
#define THEN 285
#define ELSE 286
#define ENDIF 287
#define DO 288
#define ENDWHILE 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 46 "compiler_debug.y"
 
	struct Tnode *node;
	int ival;
	char *ch;



/* Line 2068 of yacc.c  */
#line 126 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


