/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "compiler_debug.y"

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


/* Line 268 of yacc.c  */
#line 116 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 46 "compiler_debug.y"
 
	struct Tnode *node;
	int ival;
	char *ch;



/* Line 293 of yacc.c  */
#line 228 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 240 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      38,    39,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    13,    14,    19,    24,    26,
      31,    36,    40,    47,    54,    55,    60,    65,    67,    70,
      74,    79,    80,    91,   102,   111,   115,   116,   117,   123,
     124,   130,   132,   136,   140,   145,   146,   149,   154,   162,
     168,   177,   183,   190,   199,   206,   208,   212,   214,   216,
     218,   220,   225,   230,   234,   238,   242,   246,   250,   254,
     258,   262,   266,   270
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    47,    46,    52,    53,    -1,    25,
      48,    26,    -1,    -1,    48,    21,    49,    35,    -1,    48,
      22,    49,    35,    -1,     4,    -1,     4,    36,     3,    37,
      -1,     4,    38,    50,    39,    -1,     4,    40,    49,    -1,
       4,    36,     3,    37,    40,    49,    -1,     4,    38,    50,
      39,    40,    49,    -1,    -1,    50,    21,    51,    35,    -1,
      50,    22,    51,    35,    -1,     4,    -1,    41,     4,    -1,
       4,    40,    51,    -1,    41,     4,    40,    51,    -1,    -1,
      52,    21,     4,    38,    50,    39,    42,    54,    59,    43,
      -1,    52,    22,     4,    38,    50,    39,    42,    54,    59,
      43,    -1,    21,    19,    38,    39,    42,    54,    59,    43,
      -1,    25,    55,    26,    -1,    -1,    -1,    55,    21,    56,
      58,    35,    -1,    -1,    55,    22,    57,    58,    35,    -1,
       4,    -1,    58,    40,     4,    -1,    27,    60,    28,    -1,
      61,    20,    64,    35,    -1,    -1,    61,    62,    -1,     4,
       8,    64,    35,    -1,     4,    36,    64,    37,     8,    64,
      35,    -1,    15,    38,     4,    39,    35,    -1,    15,    38,
       4,    36,    64,    37,    39,    35,    -1,    16,    38,    64,
      39,    35,    -1,    17,    64,    30,    61,    32,    35,    -1,
      17,    64,    30,    61,    31,    61,    32,    35,    -1,    18,
      64,    33,    61,    34,    35,    -1,    64,    -1,    64,    40,
      63,    -1,     3,    -1,    23,    -1,    24,    -1,     4,    -1,
       4,    36,    64,    37,    -1,     4,    38,    63,    39,    -1,
       4,    38,    39,    -1,    38,    64,    39,    -1,    64,     5,
      64,    -1,    64,     7,    64,    -1,    64,     6,    64,    -1,
      64,     9,    64,    -1,    64,    10,    64,    -1,    64,    11,
      64,    -1,    64,    12,    64,    -1,    64,    13,    64,    -1,
      14,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    73,    76,    87,    88,    98,   110,   111,
     112,   113,   114,   115,   118,   119,   127,   137,   138,   139,
     142,   173,   175,   210,   246,   273,   277,   278,   278,   280,
     280,   283,   284,   287,   290,   293,   294,   297,   315,   322,
     340,   347,   348,   349,   350,   366,   370,   375,   377,   379,
     381,   396,   401,   409,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "PROD", "SUBT",
  "ASG", "GT", "LT", "EQ", "AND", "OR", "NOT", "READ", "WRITE", "IF",
  "WHILE", "MAIN", "RETURN", "INTEGER", "BOOLEAN", "__TRUE", "__FALSE",
  "DECL", "ENDDECL", "__BEGIN", "END", "__EXIT", "THEN", "ELSE", "ENDIF",
  "DO", "ENDWHILE", "';'", "'['", "']'", "'('", "')'", "','", "'&'", "'{'",
  "'}'", "$accept", "program", "$@1", "Gdeclaration", "Gdeclist",
  "Gvarlist", "FargDef", "Farglist", "Fdefinition", "MainBlock",
  "ldeclaration", "localdeclList", "$@2", "$@3", "localvarlist", "fbody",
  "body", "slist", "stat", "arglist", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    59,    91,    93,    40,    41,
      44,    38,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    53,    54,    55,    56,    55,    57,
      55,    58,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     3,     0,     4,     4,     1,     4,
       4,     3,     6,     6,     0,     4,     4,     1,     2,     3,
       4,     0,    10,    10,     8,     3,     0,     0,     5,     0,
       5,     1,     3,     3,     4,     0,     2,     4,     7,     5,
       8,     5,     6,     8,     6,     1,     3,     1,     1,     1,
       1,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,    21,     0,     0,     4,
       0,     8,     0,     0,     0,     0,     3,     0,    14,     0,
       6,     7,     0,     0,     0,     0,     0,    11,    14,     0,
      14,     9,     0,     0,    10,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,    12,     0,    18,
      15,    16,    13,     0,    26,     0,     0,    19,     0,     0,
       0,    35,     0,     0,    20,     0,    27,    29,    25,     0,
       0,    24,     0,    22,     0,     0,    33,     0,     0,     0,
       0,     0,     0,    36,    23,    31,     0,     0,     0,     0,
       0,     0,    47,    50,     0,    48,    49,     0,     0,     0,
       0,    28,     0,    30,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    35,    34,    32,    37,     0,     0,     0,     0,     0,
      53,     0,    45,    54,    55,    57,    56,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    39,    41,    51,    52,
       0,    35,     0,     0,     0,     0,    46,     0,    42,    44,
      38,     0,     0,    40,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     3,     4,    12,    26,    41,    10,    16,
      55,    60,    74,    75,    86,    62,    69,    70,    83,   131,
     132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
     -21,   -81,    15,   -81,   130,   -81,   -81,    73,    73,   -81,
      87,    36,    53,    58,     2,    98,   -81,   150,   -81,    73,
     -81,   -81,   119,   127,   138,   140,   116,   -81,   -81,   141,
     -81,   145,    -1,    -1,   157,   142,   173,   162,    73,   159,
     178,   184,   189,    73,   192,   218,   209,   -81,    -1,   215,
     -81,   -81,   -81,   218,   -81,   229,   218,   -81,    -1,   229,
     174,   -81,   214,   229,   -81,   216,   -81,   -81,   -81,   230,
     210,   -81,   217,   -81,   257,   257,   -81,    34,   224,   225,
      44,    44,    44,   -81,   -81,   -81,   -30,   -28,    44,    44,
     260,    44,   -81,    -9,    44,   -81,   -81,    44,   199,   161,
     114,   -81,   261,   -81,   123,    85,   -23,    50,    44,    27,
     211,    74,    44,    44,    44,    44,    44,    44,    44,    44,
     -81,   -81,   -81,   -81,   -81,   258,    44,   232,   233,    94,
     -81,   231,    13,   -81,   263,   -81,   263,   243,   243,   243,
     235,   226,   171,   144,    44,   105,   -81,   -81,   -81,   -81,
      44,   -81,   236,   237,   134,   234,   -81,   175,   -81,   -81,
     -81,   239,   240,   -81,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,    35,    41,   165,   -81,   -81,
      -4,   -81,   -81,   -81,   201,    91,   -81,   -76,   -81,   128,
     -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      98,    99,   100,    39,     1,   101,    22,   103,   104,   105,
     102,   107,   102,   126,   110,     5,   127,   111,   112,   113,
     114,    23,   115,   116,   117,   118,   119,   108,   129,   109,
      92,    93,   134,   135,   136,   137,   138,   139,   140,   141,
      40,    94,    88,    13,   142,   143,   145,    92,    93,    59,
      95,    96,    63,   150,    27,   112,   113,   114,    94,   115,
     116,   117,   118,   119,   154,    97,   130,    95,    96,    35,
      89,    37,    17,    47,    18,   157,    19,    11,    52,   112,
     113,   114,    97,   115,   116,   117,   118,   119,    20,   128,
     112,   113,   114,    21,   115,   116,   117,   118,   119,   112,
     113,   114,    24,   115,   116,   117,   118,   119,    14,    15,
     112,   113,   114,   133,   115,   116,   117,   118,   119,   112,
     113,   114,   125,   115,   116,   117,   118,   119,   112,   113,
     114,   148,   115,   116,   117,   118,   119,    32,    33,   112,
     113,   114,   155,   115,   116,   117,   118,   119,    77,   122,
      65,     7,     8,    25,    72,    34,     9,    28,   124,    78,
      79,    80,    81,    32,    33,    29,   112,   113,   114,   160,
     115,   116,   117,   118,   119,    77,    30,    31,   153,    77,
      36,    44,    49,    32,    33,    38,    78,    79,    80,    81,
      78,    79,    80,    81,   121,    66,    67,    43,    42,    48,
      68,    46,   151,   152,   112,   113,   114,   162,   115,   116,
     117,   118,   119,    57,    77,    45,   112,   113,   114,    50,
     115,   116,   117,    64,    51,    78,    79,    80,    81,   120,
      82,   112,   113,   114,    53,   115,   116,   117,   118,    -1,
     112,   113,   114,    54,   115,   116,   117,    -1,   112,   113,
     114,    56,    -1,    -1,    -1,    58,    61,    71,    76,    73,
      84,    85,    90,    91,   106,   123,   144,   146,   147,   113,
     149,   158,   159,   161,   163,   164,    87,     0,   156
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-81))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      80,    81,    82,     4,    25,    35,     4,    35,    88,    89,
      40,    91,    40,    36,    94,     0,    39,    97,     5,     6,
       7,    19,     9,    10,    11,    12,    13,    36,   108,    38,
       3,     4,   112,   113,   114,   115,   116,   117,   118,   119,
      41,    14,     8,     8,   120,   121,   126,     3,     4,    53,
      23,    24,    56,    40,    19,     5,     6,     7,    14,     9,
      10,    11,    12,    13,   144,    38,    39,    23,    24,    28,
      36,    30,    36,    38,    38,   151,    40,     4,    43,     5,
       6,     7,    38,     9,    10,    11,    12,    13,    35,    39,
       5,     6,     7,    35,     9,    10,    11,    12,    13,     5,
       6,     7,     4,     9,    10,    11,    12,    13,    21,    22,
       5,     6,     7,    39,     9,    10,    11,    12,    13,     5,
       6,     7,    37,     9,    10,    11,    12,    13,     5,     6,
       7,    37,     9,    10,    11,    12,    13,    21,    22,     5,
       6,     7,    37,     9,    10,    11,    12,    13,     4,    35,
      59,    21,    22,     3,    63,    39,    26,    38,    35,    15,
      16,    17,    18,    21,    22,    38,     5,     6,     7,    35,
       9,    10,    11,    12,    13,     4,    38,    37,    34,     4,
      39,    39,     4,    21,    22,    40,    15,    16,    17,    18,
      15,    16,    17,    18,    33,    21,    22,    40,    33,    40,
      26,    39,    31,    32,     5,     6,     7,    32,     9,    10,
      11,    12,    13,    48,     4,    42,     5,     6,     7,    35,
       9,    10,    11,    58,    35,    15,    16,    17,    18,    30,
      20,     5,     6,     7,    42,     9,    10,    11,    12,    13,
       5,     6,     7,    25,     9,    10,    11,    12,     5,     6,
       7,    42,     9,    10,    11,    40,    27,    43,    28,    43,
      43,     4,    38,    38,     4,     4,     8,    35,    35,     6,
      39,    35,    35,    39,    35,    35,    75,    -1,   150
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    45,    47,    48,     0,    46,    21,    22,    26,
      52,     4,    49,    49,    21,    22,    53,    36,    38,    40,
      35,    35,     4,    19,     4,     3,    50,    49,    38,    38,
      38,    37,    21,    22,    39,    50,    39,    50,    40,     4,
      41,    51,    51,    40,    39,    42,    39,    49,    40,     4,
      35,    35,    49,    42,    25,    54,    42,    51,    40,    54,
      55,    27,    59,    54,    51,    59,    21,    22,    26,    60,
      61,    43,    59,    43,    56,    57,    28,     4,    15,    16,
      17,    18,    20,    62,    43,     4,    58,    58,     8,    36,
      38,    38,     3,     4,    14,    23,    24,    38,    64,    64,
      64,    35,    40,    35,    64,    64,     4,    64,    36,    38,
      64,    64,     5,     6,     7,     9,    10,    11,    12,    13,
      30,    33,    35,     4,    35,    37,    36,    39,    39,    64,
      39,    63,    64,    39,    64,    64,    64,    64,    64,    64,
      64,    64,    61,    61,     8,    64,    35,    35,    37,    39,
      40,    31,    32,    34,    64,    37,    63,    61,    35,    35,
      35,    39,    32,    35,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 73 "compiler_debug.y"
    {printf("Declaration Complete");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 76 "compiler_debug.y"
    { 	struct Gsymbol * p = symtable;
						printf("\nSymbol Table: \n");
						if(p ==NULL){printf("Pnull ");}
						while(p != NULL) {
							printf("%s,%d,%d,%d--> ",p->name,p->size,p->binding,p->type);
							printf("Error");
							p = p->next;
							
						}
					}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 88 "compiler_debug.y"
    {	struct VarList * p;
							while(vstart != NULL) {
								Ginstall(vstart->name,INTEGER,vstart->size,vstart->arglist);
								p = vstart;
								vstart = vstart->next;
								free(p);
							}
							vstart = NULL;
							vend = NULL;
						}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 98 "compiler_debug.y"
    {	struct VarList * p;
							while(vstart != NULL) {
								Ginstall(vstart->name,BOOLEAN,vstart->size,vstart->arglist);
								p = vstart;
								vstart = vstart->next;
								free(p);
							}
							vstart = NULL;
							vend = NULL;
						}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 110 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (1)].ch),1,0);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 111 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (4)].ch),(yyvsp[(3) - (4)].ival),0);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 112 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (4)].ch),0,1);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 113 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (3)].ch),1,0);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 114 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (6)].ch),(yyvsp[(3) - (6)].ival),0);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 115 "compiler_debug.y"
    {insertVar((yyvsp[(1) - (6)].ch),0,1);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 119 "compiler_debug.y"
    {
							//create arg list of integer types
							while(fstart != NULL) {
								fstart->type = INTEGER;
								faddArg(fstart);
								fstart = fstart->next;
							}
						}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 127 "compiler_debug.y"
    {
							//create arg list of boolean types
							while(fstart != NULL) {
								fstart->type = BOOLEAN;
								faddArg(fstart);
								fstart = fstart->next;
							}
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 137 "compiler_debug.y"
    {	finsertVar((yyvsp[(1) - (1)].ch),0); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 138 "compiler_debug.y"
    {	finsertVar((yyvsp[(2) - (2)].ch),1); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 139 "compiler_debug.y"
    {	
							finsertVar((yyvsp[(1) - (3)].ch),0);
						}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 142 "compiler_debug.y"
    {
							finsertVar((yyvsp[(2) - (4)].ch),1);
						}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 173 "compiler_debug.y"
    { lsymtable = lsymtableLast = NULL; fargTable = fargTableLast = NULL; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 176 "compiler_debug.y"
    {	
							if(func_typecheck((yyvsp[(3) - (10)].ch),fargTable,INTEGER,(yyvsp[(9) - (10)].node)->ptr2->type)){
								struct Gsymbol * f = Glookup((yyvsp[(3) - (10)].ch));
								//TODO: push the local variables in the stack
								int k = getLocalVarCount() - getArgCount();
								
								int i = 0;
								
								fprintf(outfile, "%s:\n",(yyvsp[(3) - (10)].ch));
								//setting up the base pointer
								fprintf(outfile, "PUSH BP\nMOV BP, SP\n");
								
								//pushing space for local vairables
								if (k>0) {
									fprintf(outfile, "MOV R0, 0\n");
									for(i=0;i<k;i++)
										fprintf(outfile,"PUSH R0\n");
								}
								
								//codegeneration of functione body
								codegen(outfile, (yyvsp[(9) - (10)].node));
								
								//resetting the SP and BP
								fprintf(outfile, "MOV SP, BP\n");
								fprintf(outfile, "POP BP\n");
								
								//return 
								fprintf(outfile,"RET\n");	
							}
							lsymtable = lsymtableLast = NULL;
							fargTable = fargTableLast = NULL;

						}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 211 "compiler_debug.y"
    {
							if(func_typecheck((yyvsp[(3) - (10)].ch),fargTable,BOOLEAN,(yyvsp[(9) - (10)].node)->ptr2->type)){
								struct Gsymbol * f = Glookup((yyvsp[(3) - (10)].ch));
								//TODO: push the local variables in the stack
								int k = getLocalVarCount() - getArgCount();
								
								int i = 0;
								
								fprintf(outfile, "%s:\n",(yyvsp[(3) - (10)].ch));
								//setting up the base pointer
								fprintf(outfile, "PUSH BP\nMOV BP, SP\n");
								
								//pushing space for local vairables
								if (k>0) {
									fprintf(outfile, "MOV R0, 0\n");
									for(i=0;i<k;i++)
										fprintf(outfile,"PUSH R0\n");
								}
								
								//codegeneration of functione body
								codegen(outfile, (yyvsp[(9) - (10)].node));
								
								//resetting the SP and BP
								fprintf(outfile, "MOV SP, BP\n");
								fprintf(outfile, "POP BP\n");
								
								//return 
								fprintf(outfile,"RET\n");	
							}
							lsymtable = lsymtableLast = NULL;
							fargTable = fargTableLast = NULL;
					
						}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 247 "compiler_debug.y"
    { 
							fprintf(outfile,"MAIN :\n");
							printf("I got a main");
							//TODO: push the local variables in the stack
							int k = getLocalVarCount();
							int i = 0;
					
							//pushing space for local vairables
							if(k>0) {
								fprintf(outfile, "MOV R0, 0\n");
								for(i=0;i<k;i++)
									fprintf(outfile,"PUSH R0\n");
							}
							
							//codegeneration of functione body
							codegen(outfile, (yyvsp[(7) - (8)].node));
					
							for(i=0;i<k;i++)
								fprintf(outfile,"POP R0\n");
							
							//EXIT 
							fprintf(outfile,"JMP EXIT\n");
						}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 273 "compiler_debug.y"
    { argsToLocalVars(fargTable); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 277 "compiler_debug.y"
    {lvarType = 0; }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 278 "compiler_debug.y"
    {lvarType = INTEGER;}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 278 "compiler_debug.y"
    {}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 280 "compiler_debug.y"
    {lvarType = BOOLEAN;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 280 "compiler_debug.y"
    {}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 283 "compiler_debug.y"
    { linstall((yyvsp[(1) - (1)].ch), lvarType); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 284 "compiler_debug.y"
    { linstall((yyvsp[(3) - (3)].ch), lvarType); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 287 "compiler_debug.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 290 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,BODY,-1,NULL,NULL,(yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node),NULL);}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 293 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,SLIST,-1,NULL,NULL,NULL,NULL,NULL);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 294 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,SLIST,-1,NULL,NULL,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 297 "compiler_debug.y"
    {	
							struct Lsymbol * l = Llookup((yyvsp[(1) - (4)].ch));
							if( l != NULL) {
								printf("Local Lookup");
								struct Tnode *nid =TreeCreate(l->type,ID,-1,(yyvsp[(1) - (4)].ch),NULL,NULL,NULL,NULL);
								nid->lentry = l;
								nid->gentry = NULL;
								(yyval.node)=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,(yyvsp[(3) - (4)].node),NULL);
							} else {
								printf("global lookup");
								struct Gsymbol * v = Glookup((yyvsp[(1) - (4)].ch));
								struct Tnode *nid=TreeCreate(v->type,ID,-1,(yyvsp[(1) - (4)].ch),NULL,NULL,NULL,NULL);
								nid->gentry = v;
								nid->lentry = NULL;
								(yyval.node)=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,(yyvsp[(3) - (4)].node),NULL);
							}
						}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 315 "compiler_debug.y"
    {
							struct Gsymbol * v = Glookup((yyvsp[(1) - (7)].ch));
							struct Tnode *nid = TreeCreate(INTEGER,ID,-1,(yyvsp[(1) - (7)].ch),NULL,(yyvsp[(3) - (7)].node),NULL,NULL);
							nid->gentry = v;
							(yyval.node)=TreeCreate(VOID,ASG,-1,NULL,NULL,nid,(yyvsp[(6) - (7)].node),NULL);
						}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 322 "compiler_debug.y"
    {	
							struct Lsymbol * l = Llookup((yyvsp[(3) - (5)].ch));
							if( l != NULL) {
								printf("Local Lookup");
								struct Tnode *nid =TreeCreate(l->type,ID,-1,(yyvsp[(3) - (5)].ch),NULL,NULL,NULL,NULL);
								nid->lentry = l;
								nid->gentry = NULL;
								(yyval.node)=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
							} else {
								printf("global lookup");
								struct Gsymbol * v = Glookup((yyvsp[(3) - (5)].ch));
								struct Tnode *nid=TreeCreate(v->type,ID,-1,(yyvsp[(3) - (5)].ch),NULL,NULL,NULL,NULL);
								nid->gentry = v;
								nid->lentry = NULL;
								(yyval.node)=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
							}
						}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 340 "compiler_debug.y"
    {	
							struct Gsymbol * v = Glookup((yyvsp[(3) - (8)].ch));
							struct Tnode *nid = TreeCreate(INTEGER,ID,-1,(yyvsp[(3) - (8)].ch),NULL,(yyvsp[(5) - (8)].node),NULL,NULL);
							nid->gentry = v;
							(yyval.node)=TreeCreate(VOID,READ,-1,NULL,NULL,nid,NULL,NULL);
						}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 347 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,WRITE,-1,NULL,NULL,(yyvsp[(3) - (5)].node),NULL,NULL);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 348 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,IF,-1,NULL,NULL,(yyvsp[(2) - (6)].node),(yyvsp[(4) - (6)].node),NULL);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 349 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,IF,-1,NULL,NULL,(yyvsp[(2) - (8)].node),(yyvsp[(4) - (8)].node),(yyvsp[(6) - (8)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 350 "compiler_debug.y"
    {(yyval.node)=TreeCreate(VOID,WHILE,-1,NULL,NULL,(yyvsp[(2) - (6)].node),(yyvsp[(4) - (6)].node),NULL);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 366 "compiler_debug.y"
    {	(yyvsp[(1) - (1)].node)->sibling = NULL; 
						(yyval.node) = (yyvsp[(1) - (1)].node);
					}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 370 "compiler_debug.y"
    {	(yyvsp[(1) - (3)].node)->sibling = (yyvsp[(3) - (3)].node);
						(yyval.node) = (yyvsp[(1) - (3)].node);
					}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 375 "compiler_debug.y"
    {(yyval.node)=TreeCreate(INTEGER,NUM,(yyvsp[(1) - (1)].ival),NULL,NULL,NULL,NULL,NULL);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 377 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,NUM,1,NULL,NULL,NULL,NULL,NULL);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 379 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,NUM,0,NULL,NULL,NULL,NULL,NULL);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 381 "compiler_debug.y"
    {	
						struct Lsymbol * l = Llookup((yyvsp[(1) - (1)].ch));
						if( l != NULL) {
							printf("Local Lookup");
							(yyval.node)=TreeCreate(l->type,ID,((yyvsp[(1) - (1)].ch)[0]-'a'),(yyvsp[(1) - (1)].ch),NULL,NULL,NULL,NULL);
							(yyval.node)->lentry = l;
							(yyval.node)->gentry = NULL;
						} else {
							printf("global lookup");
							struct Gsymbol * v = Glookup((yyvsp[(1) - (1)].ch));
							(yyval.node)=TreeCreate(v->type,ID,((yyvsp[(1) - (1)].ch)[0]-'a'),(yyvsp[(1) - (1)].ch),NULL,NULL,NULL,NULL);
							(yyval.node)->gentry = v;
							(yyval.node)->lentry = NULL;
						}
					}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 396 "compiler_debug.y"
    {	struct Gsymbol * v = Glookup((yyvsp[(1) - (4)].ch));
						(yyval.node)=TreeCreate(v->type,ID,((yyvsp[(1) - (4)].ch)[0]-'a'),(yyvsp[(1) - (4)].ch),NULL,(yyvsp[(3) - (4)].node),NULL,NULL); 
						(yyval.node)->gentry = v;
					}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 401 "compiler_debug.y"
    {	struct Gsymbol *v = Glookup((yyvsp[(1) - (4)].ch));
						//the ArgList pointer is used to point to arguments
						if(argCompatibleToFunc(v, (yyvsp[(3) - (4)].node))) {
							(yyval.node)=TreeCreate(v->type,FUNCTION,-1,(yyvsp[(1) - (4)].ch),(yyvsp[(3) - (4)].node),NULL,NULL,NULL);
							(yyval.node)->gentry = v;
						}
					}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 409 "compiler_debug.y"
    {	struct Gsymbol *v = Glookup((yyvsp[(1) - (3)].ch));
						(yyval.node)=TreeCreate(v->type,FUNCTION,-1,(yyvsp[(1) - (3)].ch),NULL,NULL,NULL,NULL);
						(yyval.node)->gentry = v;
					}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 414 "compiler_debug.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 415 "compiler_debug.y"
    {(yyval.node)=TreeCreate(INTEGER,PLUS,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 416 "compiler_debug.y"
    {(yyval.node)=TreeCreate(INTEGER,SUBT,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 417 "compiler_debug.y"
    {(yyval.node)=TreeCreate(INTEGER,PROD,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 418 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,GT,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 419 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,LT,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 420 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,EQ,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 421 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,AND,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 422 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,OR,-1,NULL,NULL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 423 "compiler_debug.y"
    {(yyval.node)=TreeCreate(BOOLEAN,NOT,-1,NULL,NULL,(yyvsp[(1) - (2)].node),NULL,NULL);}
    break;



/* Line 1806 of yacc.c  */
#line 2236 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 425 "compiler_debug.y"




