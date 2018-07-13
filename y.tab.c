/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1505010.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<string>
#include<cmath>
#include<fstream>
//#include "symbol.h"
#include "1505010.h"
#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp2, *fp3;
ofstream codeAsm;
extern int line_num;
extern int error;
extern FILE *logout, *tokenout;
//extern SymbolTable *sym;
int flag =0;
int errFlag=0;
SymbolTable *table;
extern char* yytext;

string declared_variables;
string procedure;
//extern YYSTYPE yylval;

void yyerror(const char *s)
{
	printf("myerror: %s\n",s);
	error++;
	return;
	//write your code
}

void printError(string s, int line_num){
	if(errFlag==0){
	fprintf(fp3, "Error at Line %d: %s\n\n", line_num, s.c_str()); 
	errFlag=1;
	error++;
	}
}



int labelCount=0;
int tempCount=0;


string newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return string(lb);
}

string newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return string(t);
}




#line 147 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    INT = 262,
    FLOAT = 263,
    DOUBLE = 264,
    CHAR = 265,
    RETURN = 266,
    VOID = 267,
    PRINTLN = 268,
    ADDOP = 269,
    MULOP = 270,
    ASSIGNOP = 271,
    RELOP = 272,
    LOGICOP = 273,
    NOT = 274,
    SEMICOLON = 275,
    COMMA = 276,
    LPAREN = 277,
    RPAREN = 278,
    LCURL = 279,
    RCURL = 280,
    LTHIRD = 281,
    RTHIRD = 282,
    INCOP = 283,
    DECOP = 284,
    CONST_INT = 285,
    CONST_FLOAT = 286,
    ID = 287,
    MAIN = 288,
    DO = 289,
    SWITCH = 290,
    DEFAULT = 291,
    BREAK = 292,
    CASE = 293,
    CONTINUE = 294,
    CONST_CHAR = 295,
    BITOP = 296,
    LOWER_THAN_ELSE = 297
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define DOUBLE 264
#define CHAR 265
#define RETURN 266
#define VOID 267
#define PRINTLN 268
#define ADDOP 269
#define MULOP 270
#define ASSIGNOP 271
#define RELOP 272
#define LOGICOP 273
#define NOT 274
#define SEMICOLON 275
#define COMMA 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LTHIRD 281
#define RTHIRD 282
#define INCOP 283
#define DECOP 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define ID 287
#define MAIN 288
#define DO 289
#define SWITCH 290
#define DEFAULT 291
#define BREAK 292
#define CASE 293
#define CONTINUE 294
#define CONST_CHAR 295
#define BITOP 296
#define LOWER_THAN_ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   140,   161,   171,   182,   193,   207,   315,
     356,   356,   652,   652,   796,   829,   846,   878,   894,   894,
     929,   929,   952,  1041,  1051,  1061,  1074,  1138,  1192,  1223,
    1223,  1280,  1292,  1313,  1321,  1329,  1337,  1391,  1421,  1457,
    1489,  1527,  1571,  1589,  1613,  1649,  1707,  1720,  1864,  1876,
    1967,  1978,  2061,  2074,  2164,  2175,  2315,  2331,  2357,  2371,
    2420,  2580,  2601,  2610,  2619,  2628,  2670,  2719,  2733,  2740,
    2772
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "INT",
  "FLOAT", "DOUBLE", "CHAR", "RETURN", "VOID", "PRINTLN", "ADDOP", "MULOP",
  "ASSIGNOP", "RELOP", "LOGICOP", "NOT", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "INCOP", "DECOP",
  "CONST_INT", "CONST_FLOAT", "ID", "MAIN", "DO", "SWITCH", "DEFAULT",
  "BREAK", "CASE", "CONTINUE", "CONST_CHAR", "BITOP", "'+'", "'-'", "'*'",
  "'/'", "'|'", "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "$@3", "$@4", "var_declaration", "type_specifier",
  "declaration_list", "$@5", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    43,    45,    42,    47,   124,   297
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -75,   -75,   -75,    18,     9,   -75,   -75,   -75,   -75,
       4,   -75,   -75,    32,    53,    38,    23,   -75,    24,    42,
      58,    36,    50,    56,   -75,    61,     9,    67,   -75,    63,
      62,    66,   -75,    71,   -75,    61,   -75,    82,    94,    68,
     -75,   -75,   -75,    76,    88,    89,    98,    93,    98,    98,
     -75,    98,   -75,   -75,    33,   -75,   -75,   -75,    87,    64,
     -75,   -75,     6,   101,   -75,   104,    43,   108,   -75,   -75,
     -75,    98,    -7,    98,   107,    99,    -2,   -75,   -75,   109,
      98,    98,   110,   -75,   -75,    98,   -75,   -75,   -75,    98,
      98,    98,    98,   112,    -7,   114,   -75,   116,   -75,   -75,
     117,   120,   106,   -75,   -75,   108,   128,   -75,    94,    98,
      94,   123,   -75,    98,   -75,   140,   122,   -75,   -75,   -75,
      94,    94,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,    22,     0,    12,
       0,    17,     0,    26,     9,     0,     0,    10,    16,     0,
       0,    18,    13,    15,     8,     0,    30,     0,     0,     0,
      14,    11,    27,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    62,    63,    44,    64,    35,    33,     0,     0,
      31,    34,    59,     0,    46,    48,    50,    52,    54,    58,
      21,     0,     0,     0,     0,     0,    59,    56,    57,     0,
      68,     0,    28,    19,    32,     0,    65,    66,    43,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    61,    70,
       0,    67,     0,    47,    49,    53,    51,    55,     0,     0,
       0,     0,    60,     0,    45,    37,     0,    39,    40,    69,
       0,     0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   141,   -75,   -75,   -75,   -75,   -75,   -15,
     -75,   -75,    47,    14,   -75,   -75,   -75,   -57,   -63,   -48,
     -43,   -74,    59,    60,    57,   -44,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    35,    25,    20,    56,
      38,    39,    57,    58,    14,    16,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   100,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      76,    76,    84,    74,    77,    78,    99,    48,    79,    94,
      32,   103,    49,    50,    10,    51,     1,     2,    11,    10,
      41,     3,    85,    52,    53,    54,    86,    87,    93,    21,
      95,   109,    76,    55,    86,    87,    13,    76,   102,   119,
      33,    76,    76,    76,    76,     1,     2,     9,   107,    22,
       3,   115,     9,   117,    15,    80,    23,    90,   -29,    81,
      91,    19,    24,   122,   123,    76,   116,    43,    28,    44,
      45,     1,     2,    17,    18,    46,     3,    47,    48,    26,
      29,    27,    30,    49,    50,    31,    51,    34,    31,    83,
      36,   -20,    37,    70,    52,    53,    54,    43,    71,    44,
      45,     1,     2,    40,    55,    46,     3,    47,    48,    42,
      72,    73,    48,    49,    50,    75,    51,    49,    31,    82,
      51,    88,    89,    92,    52,    53,    54,    96,    52,    53,
      54,    97,    98,   114,    55,   108,   -29,   110,    55,   111,
     112,   113,    90,   118,   120,   121,    12,   105,   104,     0,
       0,   106
};

