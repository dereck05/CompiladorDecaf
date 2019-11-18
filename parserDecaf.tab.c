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
#line 1 "parserDecaf.y" /* yacc.c:339  */

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <sstream>
#include <vector>
#include  <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stdc++.h>
#include "Nodo.h"
#include "VarObject.h"
using  namespace  std;
extern void yyerror(const char *);
extern int yylex();
extern int yylineno;
extern int num_lines;
extern int num_caracteres;
static void createNode(Nodo *n);
static void readVector();
static void analizadorSemantico(Nodo* tree);
static void analizarWhile(Nodo* tree);
static vector< vector<VarObject> > construirTabla(Nodo* arbol);
static void printScopes(vector< vector<VarObject> > r);
static void makeDirectory(string nombre);
static char* itostr(int d);
static char* ftostr(double d);
static string stostr(string d);
static void PrintTree(Nodo * tree);

#line 97 "parserDecaf.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parserDecaf.tab.h".  */
#ifndef YY_YY_PARSERDECAF_TAB_H_INCLUDED
# define YY_YY_PARSERDECAF_TAB_H_INCLUDED
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
    STRING = 258,
    Null = 259,
    BOOLEAN = 260,
    IDENTIFIER = 261,
    SQRBRACKET = 262,
    VOID = 263,
    TYPE = 264,
    INT = 265,
    FLOAT = 266,
    OP_LOG = 267,
    OP_ALG = 268,
    SYMBOL = 269,
    S_COMMENT = 270,
    OPEN_STRING = 271,
    HEX = 272,
    TAG = 273,
    SEMICOLON = 274,
    OPENPAR = 275,
    CLOSEPAR = 276,
    COMMA = 277,
    CLASS = 278,
    EXTENDS = 279,
    IMPLEMENTS = 280,
    INTERFACE = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    FOR = 285,
    RETURN = 286,
    BREAK = 287,
    PRINT = 288,
    OPENBRA = 289,
    CLOSEBRA = 290,
    THIS = 291,
    READINT = 292,
    READLINE = 293,
    NEW = 294,
    NEWARRAY = 295,
    CLOSESQR = 296,
    INTCONST = 297,
    DOUBLECONST = 298,
    BOOLCONST = 299,
    STRCONST = 300,
    EQUALS = 301,
    LOG_OR = 302,
    LOG_AND = 303,
    OP_IGUALDAD = 304,
    OP_REL = 305,
    SUM_RESTA = 306,
    MUL_DIV_MOD = 307,
    NOT = 308,
    OPENSQR = 309,
    POINT = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parserDecaf.y" /* yacc.c:355  */

  struct{
    char* int_val;
    char* double_val;
    string* str_val;
    Nodo *nodo;

    char* tipo;
    char* voidT;
    char* id;
    char* stringValue;
    char* nullValue;
    char* boolValue;
  };