static const yytype_int8 yycheck[] =
{
      48,    49,    59,    46,    48,    49,    80,    14,    51,    72,
      25,    85,    19,    20,     0,    22,     7,     8,     0,     5,
      35,    12,    16,    30,    31,    32,    28,    29,    71,    15,
      73,    94,    80,    40,    28,    29,    32,    85,    81,   113,
      26,    89,    90,    91,    92,     7,     8,     0,    92,    26,
      12,   108,     5,   110,    22,    22,    32,    14,    26,    26,
      17,    23,    20,   120,   121,   113,   109,     3,    32,     5,
       6,     7,     8,    20,    21,    11,    12,    13,    14,    21,
      30,    23,    26,    19,    20,    24,    22,    20,    24,    25,
      27,    25,    30,    25,    30,    31,    32,     3,    22,     5,
       6,     7,     8,    32,    40,    11,    12,    13,    14,    27,
      22,    22,    14,    19,    20,    22,    22,    19,    24,    32,
      22,    20,    18,    15,    30,    31,    32,    20,    30,    31,
      32,    32,    23,    27,    40,    23,    26,    23,    40,    23,
      23,    21,    14,    20,     4,    23,     5,    90,    89,    -1,
      -1,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    12,    49,    50,    51,    52,    53,    60,
      61,     0,    51,    32,    62,    22,    63,    20,    21,    23,
      56,    61,    26,    32,    20,    55,    21,    23,    32,    30,
      26,    24,    57,    61,    20,    54,    27,    30,    58,    59,
      32,    57,    27,     3,     5,     6,    11,    13,    14,    19,
      20,    22,    30,    31,    32,    40,    57,    60,    61,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      25,    22,    22,    22,    68,    22,    67,    73,    73,    68,
      22,    26,    32,    25,    65,    16,    28,    29,    20,    18,
      14,    17,    15,    68,    66,    68,    20,    32,    23,    69,
      75,    76,    68,    69,    70,    72,    71,    73,    23,    66,
      23,    23,    23,    21,    27,    65,    68,    65,    20,    69,
       4,    23,    65,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      54,    53,    55,    53,    56,    56,    56,    56,    58,    57,
      59,    57,    60,    61,    61,    61,    62,    62,    62,    63,
      62,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     0,
       5,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     3,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     1,
       4,     3,     1,     1,     1,     2,     2,     1,     0,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 102 "1505010.y" /* yacc.c:1646  */
    {
		(yyval)->setType("start");
		fprintf(fp2,"\tSymbol Table: \n\n");		
		table->printAllScope(fp2); 
		fprintf(fp2,"Total Lines: %d\n\n", line_num);
		fprintf(fp2,"Total Errors: %d\n\n", error);		
		if(error>0) {
			fprintf(fp3, "Total Errors: %d\n\n", error);
		}	
		
		//ofstream codeOut;
		//codeAsm.open("code.asm");
		string top = ".MODEL SMALL \n.STACK 100H \n.DATA\n";
		string var;
		codeAsm << top << endl;
		//temporary variables..
		for(int i=0; i< tempCount; i++)
		{
			var = "t" + to_string(i) + "\tDW\t ?\n";
			codeAsm << var;
		}
		codeAsm << endl;
		//declared variables..
		codeAsm << declared_variables << endl;
		
		codeAsm << ".CODE \nMAIN PROC \n";
		codeAsm << "\tmov ax, @DATA\n\tmov ds, ax\n\n";
		codeAsm << (yyval)->code;
		codeAsm << "\nMAIN ENDP\n";
		//codeAsm << "include input.asm \t; INDEC \n";
		codeAsm << "include decimal_output.asm \t; OUTDEC\n";
		codeAsm << procedure;
		codeAsm << "END MAIN\n";
		
		
	}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d program : program unit\n\n", line_num);
			fprintf(fp2, "At line no: %d program : program unit\n\n", line_num);
	
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("program");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//$$->code = $1->code + $2->code;
			
			(yyval)->code = (yyvsp[0])->code;
			
			//codeAsm.open("code.asm");
			//codeAsm << $$->code;
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
		
			}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 161 "1505010.y" /* yacc.c:1646  */
    {
		//printf("At line no: %d program : unit\n\n", line_num);
		fprintf(fp2, "At line no: %d program : unit\n\n", line_num);
	
		//printf("%s\n\n", $1->getName().c_str());
		//$$->setType("program");
		fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
		}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 171 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unit : var_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : var_declaration\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 182 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unit : func_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : func_declaration\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			//$$ = $1;
			
			}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 193 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unit : func_definition\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : func_definition\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			//$$ = $1;
			//fprintf(fp2, "%s\n\n", $$->code.c_str());
			
			}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 207 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n", line_num);
	
			//printf("%s %s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str());	
			
			string b = (yyvsp[-4])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, (yyvsp[-4])->getType().c_str(), fp2);
				 s = table->lookUp(b);
				 s->type = (yyvsp[-5])->getType().c_str();
				 s->type = (yyvsp[-5])->type.c_str();
				 
				 //s->functionParameters = $4->getName().c_str();
			}
			else{
				string err = "Multiple Declaration of ";
				err.append(b);
				printError(err, line_num);
			}
			
			vector <string> tokens;
			stringstream check1((yyvsp[-2])->getName().c_str());
			string intermediate;
			string intermediate2;
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, ',')){
					tokens.push_back(intermediate2);
					//s->functionParameters.push_back(intermediate2);
				}
				else {
				tokens.push_back(intermediate);
				//s->functionParameters.push_back(intermediate);
				
				}
			}
			
			for(int i=0; i<tokens.size(); i++) {
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float"))
			{	
				SymbolInfo *s2 = table->lookUp(tokens[i]);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					//table->insert(b, "ID",  fp2);
					//s2 = table->lookUp(b);
					size_t foundArray = tokens[i].find('[');
					if(!tokens[i-1].compare("int")){
						if(foundArray!=string::npos)
						{
							//s2->type = "INT_ARRAY";
							s->functionParameters.push_back("INT_ARRAY");
							//fprintf(fp3, "added to function parameters INT_ARRAY\n");
							
						}
						else {
							//s2->type = "INT";
							s->functionParameters.push_back("INT");
							//fprintf(fp3, "added to function parameters INT\n");
						
						}
					}
					else if(!tokens[i-1].compare("double"))
					{	
						//s2->type = "DOUBLE";
						s->functionParameters.push_back("DOUBLE");
						//fprintf(fp3, "added to function parameters DBL\n");
					}
					else if(!tokens[i-1].compare("FLOAT"))
					{
						//s2->type = "FLOAT";
						s->functionParameters.push_back("FLOAT");
						//fprintf(fp3, "added to function parameters FLT\n");
						
					}
					//s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
			}
			}
	
			string allConcat ;
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("func_declaration");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			
			errFlag=0;
			}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 315 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON \n\n", line_num);
	
			//printf("%s %s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());	
	
			string b = (yyvsp[-3])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, (yyvsp[-3])->getType().c_str(), fp2);
				 s = table->lookUp(b);
				// s->type = $1->getType().c_str();
				 s->type = (yyvsp[-4])->type.c_str();
				 
				 //s->functionParameters = " ";
			}
			else{
				string err = "Multiple Declaration of ";
				err.append(b);
				printError(err, line_num);
			}
			
			string allConcat ;
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("func_declaration");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			errFlag=0;
			}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 356 "1505010.y" /* yacc.c:1646  */
    {
		
		
		/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1")) 
		table->insert($2->getName().c_str(), $2->getType().c_str(), fp2); 
		*/
		int declared=0;
		string b = (yyvsp[-3])->getName().c_str();
		b.append(" ");
		SymbolInfo *s = table->lookUp(b);
		
		procedure += (yyvsp[-3])->getName() +" PROC\n";
		procedure+="\tpop bx \t\t;RETRIEVE RETURN ADDRESS FROM THE CALL.\n";
							
		
		if(!s->getName().compare("-1"))
		{				
			 table->insert(b, (yyvsp[-3])->getType().c_str(), fp2);
			 s = table->lookUp(b);
			 s->type = (yyvsp[-4])->getType().c_str();
			 s->defined = true;
			 //s->functionParameters = $4->getName().c_str();
		}
		else
		{
			s->defined = true;
			declared=1;
			//if($1->getType().compare(s->type)) //declaration type and definition type not same..
			if((yyvsp[-4])->type.compare(s->type)) //declaration type and definition type not same..
			
			{
				string er = "Return Type Mismatch With Declaration Conflicting Type For: ";
				er.append(s->getName().c_str());
				//er.append("'");
				
				printError(er, line_num);
			}
		}
		
			
		//function age theke declare kora thakle new kore kichu add krbe na scope table e..
		
		table->enterScope(fp2);
		flag=1;
		SymbolInfo *para = (yyvsp[-1]);
		string pList = para->getName().c_str();
		//fprintf(fp2, "parameterList: %s , %s\n\n", pList.c_str(), s->getType().c_str());
		//int spaces = count(pList.begin(), pList.end(), ' ' );
		
		vector <string> tokens;
		stringstream check1(pList);
		string intermediate;
		string intermediate2;
		
		while(getline(check1, intermediate, ' ')){
			stringstream check2(intermediate);
			string intermediate2;
			if(getline(check2, intermediate2, ',')){
				tokens.push_back(intermediate2);
				while(getline(check2, intermediate2, ',')){
					tokens.push_back(intermediate2);
				}
			
				//s->functionParameters.push_back(intermediate2);
			}
			else {
			tokens.push_back(intermediate);
			//s->functionParameters.push_back(intermediate);
			
			}
		}
		int j=0;
		
		for(int i=0; i<tokens.size(); i++) {
			
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float"))
			{	
				string var = tokens[i];
				var.append(" ");
				//SymbolInfo *s2 = table->lookUp(tokens[i]);
				//look up on current scope
				SymbolInfo *s2 = table->lookUpCur(var);
				
				
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					size_t foundArray = tokens[i].find('[');
					if(!tokens[i-1].compare("int"))
					{
						if(foundArray!=string::npos)
						{
							s2->type = "INT_ARRAY";
							//s->functionParameters.push_back("INT_ARRAY");
							if(declared==0) s->functionParameters.push_back("INT_ARRAY");
							//fprintf(fp3, "added to function parameters INT_ARRAY\n");
							declared_variables += tokens[i] + to_string(s2->scope) +"\tDW \t ?\n";
							
						}
						else {
							s2->type = "INT";
							//s->functionParameters.push_back("INT");
							if(declared==0) s->functionParameters.push_back("INT");
							declared_variables += tokens[i] + to_string(s2->scope) +"\tDW \t ?\n";
							//fprintf(fp3, "added to function parameters INT\n");	
							procedure+="\tpop ax\t\t;get value from stack\n";
							procedure+="\tmov "+ tokens[i] + to_string(s2->scope) + " , ax\t;get that value back into the variable..\n";				
						}
					}
					else if(!tokens[i-1].compare("double"))
					{	
						s2->type = "DOUBLE";
						//s->functionParameters.push_back("DOUBLE");
						if(declared==0) s->functionParameters.push_back("DOUBLE");
							
						//fprintf(fp3, "added to function parameters DBL\n");
					}
					else if(!tokens[i-1].compare("FLOAT"))
					{
						s2->type = "FLOAT";
						//s->functionParameters.push_back("FLOAT");
						if(declared==0) s->functionParameters.push_back("FLOAT");
							
						//fprintf(fp3, "added to function parameters FLT\n");
					}
					//s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
				else
				{
					string err = "Multiple Declaration of ";
					err.append(var);
					printError(err,line_num);
					break;
				}
				//compare for type match.
				if(s2->type.compare(s->functionParameters[j])){
					string err = "Type Mismath";
					printError(err, line_num);
				}
				j++;
				//fprintf(fp2, "token: %s  type: %s\n", s2->getName().c_str(), s2->type.c_str());
			}
			
			
			
			/*
			
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float") && tokens[i].compare(","))
			{	
				SymbolInfo *s2 = table->lookUp(tokens[i]);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
			}*/
		
		}
		
		procedure+="\tpush bx \t\t;PUT RETURN ADDRESS BACK.\n";
		
		
		}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 532 "1505010.y" /* yacc.c:1646  */
    {
			
			
			//procedure += $2->getName() +" PROC\n";
			procedure+=(yyvsp[0])->code;
			//procedure+="ret\n";
			procedure+= (yyvsp[-5])->getName()+" ENDP\n";
			
			
			
			
			string checkForReturn = (yyvsp[0])->getName().c_str();
			size_t returncheck = checkForReturn.find("return");
			//if(returncheck!=string::npos && !$1->getName().compare("VOID"))
			vector<string> compoundTokens;
			stringstream check1(checkForReturn);
			string intermediate;
			//string intermediate2;
			//fprintf(fp3, "%s \n",checkForReturn.c_str());
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '\n'))
				{
					compoundTokens.push_back(intermediate2);
					while(getline(check2, intermediate2, '\n')){
						compoundTokens.push_back(intermediate2);
					}
				}
				else {
					compoundTokens.push_back(intermediate);
				}
			}
			
			///checking return variable type
			for(int i=0; i<compoundTokens.size(); i++){
				//fprintf(fp3, "token: %s \n",compoundTokens[i].c_str());
				if(!compoundTokens[i].compare("return")){
					//fprintf(fp3, "found return %s :%s",compoundTokens[i].c_str(), compoundTokens[i+1].c_str());
					//if(i+2==compoundTokens.size() && $1->getType().compare("VOID")) //return void or nothing but return type different;
					if(i+2==compoundTokens.size() && (yyvsp[-6])->type.compare("VOID")) //return void or nothing but return type different;
					{
						string err = "warning: ‘return’ with no value, in function returning non-void";
						printError(err, line_num);
					}
					else{
					i++;
					string returnVar = compoundTokens[i].c_str();
					returnVar.erase(returnVar.end()-1);
					//fprintf(fp2, "returnVar: s'%s'sp\n", returnVar.c_str());
					returnVar.append(" ");
					//fprintf(fp2, "lookup: s'%s'sp\n", returnVar.c_str());
					SymbolInfo *variable = table->lookUp(returnVar);
					/*if(!variable->getName().compare("-1")) // variable not found which means not declared
					{
						string err = "Undeclared Variable: ";
						err.append(returnVar);
						printError(err, line_num);
					}
					else
					{*/
						//if(variable->type.compare($1->getType()))
						//fprintf(fp3, "type: %s (%s)\n", returnVar.c_str() ,$7->getType().c_str());
						if((yyvsp[0])->type.compare((yyvsp[-6])->type))
						
						{
							string err = "Return Type Mismatch ";
							//err.append(variable->type.c_str());
							//err.append(" ");
							//err.append($1->getType());
							printError(err, line_num-1);
						}
					//}
 					
					}
				}
			}
			
			//scope part added..
			table->printAllScope(fp2);
			//if(flag==1) 
			table->exitScope(fp2);
			//..
			
			//printf("At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_num);
			fprintf(fp2, "At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_num);
	
			//printf("%s %s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $7->getName().c_str());	
			
			
			
			string allConcat ;
			allConcat.append((yyvsp[-6])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("func_definition");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			
			//fprintf(fp2,"from parameter list: %s\n\n",$4->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				
					 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			errFlag=0;
			
			(yyval)->code = (yyvsp[0])->code;
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 652 "1505010.y" /* yacc.c:1646  */
    { 
			
			
			string b = (yyvsp[-2])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, (yyvsp[-2])->getType().c_str(), fp2);
				 s = table->lookUp(b);
				 s->type = (yyvsp[-3])->getType().c_str();
				 s->defined = true;
				 //s->functionParameters = " ";
			}
			else{
				s->defined = true;
				//if(s->type.compare($1->getType()))
				if(s->type.compare((yyvsp[-3])->type))
				{
					string er = "Return Type Mismatch With Declaration";
					printError(er, line_num);
				}
			}
		
			/*
			if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1")) 
			table->insert($2->getName().c_str(), $2->getType().c_str(), fp2); 
			*/
			flag=1;
			table->enterScope(fp2);
			
			}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 684 "1505010.y" /* yacc.c:1646  */
    {
			
			
			
			
			string checkForReturn = (yyvsp[0])->getName().c_str();
			size_t returncheck = checkForReturn.find("return");
			//if(returncheck!=string::npos && !$1->getName().compare("VOID"))
			vector<string> compoundTokens;
			stringstream check1(checkForReturn);
			string intermediate;
			//string intermediate2;
			//fprintf(fp3, "%s \n",checkForReturn.c_str());
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '\n'))
				{
					compoundTokens.push_back(intermediate2);
					while(getline(check2, intermediate2, '\n')){
						compoundTokens.push_back(intermediate2);
					}
				}
				else {
					compoundTokens.push_back(intermediate);
				}
			}
			
			///checking return variable type
			for(int i=0; i<compoundTokens.size(); i++){
				//fprintf(fp3, "token: %s \n",compoundTokens[i].c_str());
				if(!compoundTokens[i].compare("return")){
					//fprintf(fp3, "found return %s :%s",compoundTokens[i].c_str(), compoundTokens[i+1].c_str());
					//if(i+2==compoundTokens.size() && $1->getType().compare("VOID")) //return void or nothing but return type different;
					if(i+2==compoundTokens.size() && (yyvsp[-5])->type.compare("VOID")) //return void or nothing but return type different;
					{
						string err = "warning: ‘return’ with no value, in function returning non-void";
						printError(err, line_num);
					}
					else{
					i++;
					string returnVar = compoundTokens[i].c_str();
					returnVar.erase(returnVar.end()-1);
					//fprintf(fp2, "returnVar: s'%s'sp\n", returnVar.c_str());
					returnVar.append(" ");
					//fprintf(fp2, "lookup: s'%s'sp\n", returnVar.c_str());
					SymbolInfo *variable = table->lookUp(returnVar);
					/*if(!variable->getName().compare("-1")) // variable not found which means not declared
					{
						string err = "Undeclared Variable: ";
						err.append(returnVar);
						printError(err, line_num);
					}
					else
					{*/
						//if(variable->type.compare($1->getType()))
						//fprintf(fp3, "type: %s (%s)\n", returnVar.c_str() ,$7->getType().c_str());
						if((yyvsp[0])->type.compare((yyvsp[-5])->type))
						
						{
							string err = "Return Type Mismatch ";
							//err.append(variable->type.c_str());
							//err.append(" ");
							//err.append($1->getType());
							printError(err, line_num-1);
						}
					//}
 					
					}
				}
			}
			
			
			//scope added..
			table->printAllScope(fp2);
			//if(flag==1) 
			table->exitScope(fp2);
			//...
			//printf("At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_num);
			fprintf(fp2, "At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_num);
	
			//printf("%s %s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $6->getName().c_str());	
			
			string allConcat ;
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("func_definition");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				
				 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			errFlag=0;
			
			(yyval)->code = (yyvsp[0])->code;
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 796 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d parameter_list : parameter_list COMMA type_specifier ID \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : parameter_list COMMA type_specifier ID \n\n", line_num);
			
			//printf("%s%s%s %s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());	
			
			string allConcat ;
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("parameter_list");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			/*if(!(table->lookUp($4->getName().c_str()))->getName().compare("-1"))
			{				

				 table->insert($4->getName().c_str(), $4->getType().c_str(), fp2);
			}*/
			
			
			//new command
			/*string concat;
			concat.append($1->getName().c_str());
			concat.append(" ");
			concat.append($4->getName().c_str());
			$$->setName(concat);
			fprintf(fp2,"paralist: %s\n\n",$$->getName().c_str());
			$$->setType("parameter_list");
			*/
			}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 829 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d parameter_list : parameter_list COMMA type_specifier \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : parameter_list COMMA type_specifier \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());	
			
			string allConcat ;
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("parameter_list");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			(yyval)->setType((yyvsp[-2])->getType());
			(yyval)->type = (yyvsp[-2])->type;
			
			}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 846 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d parameter_list : type_specifier ID \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : type_specifier ID \n\n", line_num);
			
			//printf("%s %s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("parameter_list");
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				

				 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			//new command
			/*$$->setName($2->getName().c_str());
			$$->setType("parameter_list");
			
			fprintf(fp2,"paraList: %s\n\n",$$->getName().c_str());
			*/
			(yyval)->setType((yyvsp[-1])->getType());
			(yyval)->type = (yyvsp[-1])->type;
			
			}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 878 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d parameter_list : type_specifier\n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : type_specifier\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("parameter_list");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 894 "1505010.y" /* yacc.c:1646  */
    { //fprintf(fp2,"found LCURL\n"); /*if(flag==0) {table->enterScope(fp2);}*/ 
			}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 896 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d compound_statement : LCURL statements RCURL \n\n", line_num);
			fprintf(fp2, "At line no: %d compound_statement : LCURL statements RCURL \n\n", line_num);
			
			//printf("%s\n%s%s\n\n", $1->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());	
			
			(yyval)=(yyvsp[-1]);
			
			string allConcat ;
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append("\n");
			//allConcat.append($2->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			//allConcat.append("\n");
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("compound_statement");
			
			(yyval)->setType((yyvsp[-1])->getType());
			(yyval)->type = (yyvsp[-1])->type;
			
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());			
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			//table->printAllScope(fp2); 
			//table->exitScope(fp2);
			flag=0;
			//table->printAllScope(fp2);
			//table->exitScope(fp2);
			
			(yyval)->code = (yyvsp[-1])->code;
			
			}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 929 "1505010.y" /* yacc.c:1646  */
    { //fprintf(fp2,"found LCURL\n"); /*if(flag==0) {table->enterScope(fp2);}*/
 		    }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 930 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d compound_statement : LCURL RCURL \n\n", line_num);
			fprintf(fp2, "At line no: %d compound_statement : LCURL RCURL \n\n", line_num);
			
			//printf("%s %s\n\n", $1->getName().c_str(), $3->getName().c_str());	
			
			string allConcat ;
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append("\n");
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("compound_statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//{table->printAllScope(fp2); table->exitScope(fp2);}
			//table->printAllScope(fp2);
			//table->exitScope(fp2);
			flag=0;
			
			}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 952 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n", line_num);
			
			//printf("%s %s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());	
			
			
			vector <string> tokens;
			stringstream check1((yyvsp[-1])->getName().c_str());
			string intermediate;
			string intermediate2;
		
			while(getline(check1, intermediate, ',')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '[')){
					stringstream check3(intermediate2);
					string intermediate3;
					if(getline(check3, intermediate3, ']')){
						tokens.push_back(intermediate3);
					}
					else { tokens.push_back(intermediate2); }
				}
				else tokens.push_back(intermediate);
			}
		
			for(int i=0; i<tokens.size(); i++) {	
				string b = tokens[i];
				b.append(" ");
				//printf("Tokens: %s\n", b.c_str());
				SymbolInfo *s2 = table->lookUp(b);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					if(s2->type.compare("INT_ARRAY"))
						s2->type = (yyvsp[-2])->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
				}
				else
				{
					s2 = table->lookUp(b);
					if(s2->type.compare("INT_ARRAY"))
						s2->type = (yyvsp[-2])->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
				}
				
		
			}
			
			///check every token type
			for(int i=0; i<tokens.size(); i++) {	
				string b = tokens[i];
				b.append(" ");
				
				SymbolInfo *s2 = table->lookUp(b);
				
				//declared_variables += tokens[i] + to_string(s2->scope) + "\tDW\t ?\n";
				//fprintf(fp2, "T: %s (%s) \n", s2->getName().c_str(), s2->type.c_str());
		
			}
			
			
			
			
			string allConcat ;
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("var_declaration");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			(yyval)->setType((yyvsp[-2])->getType());
			(yyval)->type = (yyvsp[-2])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			
			errFlag=0;
			
			}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 1041 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d type_specifier : INT\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : INT\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("type_specifier");
			(yyval)->setType("INT");
			(yyval)->type = "INT";
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 1051 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d type_specifier : FLOAT\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : FLOAT\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("FLOAT");
			(yyval)->type = "FLOAT";
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 1061 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d type_specifier : VOID\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : VOID\n\n", line_num);

			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("VOID");
			(yyval)->type = "VOID";
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
	
			}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1074 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d declaration_list : declaration_list COMMA ID \n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : declaration_list COMMA ID \n\n", line_num);
		
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			string allConcat ;
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("declaration_list");
			
			
			
			
			///fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			
			
			
			/*SymbolInfo *s = table->lookUp($3->getName().c_str());
			if(!s->getName().compare("-1") )
			{
				s = new SymbolInfo($3->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			/*else {
				error++;
				fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}*/
			
			
			string b = (yyvsp[0])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				declared_variables += (yyvsp[0])->getName() + to_string(s->scope) + "\tDW\t ?\n";
				
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append((yyvsp[0])->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			(yyval)->setType((yyvsp[-2])->getType());
			(yyval)->type = (yyvsp[-2])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 1138 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n", line_num);
			
			//printf("%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("declaration_list");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			/*SymbolInfo *s = table->lookUp($3->getName().c_str());
			if(!s->getName().compare("-1") )
			{
				s = new SymbolInfo($3->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			*/
			
			string b = (yyvsp[-3])->getName().c_str();
			b.append(" ");
			//SymbolInfo *s = table->lookUp(b);
			
			SymbolInfo *s = table->lookUpCur(b);
			
			
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($3->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				s->type = "INT_ARRAY";
				declared_variables += (yyvsp[-3])->getName() + to_string(s->scope) + "\tDW\t " + (yyvsp[-1])->getName()+ " DUP ('?')\n";
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append((yyvsp[-3])->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1192 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d declaration_list : ID\n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : ID\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("ID");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			string b = (yyvsp[0])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				declared_variables += (yyvsp[0])->getName() + to_string(s->scope) + "\tDW\t ?\n";
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append((yyvsp[0])->getName().c_str());
				printError(err, line_num);
				
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $1->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			
			}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1223 "1505010.y" /* yacc.c:1646  */
    { /*SymbolInfo *s = table->lookUp($1->getName().c_str());
			if(!s->getName().compare("-1") )
			{	
				string tmp = $1->getName().c_str();
				s = new SymbolInfo($1->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			*/
			
			string b = (yyvsp[0])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUpCur(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				s->type = "INT_ARRAY";
			}
			else {
				//yyerror(
				
				string err = "Multiple Declaration of ";
				err.append((yyvsp[0])->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $1->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1256 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", line_num);
		
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			
			string b = (yyvsp[-4])->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUpCur(b);
			declared_variables += (yyvsp[-4])->getName() + to_string(s->scope) + "\tDW\t " + (yyvsp[-1])->getName()+ " DUP ('?')\n";
			
			string allConcat ;
			
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("declaration_list");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1280 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statements : statement\n\n", line_num);
			fprintf(fp2, "At line no: %d statements : statement\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statements");
			
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			fprintf(fp2, "%s\n\n", (yyvsp[0])->getName().c_str());
			
			}
#line 2773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1292 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statements : statements statement\n\n", line_num);
			fprintf(fp2, "At line no: %d statements : statements statement\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			
			(yyval)->setName(allConcat);
			//$$->setType("statements");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			(yyval)->code += (yyvsp[0])->code;
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1313 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : var_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d statement : var_declaration\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1321 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : expression_statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : expression_statement \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1329 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : compound_statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : compound_statement \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1337 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str(), $7->getName().c_str());
			
			
			/*
				$3's code at first, which is already done by assigning $$=$3
				create two labels and append one of them in $$->code
				compare $4's symbol with 0
				if equal jump to 2nd label
				append $7's code
				append $5's code
				append the second label in the code
			*/
			
			//perform later...
			
			
			(yyval)=(yyvsp[-4]);
			string label1 = newLabel(); //FOR
			string label2 = newLabel(); //END FOR
			
			(yyval)->code+=label1+":\t\t;FOR\n";
			(yyval)->code+=(yyvsp[-3])->code;
			(yyval)->code+="\tcmp "+(yyvsp[-3])->getName()+", 0 \t\n";
			(yyval)->code+="\tje "+label2+"\t;END FOR\n";
			(yyval)->code+=(yyvsp[0])->code +"\t\n" ;
			(yyval)->code+=(yyvsp[-2])->code+"\t\n";
			(yyval)->code+= "\tjmp "+label1+"\t;FOR\n";
			(yyval)->code+= label2+":\t;END FOR\n";
			
			
			
			
			string allConcat ;
	
			allConcat.append((yyvsp[-6])->getName().c_str());
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append("; ");
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append("; ");
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			fprintf(fp2,"%s\n\n",(yyval)->code.c_str());
			
			}
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1391 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			
			(yyval)=(yyvsp[-2]);
			
			string label=newLabel();
			(yyval)->code+="\tmov ax, "+(yyvsp[-2])->getName()+"\n";
			(yyval)->code+="\tcmp ax, 0\n";
			(yyval)->code+="\tje "+label+"\t;ENDIF\n";
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+=label+":\t\t;ENDIF\n";
			
			//codeAsm << $$->code.c_str() << endl;
			string allConcat ;
			
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1421 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement  \n\n", line_num);
			
			//printf("%s%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str(), $7->getName().c_str());
			
			(yyval)=(yyvsp[-4]);
			
			string label1=newLabel(); 	//ELSE
			string label2=newLabel();	//ENDIF
			(yyval)->code+="\tmov ax, "+(yyvsp[-4])->getName()+"\n";
			(yyval)->code+="\tcmp ax, 0\n";
			(yyval)->code+="\tje "+label1+"\t;ELSE\n";
			(yyval)->code+=(yyvsp[-2])->code;
			(yyval)->code+="\tjmp "+label2 + "\t;ENDIF\n";
			(yyval)->code+=label1+":\t\t;ELSE\n";
			(yyval)->code+= (yyvsp[0])->code;
			(yyval)->code+= label2+":\t\t;ENDIF\n";
			
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-6])->getName().c_str());
			allConcat.append((yyvsp[-5])->getName().c_str());
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			}
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1457 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : WHILE LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : WHILE LPAREN expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			
			(yyval)=(yyvsp[-2]);
			string label1 = newLabel(); //WHILE
			string label2 = newLabel();
			
			(yyval)->code+=label1+":\t\t;WHILE\n";
			(yyval)->code+="\tcmp "+(yyvsp[-2])->getName()+", 0 \t\n";
			(yyval)->code+="\tje "+label2+"\t;END WHILE\n";
			(yyval)->code+=(yyvsp[0])->code +"\t\n" ;
			(yyval)->code+=(yyvsp[-2])->code+"\t\n";
			(yyval)->code+= "\tjmp "+label1+"\t;WHILE\n";
			(yyval)->code+= label2+":\t;END WHILE\n";
			
			
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1489 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			
			string label = newLabel(); //PRINT:
			//string tmp = "\tMOV AH,2\n\tMOV DL,0Dh\n\tINT 21H\n\tMOV DL,0Ah\n\tINT 21H\n" + label + ": \t\t;PRINT\n\tpop ax\n\tmov ax, ";
			string tmp = "\tMOV AH,2\n\tMOV DL,0Dh\n\tINT 21H\n\tMOV DL,0Ah\n\tINT 21H\n" + label + ": \t\t;PRINT\n\tmov ax, ";
			
			SymbolInfo *s = table->lookUp((yyvsp[-2])->getName()+" ");
			if(s->getName()=="-1"){
				
			}
			else{
				tmp +=(yyvsp[-2])->getName()+to_string(s->scope)+"\n";
				tmp += "\n\tCALL OUTDEC\n";
			
				//tmp+=  "\tMOV AH, 2\n\tMOV DL, ' '\n\tINT 21H\n\tLOOP " + label + "\n";
				tmp+=  "\tMOV AH,2\n\tMOV DL,0Dh\n\tINT 21H\n\tMOV DL,0Ah\n\tINT 21H\n";
			
				(yyval)->code += tmp;
			}
			string allConcat ;
			
			allConcat.append((yyvsp[-4])->getName().c_str());
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			errFlag=0;
			
			}
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1527 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d statement : RETURN expression SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : RETURN expression SEMICOLON \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			/*pop  bx  ;RETRIEVE RETURN ADDRESS FROM THE CALL.
  			push ax  ;VALUE TO RETURN ('0' OR '1').
			push bx  ;PUT RETURN ADDRESS BACK.*/
			
			/*procedure+="\tpop bx\t\t; ;RETRIEVE RETURN ADDRESS FROM THE CALL.\n";
			procedure+="\tpush "+$2->getName()+"\t\t;VALUE TO RETURN \n";
			procedure+="\tpush bx\t\t;PUT RETURN ADDRESS BACK.\n";
			procedure+="\tret\n";
			*/
			
			(yyval)->code+="\tpop bx\t\t;RETRIEVE RETURN ADDRESS FROM THE CALL.\n";
			(yyval)->code+="\tpush "+(yyvsp[-1])->getName()+"\t\t;VALUE TO RETURN \n";
			(yyval)->code+="\tpush bx\t\t;PUT RETURN ADDRESS BACK.\n";
			(yyval)->code+="\tret\n";
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append(" ");
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			allConcat.append("\n");
			(yyval)->setName(allConcat);
			//$$->setType("statement");
			
			(yyval)->setType((yyvsp[-1])->getType());
			(yyval)->type = (yyvsp[-1])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			
			//errFlag=0;
			
			}
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1571 "1505010.y" /* yacc.c:1646  */
    {
			
			//printf("At line no: %d expression_statement : SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d expression_statement : SEMICOLON\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[0])->getName().c_str());
			//allConcat.append("\n");
			
			(yyval)->setName(allConcat);
			//$$->setType("expression_statement");
			
			errFlag=0;
			
			}
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1589 "1505010.y" /* yacc.c:1646  */
    {
			
			//printf("At line no: %d expression_statement : expression SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d expression_statement : expression SEMICOLON\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			//allConcat.append("\n");
			
			//$$->setName(allConcat);
			//$$->setType("expression_statement");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			fprintf(fp2,"%s\n\n",allConcat.c_str());
			
			errFlag=0;
			
			(yyval)=(yyvsp[-1]);
			
			}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1613 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d variable : ID \n\n", line_num);
			fprintf(fp2, "At line no: %d variable : ID \n\n", line_num);
			
			//table->printAllScope(fp2);
			
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("variable");
			(yyval)->setType((yyvsp[0])->getType());
			
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			(yyval)->setName((yyvsp[0])->getName().c_str());
			string id = (yyvsp[0])->getName().c_str();
			id.append(" ");
			SymbolInfo *s = table->lookUp(id);
			if(!s->getName().compare("-1"))
			{				
				string err = "Undeclared Variable: ";
				err.append(id);
				printError(err, line_num);
				 //table->insert($1->getName().c_str(), $1->getType().c_str(), fp2);
			}
			else
			{
				(yyval)->type = s->type;
				
				
			}
			(yyval)->scope = s->scope;
			(yyval)->setName((yyvsp[0])->getName()+to_string(s->scope));
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s(%s)\n\n",$$->getName().c_str(), s->type.c_str());
			
			}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1649 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d variable : ID LTHIRD expression RTHIRD \n\n", line_num);
			fprintf(fp2, "At line no: %d variable : ID LTHIRD expression RTHIRD \n\n", line_num);
	
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			
			
			//if($3->getType().compare("INT"))
			if((yyvsp[-1])->type.compare("INT"))
			{
				string s = "Non-integer Array Index" ;
				printError(s, line_num);
			}
			
			
			
			
			
			string id = (yyvsp[-3])->getName().c_str();
			id.append(" ");
			SymbolInfo *s = table->lookUp(id);
			if(!s->getName().compare("-1"))
			{				
				string err = "Undeclared Variable: ";
				err.append(id);
				printError(err, line_num);
				 //table->insert($1->getName().c_str(), $1->getType().c_str(), fp2);
			}
			else if(s->type.compare("INT_ARRAY")){
				string err = "Not an array type variable ";
				err.append(s->getName().c_str());
				printError(err, line_num);
			}
			
			
			string allConcat ;
	
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
		
			(yyval)->setName(allConcat);
			//$$->setType("variable");
			(yyval)->setType(s->getType());
			(yyval)->type = s->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s) \n\n",$$->getName().c_str(), s->type.c_str());
			
			(yyval)->code=(yyvsp[-1])->code+"\tmov bx, " +(yyvsp[-1])->getName() +"\n\tadd bx, bx\n";
			//delete $3;
			//codeAsm << $$->code.c_str() <<endl;
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			
			}
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1707 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d expression : logic_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d expression : logic_expression \n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1720 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d expression : variable ASSIGNOP logic_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d expression : variable ASSIGNOP logic_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			//fprintf(fp2, "\n\n vartype: (%s) %s, exprs_type:(%s) %s\n\n", $1->getName().c_str(), varType.c_str(),  $3->getName().c_str(),logic_expressionType.c_str());
			
			string name = "";
			
			size_t found = (yyvsp[-2])->getName().find("[");
			if(found==string::npos)
			{
				string b = (yyvsp[-2])->getName().c_str();
				b.append(" ");
				SymbolInfo *s = table->lookUp(b);
				
				string varType = s->type.c_str();
				//string logic_expressionType = $3->getType().c_str();
				string logic_expressionType = (yyvsp[0])->type.c_str();
				
				
				
				//fprintf(fp2, "\n\n vartype: (%s) %s, exprs_type:(%s) %s\n\n", $1->getName().c_str(), varType.c_str(),  $3->getName().c_str(),logic_expressionType.c_str());
				if(!varType.compare("INT_ARRAY") && logic_expressionType.compare("INT_ARRAY"))
				{	
					string err = "Type Mismatch ";
					//err.append(varType);
					printError(err, line_num);
				}
				
				
				if(!logic_expressionType.compare("INT_ARRAY"))
				{
					logic_expressionType = "INT";
				}
				
				if(varType.compare(logic_expressionType))
				{
					string err = "Type Mismatch ";
					//err.append(varType);
					//err.append(" ");
					//err.append(logic_expressionType);
					printError(err, line_num);
				}
				
				/*
				if(!varType.compare("INT") && !logic_expressionType.compare("INT")){
			
				}
				else if(!varType.compare("FLOAT") && !logic_expressionType.compare("FLOAT")){	
				
				}
				else if(!varType.compare("INT_ARRAY") && found==string::npos)
				{	
					string err = "Type Mismatch ";
					//err.append(varType);
					printError(err, line_num);
				}
				else if(!varType.compare(logic_expressionType) && found!=string::npos )
				{ 
					//this command never runs
				}
				/*else if(!varType.compare("-1"))
				{ 
					
				}*/
				/*else
				{
					string err = "Type Mismatch ";
					err.append(varType);
					err.append(" ");
					err.append(logic_expressionType);
					printError(err, line_num);
				}*/
				
				name = (yyvsp[-2])->getName();
				
			}
			else
			{
				string varType = "INT_ARRAY";
				string logic_expressionType = (yyvsp[0])->type.c_str();
				//if(varType.compare(logic_expressionType)!=0 )
				
				//fprintf(fp2, "%s\n",logic_expressionType.c_str());
				
				if(logic_expressionType.compare("INT") && logic_expressionType.compare("INT_ARRAY") )
				{
					string err = "Type Mismatch (added 22-june)";
					//err.append(varType);
					printError(err, line_num);
				}
				
				vector <string> tokens;
				stringstream check1((yyvsp[-2])->getName().c_str());
				string intermediate;
				string intermediate2;
		
				while(getline(check1, intermediate, '[')){
					stringstream check2(intermediate);
					string intermediate2;
					if(getline(check2, intermediate2, ']')){
						tokens.push_back(intermediate2);
					}
					else { tokens.push_back(intermediate); }
				}
				
				
				name = tokens[0];
				
			}
			
			(yyval) = (yyvsp[-2]);
			
			(yyval)->code=(yyvsp[0])->code+(yyvsp[-2])->code;
			(yyval)->code+="\tmov ax, "+(yyvsp[0])->getName()+"\n";
			if((yyval)->type=="INT_ARRAY"){ 
				(yyval)->code+= "\tmov "+ name +"[bx], ax\n";	
			}
			else{
				(yyval)->code+= "\tmov "+ name +", ax\n";
			}
			//delete $3;
			
			//codeAsm << $$->code.c_str() << endl;
			
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
		
			(yyval)->setName(allConcat);
			//$$->setType("expression");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 3414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1864 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d logic_expression : rel_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d logic_expression : rel_expression \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("logic_expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 3431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1876 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d logic_expression : rel_expression LOGICOP rel_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d logic_expression : rel_expression LOGICOP rel_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			//$$->setType("logic_expression");
			
			if((yyvsp[-2])->type.compare((yyvsp[0])->type) && (yyvsp[-2])->type.compare("INT")){
				//error 
				string err = "Integer operand on logic operator ";
				printError(err, line_num);
				(yyval)->setType("error");
			}
			else
			{
				(yyval)->setType((yyvsp[-2])->getType());
				(yyval)->type = (yyvsp[-2])->type;
			}
			
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+="\tmov ax, " + (yyvsp[-2])->getName()+"\n";
			(yyval)->code+="\tmov bx, " + (yyvsp[0])->getName()+"\n";
			string temp=newTemp();
			string label1 = newLabel(); // ELSE
			string label2 = newLabel(); // END
					
			if((yyvsp[-1])->getName()=="&&"){
				/* 
				Check whether both operands value is 1. If both are one set value of a temporary variable to 1
				otherwise 0
				*/
				
				(yyval)->code += "\tcmp ax, 0\n";
				(yyval)->code += "\tje " + label1 + "\n";
				(yyval)->code += "\tcmp bx, 0\n";
				(yyval)->code += "\tje " + label1 + "\n"; // jump ELSE
				(yyval)->code += "\tmov " + temp + ", 1\n";
				(yyval)->code += "\tjmp " + label2 + "\n"; // jump END
				(yyval)->code += label1 + ": \n\tmov " + temp + ", 0\n";
				(yyval)->code += label2 + ": \n";
				
			}
			else if((yyvsp[-1])->getName()=="||"){
			
				// label1 = TRUE;
				//label2 = END;
				
				(yyval)->code += "\tcmp ax, 0\n";
				(yyval)->code += "\tjne " + label1 + "\n"; // jump TRUE
				(yyval)->code += "\tcmp bx, 0\n"; // first variable found false...
				(yyval)->code += "\tjne " + label1 + "\n"; // jump TRUE
				(yyval)->code += "\tmov " + temp + ", 0\n"; // false....
				(yyval)->code += "\tjmp " + label2 + "\n"; // jump END
				(yyval)->code += label1 + ": \n\tmov " + temp + ", 1\n";
				(yyval)->code += label2 + ": \n";
				
				
			}
			//delete $3;
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			
			//$$->setType("logic_expression");
			
			
			string concatType = (yyvsp[-2])->getType().c_str();
			concatType.append(" ");
			concatType.append((yyvsp[0])->getType().c_str());
			
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			
			
			(yyval)->setName(temp);
			
			//codeAsm << $$->code.c_str() <<endl;
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 3525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1967 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d rel_expression : simple_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d rel_expression : simple_expression \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("rel_expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 3541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1978 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d rel_expression : simple_expression RELOP simple_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d rel_expression : simple_expression RELOP simple_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			if((yyvsp[-2])->type!="FLOAT")
			{
				(yyvsp[-2])->type = "INT";
			}
			if((yyvsp[0])->type!="FLOAT")
			{
				(yyvsp[0])->type = "INT";
			}
			
			
			/*if($1->type.compare($3->type))
			{
				string err = "Type Mismatch: Both side of RELOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}*/
			
			
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+="\tmov ax, " + (yyvsp[-2])->getName()+"\n";
			(yyval)->code+="\tcmp ax, " + (yyvsp[0])->getName()+"\n";
			string temp=newTemp();
			string label1=newLabel();
			string label2=newLabel();
			if((yyvsp[-1])->getName()=="<"){
				(yyval)->code+="\tjl " + label1+"\n";
			}
			else if((yyvsp[-1])->getName()=="<="){
				(yyval)->code+="\tjle " + label1+"\n";
			}
			else if((yyvsp[-1])->getName()==">"){
				(yyval)->code+="\tjg " + label1+"\n";
			}
			else if((yyvsp[-1])->getName()==">="){
				(yyval)->code+="\tjge " + label1+"\n";
			}
			else if((yyvsp[-1])->getName()=="=="){
				(yyval)->code+="\tje " + label1+"\n";
			}
			else{
				(yyval)->code+="\tjne " + label1+"\n";
			}
			
			(yyval)->code+="\tmov "+temp +", 0\n";
			(yyval)->code+="\tjmp "+label2 +"\n";
			(yyval)->code+=label1+":\n\tmov "+temp+", 1\n";
			(yyval)->code+=label2+":\n";
			
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("rel_expression");
			
			string concatType = (yyvsp[-2])->getType().c_str();
			concatType.append(" ");
			concatType.append((yyvsp[0])->getType().c_str());
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			(yyval)->setName(temp);
			//delete $3;
			
			//codeAsm << $$->code.c_str() << endl;
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			}
#line 3627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 2061 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d simple_expression : term\n\n", line_num);
			fprintf(fp2, "At line no: %d simple_expression : term\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			//$$->setType("simple_expression");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 3645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 2074 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d simple_expression : simple_expression ADDOP term \n\n", line_num);
			fprintf(fp2, "At line no: %d simple_expression : simple_expression ADDOP term \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			///fprintf(fp2,"$1:%s $3:%s\n\n",$1->type.c_str(), $3->type.c_str());
			
			
			if(!(yyvsp[-2])->type.compare("FLOAT") && !(yyvsp[0])->type.compare("INT"))
			{
				(yyval)->setType((yyvsp[-2])->getType());
				(yyval)->type = (yyvsp[-2])->type;
			}
			else if(!(yyvsp[-2])->type.compare("INT") && !(yyvsp[0])->type.compare("FLOAT"))
			{
				(yyval)->setType((yyvsp[0])->getType());
				(yyval)->type = (yyvsp[0])->type;
			}
			else
			{
				(yyval)->setType((yyvsp[-2])->getType());
				(yyval)->type = (yyvsp[-2])->type;
			}
			
			
			
			/*
			
			if($1->type.compare($3->type)){
				string err = "Type Mismatch: Both side of ADDOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}*/
			
			(yyval) = (yyvsp[-2]);
			
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code += "\tmov ax, "+ (yyvsp[-2])->getName() +"\n";
			(yyval)->code += "\tmov bx, "+ (yyvsp[0])->getName() +"\n";
			// move one of the operands to a register, perform addition or subtraction with the other operand and move the result in a temporary variable  
			string temp=newTemp();
			if((yyvsp[-1])->getName()=="+"){
				(yyval)->code += "\tadd ax, bx\n";
				(yyval)->code += "\tmov "+ temp + ", ax\n";
			}
			else{
				(yyval)->code += "\tsub ax, bx\n";
				(yyval)->code += "\tmov "+ temp + ", ax\n";
			}
			//delete $3;
			//cout <<$$->code.c_str() << endl;
			//codeAsm << $$->code.c_str() << endl;
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			
			
			//string dollar1 = $1->getName();
			
			//$$ changed so did $1
			(yyval)->setName(allConcat);
			//$$->setType("simple_expression");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			string concatType = (yyvsp[-2])->getType().c_str();
			concatType.append(" ");
			concatType.append((yyvsp[0])->getType().c_str());
			
			
			
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			(yyval)->setName(temp);
			
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 2164 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d term : unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d term : unary_expression\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("term");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			}
#line 3754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 2175 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d term : term MULOP unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d term : term MULOP unary_expression\n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			
			
			///string a = $1->getType();
			///string b = $3->getType();
			
			string a = (yyvsp[-2])->type;
			string b = (yyvsp[0])->type;			
			
			///fprintf(fp2, "types: %s %s\n", a.c_str(), b.c_str());
			
			if(!a.compare("CONST_INT"))
			{
				a = "INT";
			}
			else if(!a.compare("CONST_FLOAT"))
			{
				a = "FLOAT";
			}
			
			if(!b.compare("CONST_INT"))
			{
				b = "INT";
			}
			else if(!b.compare("CONST_FLOAT"))
			{
				b = "FLOAT";
			}
			
			/*if(!$2->getName().compare("%") && $3->getType().compare("CONST_INT")){
				string err = "Integer operand on modulus operator";
				printError(err, line_num);				
			}
			
			if($1->getType().compare($3->getType())){
				string err = "Type Mismatch: Both side of MULOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}*/
			
			
			if(!(yyvsp[-1])->getName().compare("%") && b.compare("INT")){
				string err = "Integer operand on modulus operator ";
				//err.append(a);
				//err.append(" ");
				//err.append(b);
				printError(err, line_num);				
			}
			/*if((!a.compare("FLOAT") && !b.compare("INT")) || (!b.compare("FLOAT") && a.compare("INT")))
			{
				
			}
			
			if(a.compare(b)){
				string err = "Type Mismatch: Both side of MULOP should be same type ";
				
				err.append(a);
				err.append(" ");
				err.append(b);
				printError(err, line_num);
			}
			else
			{*/
				//$$->setType($1->getType());
				//$$->type = $1->type;
			//}
			
			
			if(!a.compare("FLOAT") && !b.compare("INT"))
			{
				(yyval)->setType((yyvsp[-2])->getType());
				(yyval)->type = a;
			}
			else if(!a.compare("INT") && !b.compare("FLOAT"))
			{
				(yyval)->setType((yyvsp[0])->getType());
				(yyval)->type = b;
			}
			else
			{
				(yyval)->setType((yyvsp[-2])->getType());
				(yyval)->type = a;
			}
			
			//string concatType = $1->getType().c_str();
			//concatType.append(" ");
			//concatType.append($3->getType().c_str());
			
			(yyval)->code += (yyvsp[0])->code;
			(yyval)->code += "\tmov ax, "+ (yyvsp[-2])->getName()+"\n";
			(yyval)->code += "\tmov bx, "+ (yyvsp[0])->getName() +"\n";
			string temp=newTemp();
			if((yyvsp[-1])->getName()=="*"){
				(yyval)->code += "\tmul bx\n";
				(yyval)->code += "\tmov "+ temp + ", ax\n";
			}
			else if((yyvsp[-1])->getName()=="/"){
				(yyval)->code +="\txor dx, dx\n";
				(yyval)->code += "\tdiv bx\n";
				(yyval)->code += "\tmov "+temp+", al\n"; // 8 bit quotient
				// clear dx, perform 'div bx' and mov ax to temp
			}
			else{
				(yyval)->code +="\txor dx, dx\n";
				(yyval)->code += "\tdiv bx\n";
				(yyval)->code += "\tmov "+temp+", ah\n"; // 8 bit remainder
				// clear dx, perform 'div bx' and mov dx to temp
			}
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("term");
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			(yyval)->setName(temp);
			cout << endl << (yyval)->code.c_str() << endl;
			
			//codeAsm << $$->code.c_str() << endl;
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			
			
			
			}