#line 210 "parserDecaf.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERDECAF_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "parserDecaf.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    87,    88,    90,    91,    92,    93,    95,
      97,    98,   102,   103,   105,   106,   111,   112,   114,   115,
     118,   119,   120,   121,   123,   124,   126,   127,   129,   130,
     132,   133,   134,   136,   138,   139,   141,   142,   144,   146,
     147,   149,   150,   152,   153,   154,   155,   156,   157,   158,
     159,   161,   162,   165,   166,   168,   170,   172,   173,   175,
     177,   178,   180,   182,   184,   185,   187,   188,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   208,   209,   210,   212,   213,
     215,   216,   218,   219,   220,   221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "Null", "BOOLEAN",
  "IDENTIFIER", "SQRBRACKET", "VOID", "TYPE", "INT", "FLOAT", "OP_LOG",
  "OP_ALG", "SYMBOL", "S_COMMENT", "OPEN_STRING", "HEX", "TAG",
  "SEMICOLON", "OPENPAR", "CLOSEPAR", "COMMA", "CLASS", "EXTENDS",
  "IMPLEMENTS", "INTERFACE", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "BREAK", "PRINT", "OPENBRA", "CLOSEBRA", "THIS", "READINT", "READLINE",
  "NEW", "NEWARRAY", "CLOSESQR", "INTCONST", "DOUBLECONST", "BOOLCONST",
  "STRCONST", "EQUALS", "LOG_OR", "LOG_AND", "OP_IGUALDAD", "OP_REL",
  "SUM_RESTA", "MUL_DIV_MOD", "NOT", "OPENSQR", "POINT", "$accept",
  "Program", "Decls", "Decl", "VariableDecl", "Variable", "FunctionDecl",
  "Formals", "CommaVariables", "CommaVarList", "ClassDecl",
  "CommaIdentifiers", "CommaIdentList", "Fields", "Field", "InterfaceDecl",
  "Prototypes", "Prototype", "StmtBlock", "VariableDecls", "Stmts", "Stmt",
  "Expresions", "IfStmt", "WhileStmt", "ForStmt", "ForExpresion",
  "ReturnStmt", "ReturnExpresion", "BreakStmt", "PrintStmt",
  "CommaExpresions", "CommaExpList", "Expresion", "LValue", "Call",
  "Actuals", "Constant", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      59,     0,    55,    22,    53,    27,    59,  -159,  -159,     2,
    -159,  -159,  -159,    45,    46,    63,    64,    43,  -159,  -159,
    -159,    83,    83,  -159,    80,    87,    15,  -159,    77,  -159,
      73,    83,    95,    74,    21,  -159,    -4,   100,  -159,  -159,
    -159,    96,    15,    10,  -159,    98,    95,    83,    98,    87,
      15,    15,   100,   127,  -159,  -159,   128,   130,  -159,  -159,
    -159,  -159,  -159,  -159,     7,   118,   119,  -159,   123,   135,
      70,    15,  -159,  -159,    83,    83,  -159,  -159,  -159,   138,
    -159,  -159,   167,   139,   142,   143,   167,   145,   148,  -159,
     149,   154,   155,   156,   167,  -159,  -159,   144,   108,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   141,   134,  -159,  -159,
     159,   160,   177,   167,   176,   167,   167,   167,   181,   164,
    -159,   167,   180,   188,   204,   167,   164,  -159,  -159,  -159,
     167,   167,   167,   167,   167,   167,   167,   215,   167,  -159,
     183,   203,   167,   210,   164,   212,  -159,   187,   196,   221,
     164,  -159,   146,  -159,  -159,   228,   207,   227,    75,   164,
     164,   234,    66,   219,   232,   164,  -159,  -159,   210,   167,
    -159,   108,   108,   167,   244,  -159,   255,  -159,   167,   164,
     137,  -159,   246,  -159,   251,   259,   108,   167,  -159,  -159,
    -159,   264,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     5,     0,
       6,     7,     8,     0,    10,     0,     0,     0,     1,     4,
       9,    14,    14,    11,     0,     0,    28,    34,     0,    18,
       0,    15,    16,     0,     0,    26,     0,    24,    30,    32,
      31,     0,    28,     0,    10,     0,    17,     0,     0,     0,
      28,    28,    25,     0,    20,    29,     0,     0,    33,    35,
      39,    13,    19,    12,     0,     0,     0,    27,     0,     0,
      41,    28,    21,    22,    14,    14,    95,    96,    94,    85,
      92,    93,     0,     0,     0,     0,    60,     0,     0,    70,
       0,     0,     0,     0,     0,    40,    50,     0,    41,    43,
      44,    45,    46,    48,    47,    49,     0,    69,    71,    68,
       0,     0,     0,    90,     0,     0,     0,    57,     0,    61,
      62,     0,     0,     0,     0,     0,    79,    38,    42,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,    91,    64,    66,     0,    72,     0,     0,     0,
      58,    59,     0,    80,    81,     0,     0,    78,    77,    76,
      75,    73,    74,     0,    86,    84,    37,    36,    65,     0,
      88,    51,    51,    57,     0,    82,     0,    87,    90,    67,
      53,    55,     0,    63,     0,     0,    51,    57,    83,    89,
      54,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   247,     1,   -11,     3,   -17,  -159,   256,
      72,   241,   -22,   -34,  -159,  -159,  -159,  -159,    -1,  -159,
     193,  -146,  -159,  -159,  -159,  -159,  -158,  -159,  -159,  -159,
    -159,   171,  -120,   -82,  -159,  -159,   115,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    38,     9,    39,    30,    31,    32,
      40,    36,    37,    41,    42,    12,    43,    59,    96,    70,
      97,    98,    99,   100,   101,   102,   149,   103,   118,   104,
     105,   142,   143,   106,   107,   108,   145,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     114,     8,    35,    10,   119,    33,    13,     8,    55,    10,
      29,    29,   126,    35,    52,   182,    65,    66,    56,    57,
      29,    20,   168,     1,     2,   180,   181,    18,    16,   191,
      51,   144,   168,   147,   148,   150,    62,   110,     3,   144,
     190,    71,    52,   156,    61,    58,    49,    63,   157,   158,
     159,   160,   161,   162,   163,    50,   165,   111,   112,    17,
     144,    14,    15,    29,    29,    21,    22,     1,     2,    23,
     144,    95,    11,    76,    77,    78,    79,    27,    11,    28,
      80,    81,     3,    44,    15,     4,    34,   179,    24,    25,
      82,   150,    28,    35,    45,    48,   144,    83,    26,    84,
      85,    86,    87,    88,    60,   150,    89,    90,    91,    92,
      93,    76,    77,    78,    79,   132,   133,    47,    80,    81,
     136,   137,    53,    94,   132,   133,   134,   135,    82,   136,
     137,    54,    60,    67,    68,    83,    69,    84,    85,    86,
      87,    88,    60,    74,    89,    90,    91,    92,    93,    76,
      77,    78,    79,    72,    73,    75,    80,    81,   113,   115,
     129,    94,   116,   117,   120,   186,    82,   174,   121,   122,
      76,    77,    78,    79,   123,   124,   125,    80,    81,   127,
     138,   140,    89,    90,    91,    92,    93,    82,   130,   131,
     132,   133,   134,   135,   139,   136,   137,   146,   141,    94,
     151,   153,   166,    89,    90,    91,    92,    93,   171,   154,
     155,   130,   131,   132,   133,   134,   135,   172,   136,   137,
      94,   164,   167,   130,   131,   132,   133,   134,   135,   176,
     136,   137,   169,   170,   130,   131,   132,   133,   134,   135,
     173,   136,   137,   130,   131,   132,   133,   134,   135,   175,
     136,   137,   178,    19,   130,   131,   132,   133,   134,   135,
     177,   136,   137,   183,   184,   187,   130,   131,   132,   133,
     134,   135,   188,   136,   137,   131,   132,   133,   134,   135,
     189,   136,   137,   132,   133,   192,   135,    46,   136,   137,
      64,   128,   152,   185
};

static const yytype_uint8 yycheck[] =
{
      82,     0,     6,     0,    86,    22,     6,     6,    42,     6,
      21,    22,    94,     6,    36,   173,    50,    51,     8,     9,
      31,    19,   142,     8,     9,   171,   172,     0,     6,   187,
      34,   113,   152,   115,   116,   117,    47,    71,    23,   121,
     186,    34,    64,   125,    45,    35,    25,    48,   130,   131,
     132,   133,   134,   135,   136,    34,   138,    74,    75,     6,
     142,     6,     7,    74,    75,    20,    20,     8,     9,     6,
     152,    70,     0,     3,     4,     5,     6,    34,     6,     9,
      10,    11,    23,     6,     7,    26,     6,   169,    24,    25,
      20,   173,     9,     6,    21,    21,   178,    27,    34,    29,
      30,    31,    32,    33,    34,   187,    36,    37,    38,    39,
      40,     3,     4,     5,     6,    49,    50,    22,    10,    11,
      54,    55,    22,    53,    49,    50,    51,    52,    20,    54,
      55,    35,    34,     6,     6,    27,     6,    29,    30,    31,
      32,    33,    34,    20,    36,    37,    38,    39,    40,     3,
       4,     5,     6,    35,    35,    20,    10,    11,    20,    20,
      19,    53,    20,    20,    19,    28,    20,    21,    20,    20,
       3,     4,     5,     6,    20,    20,    20,    10,    11,    35,
      46,    21,    36,    37,    38,    39,    40,    20,    47,    48,
      49,    50,    51,    52,    35,    54,    55,    21,    21,    53,
      19,    21,    19,    36,    37,    38,    39,    40,    21,    21,
       6,    47,    48,    49,    50,    51,    52,    21,    54,    55,
      53,     6,    19,    47,    48,    49,    50,    51,    52,    22,
      54,    55,    22,    21,    47,    48,    49,    50,    51,    52,
      19,    54,    55,    47,    48,    49,    50,    51,    52,    21,
      54,    55,    20,     6,    47,    48,    49,    50,    51,    52,
      41,    54,    55,    19,     9,    19,    47,    48,    49,    50,
      51,    52,    21,    54,    55,    48,    49,    50,    51,    52,
      21,    54,    55,    49,    50,    21,    52,    31,    54,    55,
      49,    98,   121,   178
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    23,    26,    57,    58,    59,    60,    61,
      62,    66,    71,     6,     6,     7,     6,     6,     0,    59,
      19,    20,    20,     6,    24,    25,    34,    34,     9,    61,
      63,    64,    65,    63,     6,     6,    67,    68,    60,    62,
      66,    69,    70,    72,     6,    21,    65,    22,    21,    25,
      34,    34,    68,    22,    35,    69,     8,     9,    35,    73,
      34,    74,    61,    74,    67,    69,    69,     6,     6,     6,
      75,    34,    35,    35,    20,    20,     3,     4,     5,     6,
      10,    11,    20,    27,    29,    30,    31,    32,    33,    36,
      37,    38,    39,    40,    53,    60,    74,    76,    77,    78,
      79,    80,    81,    83,    85,    86,    89,    90,    91,    93,
      69,    63,    63,    20,    89,    20,    20,    20,    84,    89,
      19,    20,    20,    20,    20,    20,    89,    35,    76,    19,
      47,    48,    49,    50,    51,    52,    54,    55,    46,    35,
      21,    21,    87,    88,    89,    92,    21,    89,    89,    82,
      89,    19,    87,    21,    21,     6,    89,    89,    89,    89,
      89,    89,    89,    89,     6,    89,    19,    19,    88,    22,
      21,    21,    21,    19,    21,    21,    22,    41,    20,    89,
      77,    77,    82,    19,     9,    92,    28,    19,    21,    21,
      77,    82,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    71,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    79,    80,    81,    82,    82,    83,
      84,    84,    85,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     3,     6,     6,     0,     1,     1,     2,     1,     3,
       5,     7,     7,     9,     1,     2,     1,     3,     0,     2,
       1,     1,     1,     5,     0,     2,     6,     6,     4,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     5,     7,     5,     8,     0,     1,     3,
       0,     1,     2,     5,     1,     2,     1,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     4,     6,     3,     1,     3,     4,     4,     6,
       0,     1,     1,     1,     1,     1,     1
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
#line 78 "parserDecaf.y" /* yacc.c:1646  */
    {Nodo *arbol = new Nodo("Program",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);
		PrintTree(arbol);
	analizadorSemantico(arbol);
    //vector< vector<VarObject> > v = construirTabla(arbol);
    //cout<< v.size();
    //printScopes(v);

		}
#line 1473 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1479 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) =(yyvsp[-1].nodo);(yyvsp[-1].nodo) = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1485 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1491 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1497 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1503 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1509 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("VariableDecl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1515 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Variable",num_lines,num_caracteres,(yyvsp[-1].tipo),(yyvsp[0].id),"NA",NULL,NULL,NULL);}
#line 1521 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "parserDecaf.y" /* yacc.c:1646  */
    {char * c =&(string((yyvsp[-2].tipo))+string((yyvsp[-1].id)))[0] ;(yyval.nodo) = new Nodo("Variable",num_lines,num_caracteres,c,(yyvsp[0].id),"NA",NULL,NULL,NULL);}
#line 1527 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("FunctionDecl",num_lines,num_caracteres,(yyvsp[-5].tipo),(yyvsp[-4].id),"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1533 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("FunctionDecl",num_lines,num_caracteres,(yyvsp[-5].voidT),(yyvsp[-4].id),"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1539 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Formals",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1545 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 111 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaVariables",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1551 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 112 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaVariables",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1557 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaVarList",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1563 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaVarList",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1569 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",(yyvsp[-3].id),"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1575 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1581 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1587 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1593 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 123 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1599 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1605 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 126 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",(yyvsp[0].id),"NA",NULL,NULL,NULL);}
#line 1611 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",(yyvsp[0].id),"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1617 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "parserDecaf.y" /* yacc.c:1646  */
    {((yyval.nodo)=(yyvsp[-1].nodo)) =new Nodo("Fields",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1623 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1629 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 133 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1635 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 134 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1641 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 136 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("InterfaceDecl",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1647 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Prototypes",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1653 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 141 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Prototype",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1659 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 142 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Prototype",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1665 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 144 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("StmtBlock",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[-1].nodo),NULL);}
#line 1671 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("VariableDecls",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1677 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 150 "parserDecaf.y" /* yacc.c:1646  */
    {((yyval.nodo) =(yyvsp[-1].nodo)) = new Nodo("Stmts",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1683 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 152 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1689 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 153 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1695 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1701 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1707 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 156 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1713 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 157 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1719 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 158 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1725 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 159 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1731 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 162 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Expresions",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1737 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 165 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("IfStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1743 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 166 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("IfStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-4].nodo),(yyvsp[-2].nodo),(yyvsp[0].nodo));}
#line 1749 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 168 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("WhileStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1755 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 170 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ForStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-5].nodo),(yyvsp[-3].nodo),(yyvsp[-1].nodo));}
#line 1761 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 173 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ForExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1767 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 175 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ReturnStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1773 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 178 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ReturnExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1779 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 180 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("BreakStmt",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
#line 1785 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("PrintStmt",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1791 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 184 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1797 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 185 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1803 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 187 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaExpList",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1809 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CommaExpList",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1815 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 190 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ConstantExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1821 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 191 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("LValueExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1827 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 192 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ThisExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
#line 1833 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 193 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("CallExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1839 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 194 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1845 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 195 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("SumExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1851 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 196 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("MulDivModExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1857 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 197 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("OpRelExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1863 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 198 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("OpIgualExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1869 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 199 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("AndExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1875 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 200 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("OrExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1881 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 201 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("NotExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1887 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 202 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ReadIntExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
#line 1893 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 203 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("ReadLineExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
#line 1899 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 204 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("NewExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
#line 1905 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 205 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("NewArrExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-3].nodo),NULL,NULL);}
#line 1911 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 206 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("EqualExpresion",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1917 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 208 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA",(yyvsp[0].id),"NA",NULL,NULL,NULL);}
#line 1923 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 209 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA",(yyvsp[0].id),"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1929 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 210 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1935 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 212 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA",(yyvsp[-3].id),"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1941 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 213 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA",(yyvsp[-3].id),"NA",(yyvsp[-5].nodo),(yyvsp[-1].nodo),NULL);}
#line 1947 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 216 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA","NA","NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1953 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 218 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("INT",num_lines,num_caracteres,"NA","NA",(yyvsp[0].int_val),NULL,NULL,NULL);}
#line 1959 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 219 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("FLOAT",num_lines,num_caracteres,"NA","NA",(yyvsp[0].double_val),NULL,NULL,NULL);}
#line 1965 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 220 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("BOOLEAN",num_lines,num_caracteres,"NA","NA",(yyvsp[0].boolValue),NULL,NULL,NULL);}
#line 1971 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 221 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("STRING",num_lines,num_caracteres,"NA","NA",(yyvsp[0].stringValue),NULL,NULL,NULL);}
#line 1977 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 222 "parserDecaf.y" /* yacc.c:1646  */
    {(yyval.nodo) = new Nodo("Null",num_lines,num_caracteres,"NA","NA",(yyvsp[0].nullValue),NULL,NULL,NULL);}
#line 1983 "parserDecaf.tab.c" /* yacc.c:1646  */
    break;


#line 1987 "parserDecaf.tab.c" /* yacc.c:1646  */
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
#line 224 "parserDecaf.y" /* yacc.c:1906  */


static vector<Nodo*> v ;

static void createNode(Nodo *n){
    v.push_back(n);
    //printf("%s\n","Inserted!");
}

static string path = "/home/natalia/Desktop/Pruebas";

static void makeDirectory(string nombre){
	path = path +"/"+ nombre;
	//printf("%s\n",path.c_str());
	mkdir(path.c_str() ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

static void readVector(){
    for(int i =0;i<v.size(); i++){
       printf("\n%s","fila:");
       printf("%d",v[i]->fila);
       printf("%s","  columna:");
       printf("%d",v[i]->columna);
       printf("%s","  nombre:");
       printf("%s",v[i]->nombre);
       makeDirectory(v[i]->nombre);
       if(v[i]->valor != "NA"){
           printf("%s","  valor:");
           printf("%s",v[i]->valor);
	         makeDirectory(v[i]->valor);
       }
    }
}


static string stostr(string d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}

static void PrintTree(Nodo* tree){
  if(tree == NULL) {
     return;
  }
  printf("ID: %s",tree->nombre.c_str());
  if(tree->tipo != "NA")cout<<" Tipo:"<<string(tree->tipo);
  if(tree->identificador != "NA")cout<<" identificador:"<<string(tree->identificador);
  if(tree->valor != "NA")cout<<" Valor:"<<string(tree->valor);
  printf("\n");
  PrintTree(tree->first);
  PrintTree(tree->second);
  PrintTree(tree->third);
}


//_________________________________________________Semantical____________________________________________

static void analizadorSemantico(Nodo* tree){
	//printf("olAA: %s",tree->nombre.c_str());
	string s = tree->nombre.c_str();
	cout << "HOLAAA: "<< s << endl;
    if(tree == NULL) {
       return;
    }
    if((s.compare("WhileStmt")) == 0){
      analizarWhile(tree);
    }
    if((s.compare("ForStmt")) == 0){
      //analizarWhile()
    }

    analizadorSemantico(tree->first);
    analizadorSemantico(tree->second);
    analizadorSemantico(tree->third);
}

static void analizarWhile(Nodo* tree){
	cout << "AQUIIII: "<< tree->first->nombre.c_str() << endl;	
	string s = tree->first->nombre.c_str();
	int c = s.compare("");
	if(c==0){
		//nada
	}
}


static vector< vector<VarObject> > result;

static vector< vector<VarObject> > construirTabla(Nodo* arbol){
  if(arbol==NULL){

    return result;
  }
  string s = arbol->nombre.c_str();
  int c = s.compare("ClassDecl");
  if(c==0){
    vector<VarObject> v;
    result.push_back(v);
  }
  c = s.compare("FunctionDecl");
  if(c == 0){
    vector<VarObject> v;
    result.push_back(v);

  }
  c = s.compare("Variable");
  if(c == 0){
    VarObject var;
    var.tipo = arbol->tipo;
    var.identificador = arbol->identificador;
    var.valor = "";
    int pos = result.size()-1;
    for(int i = 0; i< result.size(); i++){
      for(int j = 0; j < result.at(i).size();j++){
        string v1 = var.identificador;
        string v2 = result.at(i).at(j).identificador;
        int c = v1.compare(v2);
        if(c == 0){
          cout<<"Error, la variable "<<v1<<" ya existe"<<endl;
          exit(0);
        }

      }
    }
    result.at(pos).push_back(var);
  }
  c = s.compare("EqualExpresion");
  if(c == 0){
    string id = arbol->first->identificador;
    string val = arbol->second->first->valor;
    int found = 0;
    for(int i = 0;i<result.size();i++){
      for(int j = 0; j<result.at(i).size();j++){
        int x = result.at(i).at(j).identificador.compare(id);
        if(x == 0){
          result.at(i).at(j).valor = val;
          found = 1;
        }

      }
    }
    if(found == 0){
      cout<<"Error, la variable "<<id<<" no fue declarada previamente"<<endl;
      exit(0);
    }
  }
  construirTabla(arbol->first);
  construirTabla(arbol->second);
  construirTabla(arbol->third);
  return result;

}

static void printScopes(vector< vector<VarObject> > r){

  for(int i = 0;i<r.size();i++){
    vector<VarObject> v = r.at(i);
    cout<<"--------------Scope--------------"<<endl;
    for(int j = 0; j<v.size();j++){
      VarObject var = v.at(j);
      cout<< "Tipo:"<<var.tipo;
      cout<< " ID:"<<var.identificador;
      cout<< " Valor:"<<var.valor<<endl;

    }
  }

}