#line 3897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 2315 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unary_expression : ADDOP unary_expression  \n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : ADDOP unary_expression  \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("unary_expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 3918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 2331 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unary_expression : NOT unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : NOT unary_expression\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			(yyval)->setName(allConcat);
			//$$->setType("unary_expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			string temp=newTemp();
			(yyval)->code="\tmov ax, " + (yyvsp[0])->getName() + "\n";
			(yyval)->code+="\tnot ax\n";
			(yyval)->code+="\tmov "+temp+", ax";
						
			//cout << $$->code.c_str();
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			//codeAsm << $$->code.c_str();
			
			}
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 2357 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d unary_expression : factor \n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : factor \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unary_expression");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			// fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			}
#line 3966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 2371 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : variable\n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("factor");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type= (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			if((yyval)->type=="INT_ARRAY"){
				
				vector <string> tokens;
				stringstream check1((yyvsp[0])->getName().c_str());
				string intermediate;
				string intermediate2;
		
				while(getline(check1, intermediate, '[')){
					stringstream check2(intermediate);
					string intermediate2;
					if(getline(check2, intermediate2, ']')){
						tokens.push_back(intermediate2);
					}
					else { tokens.push_back(intermediate); }
				}
				
				string name = tokens[0];
				
				
				string temp= newTemp();
				(yyval)->code+="\tmov ax, " + name + "[bx]\n";
				(yyval)->code+= "\tmov " + temp + ", ax\n";
				(yyval)->setName(temp);
			}
			else{
				string temp = newTemp();
				(yyval)->code+="\tmov ax, " + (yyvsp[0])->getName() +"\n";
				(yyval)->code+= "\tmov " + temp + ", ax\n";
				(yyval)->setName(temp);
				//$$->code+="mov ax, 
			}
			
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			//codeAsm << $$->code.c_str();
			//cout <<  $$->code.c_str() << "\n" << $$->type.c_str() ;
			
			}
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 2420 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : ID LPAREN argument_list RPAREN\n\n", line_num);
			fprintf(fp2, "At line no: %d factor : ID LPAREN argument_list RPAREN\n\n", line_num);
			
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			string argList = (yyvsp[-1])->getName().c_str();
			string funcName = (yyvsp[-3])->getName().c_str();
			funcName.append(" ");
			SymbolInfo *funcNameSym = table->lookUp(funcName);
			string args="";	
			vector<string> tokens;
			
			if(!funcNameSym->getName().compare("-1"))
			{
				string err = "Undeclared Function ";
				err.append(funcName);
				printError(err, line_num);
			}
			else if(!funcNameSym->defined){
				string err = "Undfined Function ";
				err.append(funcName);
				printError(err, line_num);
			}
			else{
			
			
			vector<string> typeTokens;
			stringstream check2((yyvsp[-1])->getType().c_str());
			string intermediate2;
		
			while(getline(check2, intermediate2, ' ')){
				typeTokens.push_back(intermediate2);
			}
		
			
					
			
			///fprintf(fp2, "argList: %s\n",$3->getName().c_str());
			///fprintf(fp2, "funcPara: %s\n",funcNameSym->getName().c_str());
			
			stringstream check1(argList.c_str());
			string intermediate;
		
			while(getline(check1, intermediate, ',')){
				tokens.push_back(intermediate);
			}
			
			if(tokens.size()!=funcNameSym->functionParameters.size())
			{
				string err = "Parameter number doesn't match!";
				printError(err, line_num);
			}
			else{
			
			for(int i=0, j=0; i<tokens.size(); i++, j++) {	
				string b = tokens[i];
				b.append(" ");
				///fprintf(fp2, "Looking:%s (%s %s) 'typeTokens': %s \n",b.c_str(), $3->type.c_str(), $3->getType().c_str(), typeTokens[i].c_str());
				SymbolInfo *s2 = table->lookUp(b);
				if(!s2->getName().compare("-1"))
				{				
					
					if(!typeTokens[i].compare("CONST_INT"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("INT"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							(yyvsp[-1])->setName("error");
							break;
						}
					}
					else if(!typeTokens[i].compare("CONST_FLOAT"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("FLOAT"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							(yyvsp[-1])->setName("error");
							break;
						}
					}
					else if(!typeTokens[i].compare("CONST_CHAR"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("CHAR"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							(yyvsp[-1])->setName("error");
							break;
						}
					}
					else
					{
						string err = "Undeclared Variable: ";
						err.append(b);
						printError(err, line_num);
						break;
					}
						
				}
				else
				{
					string argType = s2->type;
					string parameterType = funcNameSym->functionParameters[j];
					if(parameterType.compare(argType))
					{
						string err = "Type Mismatch";
						printError(err, line_num);
						(yyvsp[-1])->setName("error");
						break;
					}
				}
				
				//args+="\tpush "+tokens[i]+"\n";
		
			}
			}
			
			
			
			}
			for(int i=tokens.size()-1; i>=0; i--)
			{
				args+="\tpush "+tokens[i]+"\n";
			}
			
			(yyval)->code += "\n\t;push register data\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\n";
			//now push argument lists..
			(yyval)->code+=args;
			
			(yyval)->code +="\n\tcall "+ (yyvsp[-3])->getName()+"\n\n";
			string temp = newTemp();
			if(funcNameSym->type=="INT")	{
				
				(yyval)->code+= "\tpop ax\t\t;function's return value in ax register\n";
				(yyval)->code+="\tmov "+temp+", ax\n";
				declared_variables+=temp+"\tDW\t ?\n";
			}
			(yyval)->code +="\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n";
			string allConcat ;
			
			allConcat.append((yyvsp[-3])->getName().c_str());
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
		
			(yyval)->setName(allConcat);
			(yyval)->setType(funcNameSym->type);
			(yyval)->type = funcNameSym->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			(yyval)->setName(temp);
			fprintf(fp2,"%s\n\n",(yyval)->code.c_str());
			
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			
			}
#line 4185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 2580 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : LPAREN expression RPAREN \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : LPAREN expression RPAREN \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
		
			(yyval)->setName(allConcat);
			
			(yyval)->setType((yyvsp[-1])->getType());
			(yyval)->type = (yyvsp[-1])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			
			(yyval) = (yyvsp[-1]);
			
			}
#line 4211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 2601 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : CONST_INT \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_INT \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("CONST_INT");
			(yyval)->type = "INT";
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 4225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 2610 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : CONST_FLOAT \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_FLOAT \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("CONST_FLOAT");
			(yyval)->type = "FLOAT";
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 4239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 2619 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : CONST_CHAR \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_CHAR \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			(yyval)->setType("CONST_CHAR");
			(yyval)->type = "CHAR";
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 4253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2628 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : variable INCOP \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable INCOP \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			
			
			//write type checking..
			if((yyvsp[-1])->type.compare("INT") && (yyvsp[-1])->type.compare("INT_ARRAY") )
			{
				string err = "Type Mismatch: INCOP applicable only with INT";
				printError(err, line_num);
			}
			else
			{
				(yyval)->setType((yyvsp[-1])->getType());
				(yyval)->type = (yyvsp[-1])->type;
			}

			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			//$$->setType("factor");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			string temp=newTemp();
			if((yyvsp[-1])->type=="INT_ARRAY")
			{
				
			}
			else
			{
				
				(yyval)->code="\tmov ax, " + (yyvsp[-1])->getName() + "\n";
				(yyval)->code+="\tinc ax\n";
				(yyval)->code+="\tmov "+temp+", ax";
			
			}
			
			(yyval)->setName(temp);
			
			}
#line 4300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2670 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d factor : variable DECOP \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable DECOP \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			
			
			//write type checking..
			
			if((yyvsp[-1])->type.compare("INT") && (yyvsp[-1])->type.compare("INT_ARRAY") )
			{
				string err = "Type Mismatch: INCOP applicable only with INT";
				printError(err, line_num);
			}
			else
			{
				(yyval)->setType((yyvsp[-1])->getType());
				(yyval)->type = (yyvsp[-1])->type;
			}
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
			//$$->setType("factor");
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			string temp=newTemp();
			if((yyvsp[-1])->type=="INT_ARRAY")
			{
			
			}
			else
			{
				
				(yyval)->code="\tmov ax, " + (yyvsp[-1])->getName() + "\n";
				(yyval)->code+="\tdec ax\n";
				(yyval)->code+="\tmov "+temp+", ax";
			
			}
						
			//cout << $$->code.c_str();
			fprintf(fp2, "%s\n\n", (yyval)->code.c_str());
			//codeAsm << $$->code.c_str();
			(yyval)->setName(temp);
			
			}
#line 4352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2719 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d argument_list : arguments\n\n", line_num);
			fprintf(fp2, "At line no: %d argument_list : arguments\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("argument_list");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str() ,$$->getType().c_str());
			
			}
#line 4370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2733 "1505010.y" /* yacc.c:1646  */
    {
			  	(yyval) = new SymbolInfo("", "");
			  	(yyval)->setName("");
			  	
			  }
#line 4380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2740 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d arguments : arguments COMMA logic_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d arguments : arguments COMMA logic_expression\n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			
			string allConcat ;
			
			allConcat.append((yyvsp[-2])->getName().c_str());
			allConcat.append((yyvsp[-1])->getName().c_str());
			allConcat.append((yyvsp[0])->getName().c_str());
		
			(yyval)->setName(allConcat);
			//$$->setType("arguments");
			
			
			string typeConcat;
			
			typeConcat.append((yyvsp[-2])->getType().c_str());
			typeConcat.append(" ");
			typeConcat.append((yyvsp[0])->getType().c_str());
		
			(yyval)->setType(typeConcat);
			
			//$$->setType($1->getType());
			(yyval)->type = (yyvsp[-2])->type;
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			
			}
#line 4417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2772 "1505010.y" /* yacc.c:1646  */
    {
			//printf("At line no: %d arguments : logic_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d arguments : logic_expression\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("arguments");
			(yyval)->setType((yyvsp[0])->getType());
			(yyval)->type = (yyvsp[0])->type;
			
			fprintf(fp2,"%s\n\n",(yyval)->getName().c_str());
			}
#line 4433 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4437 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2786 "1505010.y" /* yacc.c:1906  */


int main(int argc,char *argv[])
{
	table = new SymbolTable;	
	table->setCapacity(20);
	//sym = new SymbolTable;
	//sym->setCapacity(10);
	
	logout= fopen("1505010_logScanner.txt","w");
	tokenout= fopen("1505010_tokenScanner.txt","w");

	FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	fp2= fopen(argv[2],"w");
	fclose(fp2);
	fp3= fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a");
	
	codeAsm.open("code.asm");
	
	

	yyin=fp;
	yyparse();
	

	fclose(fp2);
	fclose(fp3);
	
	return 0;
}

