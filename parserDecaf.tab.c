/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parserDecaf.y"

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
using  namespace  std;
extern void yyerror(const char *);
extern int yylex();
extern int yylineno;
extern int num_lines;
extern int num_caracteres;
static void createNode(Nodo *n);
static void readVector();
static void makeDirectory(string nombre);
static string itostr(int d);
static string ftostr(double d);
static string stostr(string d);
static void PrintTree(Nodo * tree);

#line 97 "parserDecaf.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    INT = 258,
    FLOAT = 259,
    BOOLEAN = 260,
    OP_LOG = 261,
    OP_ALG = 262,
    SYMBOL = 263,
    IDENTIFIER = 264,
    S_COMMENT = 265,
    OPEN_STRING = 266,
    STRING = 267,
    HEX = 268,
    TYPE = 269,
    SQRBRACKET = 270,
    TAG = 271,
    SEMICOLON = 272,
    OPENPAR = 273,
    CLOSEPAR = 274,
    VOID = 275,
    COMMA = 276,
    CLASS = 277,
    EXTENDS = 278,
    IMPLEMENTS = 279,
    INTERFACE = 280,
    IF = 281,
    ELSE = 282,
    WHILE = 283,
    FOR = 284,
    RETURN = 285,
    BREAK = 286,
    PRINT = 287,
    OPENBRA = 288,
    CLOSEBRA = 289,
    THIS = 290,
    READINT = 291,
    READLINE = 292,
    NEW = 293,
    NEWARRAY = 294,
    CLOSESQR = 295,
    INTCONST = 296,
    DOUBLECONST = 297,
    BOOLCONST = 298,
    STRCONST = 299,
    Null = 300,
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
#line 29 "parserDecaf.y"

    int int_val;
    double double_val;
    string* str_val;
    Nodo *nodo;


#line 204 "parserDecaf.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERDECAF_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

#define YYUNDEFTOK  2
#define YYMAXUTOK   310

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
       0,    60,    60,    62,    63,    65,    66,    67,    68,    70,
      72,    73,    77,    78,    80,    81,    84,    85,    87,    88,
      90,    91,    92,    93,    96,    97,    99,   100,   102,   103,
     105,   106,   108,   110,   111,   113,   114,   116,   118,   119,
     121,   122,   124,   125,   126,   127,   128,   129,   130,   131,
     133,   134,   137,   138,   140,   142,   144,   145,   147,   149,
     150,   152,   154,   156,   157,   159,   160,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   180,   181,   182,   184,   185,   187,
     188,   190,   191,   192,   193,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOLEAN", "OP_LOG",
  "OP_ALG", "SYMBOL", "IDENTIFIER", "S_COMMENT", "OPEN_STRING", "STRING",
  "HEX", "TYPE", "SQRBRACKET", "TAG", "SEMICOLON", "OPENPAR", "CLOSEPAR",
  "VOID", "COMMA", "CLASS", "EXTENDS", "IMPLEMENTS", "INTERFACE", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "PRINT", "OPENBRA",
  "CLOSEBRA", "THIS", "READINT", "READLINE", "NEW", "NEWARRAY", "CLOSESQR",
  "INTCONST", "DOUBLECONST", "BOOLCONST", "STRCONST", "Null", "EQUALS",
  "LOG_OR", "LOG_AND", "OP_IGUALDAD", "OP_REL", "SUM_RESTA", "MUL_DIV_MOD",
  "NOT", "OPENSQR", "POINT", "$accept", "Program", "Decls", "Decl",
  "VariableDecl", "Variable", "FunctionDecl", "Formals", "CommaVariables",
  "CommaVarList", "ClassDecl", "CommaIdentifiers", "CommaIdentList",
  "Fields", "Field", "InterfaceDecl", "Prototypes", "Prototype",
  "StmtBlock", "VariableDecls", "Stmts", "Stmt", "Expresions", "IfStmt",
  "WhileStmt", "ForStmt", "ForExpresion", "ReturnStmt", "ReturnExpresion",
  "BreakStmt", "PrintStmt", "CommaExpresions", "CommaExpList", "Expresion",
  "LValue", "Call", "Actuals", "Constant", YY_NULLPTR
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

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,    68,    40,    53,    79,    10,    90,  -163,  -163,   -12,
    -163,  -163,  -163,    57,    80,    85,    83,    81,  -163,  -163,
    -163,    87,  -163,    87,   104,   108,  -163,  -163,    72,  -163,
      99,    87,   115,   101,     3,  -163,    -3,   116,     5,     6,
    -163,   107,   115,    87,   107,   108,  -163,  -163,   116,   132,
    -163,  -163,  -163,  -163,   134,   135,  -163,  -163,  -163,  -163,
    -163,  -163,     2,    58,    65,  -163,   127,   129,    87,  -163,
    -163,  -163,    87,    87,  -163,    93,    66,   145,   154,  -163,
    -163,  -163,   156,  -163,   167,   160,   162,   163,   167,   136,
     164,  -163,  -163,   166,   168,   178,   179,  -163,   167,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   140,   131,
    -163,  -163,  -163,   181,   182,   167,   174,   167,   167,   167,
     183,   228,  -163,   167,   191,   196,   192,   167,   228,  -163,
     167,   167,   167,   167,   167,   167,   167,   208,   167,  -163,
    -163,   167,   198,   228,   199,  -163,   188,   197,   213,   228,
    -163,    29,  -163,  -163,   212,   206,   236,   100,   228,   228,
     159,    -4,   219,   214,   228,   198,   167,  -163,   130,   130,
     167,   216,  -163,   220,  -163,   167,   228,   223,  -163,   224,
    -163,   243,   244,   130,   167,  -163,  -163,  -163,   245,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     5,     0,
       6,     7,     8,    10,     0,     0,     0,     0,     1,     4,
       9,    14,    11,    14,     0,     0,    28,    33,     0,    18,
       0,    15,    16,     0,     0,    26,     0,    24,     0,     0,
      10,     0,    17,     0,     0,     0,    28,    28,    25,     0,
      20,    30,    31,    29,     0,     0,    32,    34,    38,    12,
      19,    13,     0,     0,     0,    27,     0,     0,    40,    28,
      21,    22,    14,    14,    39,     0,     0,     0,     0,    91,
      92,    93,    84,    94,     0,     0,     0,     0,    59,     0,
       0,    37,    70,     0,     0,     0,     0,    95,     0,    49,
      41,    42,    43,    44,    45,    47,    46,    48,     0,    69,
      71,    68,    23,     0,     0,    89,     0,     0,     0,    56,
       0,    60,    61,     0,     0,     0,     0,     0,    79,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    90,    63,    65,     0,    72,     0,     0,     0,    57,
      58,     0,    80,    81,     0,     0,    78,    77,    76,    75,
      73,    74,     0,    85,    67,    64,     0,    87,    50,    50,
      56,     0,    82,     0,    86,    89,    66,    52,    54,     0,
      62,     0,     0,    50,    56,    83,    88,    53,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   259,     1,   -19,    84,    -2,  -163,   241,
    -163,   247,   -33,   -32,  -163,  -163,  -163,  -163,    32,  -163,
    -163,  -152,  -163,  -163,  -163,  -163,  -162,  -163,  -163,  -163,
    -163,   158,  -123,   -75,  -163,  -163,   114,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    51,     9,    52,    30,    31,    32,
      11,    36,    37,    38,    53,    12,    39,    57,    99,    68,
      75,   100,   101,   102,   103,   104,   148,   105,   120,   106,
     107,   141,   142,   143,   109,   110,   144,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     108,     8,    29,    48,    29,    20,    35,     8,   179,   116,
      18,    35,    29,   121,    63,    64,   177,   178,   165,     1,
      54,    33,   188,   128,    60,     2,    55,    45,   165,    48,
      47,   187,    79,    80,    81,    69,    46,    76,    82,    50,
      56,    83,   146,   147,   149,   132,   133,    84,   171,    15,
     136,   137,   155,    29,    29,   156,   157,   158,   159,   160,
     161,   162,    16,   164,    92,    93,    94,    95,    96,    74,
      77,    78,     1,    59,    97,    21,    61,    13,     2,     1,
       1,    40,    98,    14,    10,     2,     2,    14,    17,    22,
      10,   176,    70,   108,   108,   149,    79,    80,    81,    71,
     112,    28,    82,    23,     1,    83,    24,    25,   108,   149,
       2,    84,     3,    34,    27,     4,    26,    35,    41,    85,
      44,    86,    87,    88,    89,    90,    58,    91,    92,    93,
      94,    95,    96,    79,    80,    81,    43,    49,    97,    82,
      58,    65,    83,    66,    67,    72,    98,    73,    84,   132,
     133,   134,   135,   122,   136,   137,    85,   129,    86,    87,
      88,    89,    90,    58,   113,    92,    93,    94,    95,    96,
      79,    80,    81,   114,   115,    97,    82,   138,   117,    83,
     118,   119,   123,    98,   124,    84,   125,   130,   131,   132,
     133,   134,   135,   145,   136,   137,   126,   127,   139,   140,
     150,   154,    92,    93,    94,    95,    96,   168,   132,   133,
     152,   135,    97,   136,   137,   153,   169,   163,   167,   166,
      98,   130,   131,   132,   133,   134,   135,   173,   136,   137,
     170,   172,   175,   180,   181,   130,   131,   132,   133,   134,
     135,   184,   136,   137,   130,   131,   132,   133,   134,   135,
     183,   136,   137,   130,   131,   132,   133,   134,   135,   174,
     136,   137,   185,   186,   189,    19,   130,   131,   132,   133,
     134,   135,    42,   136,   137,   130,   131,   132,   133,   134,
     135,   151,   136,   137,   131,   132,   133,   134,   135,   182,
     136,   137,    62
};

static const yytype_uint8 yycheck[] =
{
      75,     0,    21,    36,    23,    17,     9,     6,   170,    84,
       0,     9,    31,    88,    46,    47,   168,   169,   141,    14,
      14,    23,   184,    98,    43,    20,    20,    24,   151,    62,
      33,   183,     3,     4,     5,    33,    33,    69,     9,    34,
      34,    12,   117,   118,   119,    49,    50,    18,    19,     9,
      54,    55,   127,    72,    73,   130,   131,   132,   133,   134,
     135,   136,     9,   138,    35,    36,    37,    38,    39,    68,
      72,    73,    14,    41,    45,    18,    44,     9,    20,    14,
      14,     9,    53,    15,     0,    20,    20,    15,     9,     9,
       6,   166,    34,   168,   169,   170,     3,     4,     5,    34,
      34,    14,     9,    18,    14,    12,    23,    24,   183,   184,
      20,    18,    22,     9,    33,    25,    33,     9,    19,    26,
      19,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     3,     4,     5,    21,    21,    45,     9,
      33,     9,    12,     9,     9,    18,    53,    18,    18,    49,
      50,    51,    52,    17,    54,    55,    26,    17,    28,    29,
      30,    31,    32,    33,    19,    35,    36,    37,    38,    39,
       3,     4,     5,    19,    18,    45,     9,    46,    18,    12,
      18,    18,    18,    53,    18,    18,    18,    47,    48,    49,
      50,    51,    52,    19,    54,    55,    18,    18,    17,    17,
      17,     9,    35,    36,    37,    38,    39,    19,    49,    50,
      19,    52,    45,    54,    55,    19,    19,     9,    19,    21,
      53,    47,    48,    49,    50,    51,    52,    21,    54,    55,
      17,    19,    18,    17,    14,    47,    48,    49,    50,    51,
      52,    17,    54,    55,    47,    48,    49,    50,    51,    52,
      27,    54,    55,    47,    48,    49,    50,    51,    52,    40,
      54,    55,    19,    19,    19,     6,    47,    48,    49,    50,
      51,    52,    31,    54,    55,    47,    48,    49,    50,    51,
      52,   123,    54,    55,    48,    49,    50,    51,    52,   175,
      54,    55,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    20,    22,    25,    57,    58,    59,    60,    61,
      62,    66,    71,     9,    15,     9,     9,     9,     0,    59,
      17,    18,     9,    18,    23,    24,    33,    33,    14,    61,
      63,    64,    65,    63,     9,     9,    67,    68,    69,    72,
       9,    19,    65,    21,    19,    24,    33,    33,    68,    21,
      34,    60,    62,    70,    14,    20,    34,    73,    33,    74,
      61,    74,    67,    69,    69,     9,     9,     9,    75,    33,
      34,    34,    18,    18,    60,    76,    69,    63,    63,     3,
       4,     5,     9,    12,    18,    26,    28,    29,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    45,    53,    74,
      77,    78,    79,    80,    81,    83,    85,    86,    89,    90,
      91,    93,    34,    19,    19,    18,    89,    18,    18,    18,
      84,    89,    17,    18,    18,    18,    18,    18,    89,    17,
      47,    48,    49,    50,    51,    52,    54,    55,    46,    17,
      17,    87,    88,    89,    92,    19,    89,    89,    82,    89,
      17,    87,    19,    19,     9,    89,    89,    89,    89,    89,
      89,    89,    89,     9,    89,    88,    21,    19,    19,    19,
      17,    19,    19,    21,    40,    18,    89,    77,    77,    82,
      17,    14,    92,    27,    17,    19,    19,    77,    82,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    82,    83,    84,
      84,    85,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     3,     6,     6,     0,     1,     1,     2,     1,     3,
       5,     7,     7,     9,     1,     2,     1,     3,     0,     2,
       1,     1,     5,     0,     2,     6,     6,     4,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     5,     7,     5,     8,     0,     1,     3,     0,
       1,     2,     5,     1,     2,     1,     3,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     4,     6,     1,     3,     4,     4,     6,     0,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 60 "parserDecaf.y"
    {Nodo *arbol = new Nodo("Program",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL); }
#line 1455 "parserDecaf.tab.c"
    break;

  case 3:
#line 62 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decls",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1461 "parserDecaf.tab.c"
    break;

  case 4:
#line 63 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decls",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1467 "parserDecaf.tab.c"
    break;

  case 5:
#line 65 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1473 "parserDecaf.tab.c"
    break;

  case 6:
#line 66 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1479 "parserDecaf.tab.c"
    break;

  case 7:
#line 67 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1485 "parserDecaf.tab.c"
    break;

  case 8:
#line 68 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Decl",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1491 "parserDecaf.tab.c"
    break;

  case 9:
#line 70 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("VariableDecl",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1497 "parserDecaf.tab.c"
    break;

  case 10:
#line 72 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Variable",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1503 "parserDecaf.tab.c"
    break;

  case 11:
#line 73 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Variable",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1509 "parserDecaf.tab.c"
    break;

  case 12:
#line 77 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("FunctionDecl",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1515 "parserDecaf.tab.c"
    break;

  case 13:
#line 78 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("FunctionDecl",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1521 "parserDecaf.tab.c"
    break;

  case 15:
#line 81 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Formals",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1527 "parserDecaf.tab.c"
    break;

  case 16:
#line 84 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaVariables",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1533 "parserDecaf.tab.c"
    break;

  case 17:
#line 85 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaVariables",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1539 "parserDecaf.tab.c"
    break;

  case 18:
#line 87 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaVarList",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1545 "parserDecaf.tab.c"
    break;

  case 19:
#line 88 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaVarList",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1551 "parserDecaf.tab.c"
    break;

  case 20:
#line 90 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1557 "parserDecaf.tab.c"
    break;

  case 21:
#line 91 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1563 "parserDecaf.tab.c"
    break;

  case 22:
#line 92 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1569 "parserDecaf.tab.c"
    break;

  case 23:
#line 93 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1575 "parserDecaf.tab.c"
    break;

  case 24:
#line 96 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1581 "parserDecaf.tab.c"
    break;

  case 25:
#line 97 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1587 "parserDecaf.tab.c"
    break;

  case 26:
#line 99 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1593 "parserDecaf.tab.c"
    break;

  case 27:
#line 100 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1599 "parserDecaf.tab.c"
    break;

  case 29:
#line 103 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Fields",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1605 "parserDecaf.tab.c"
    break;

  case 30:
#line 105 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Field",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1611 "parserDecaf.tab.c"
    break;

  case 31:
#line 106 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Field",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1617 "parserDecaf.tab.c"
    break;

  case 32:
#line 108 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("InterfaceDecl",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1623 "parserDecaf.tab.c"
    break;

  case 34:
#line 111 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Prototypes",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1629 "parserDecaf.tab.c"
    break;

  case 35:
#line 113 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Prototype",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1635 "parserDecaf.tab.c"
    break;

  case 36:
#line 114 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Prototype",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1641 "parserDecaf.tab.c"
    break;

  case 37:
#line 116 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("StmtBlock",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[-1].nodo),NULL);}
#line 1647 "parserDecaf.tab.c"
    break;

  case 39:
#line 119 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("VariableDecls",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1653 "parserDecaf.tab.c"
    break;

  case 41:
#line 122 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmts",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1659 "parserDecaf.tab.c"
    break;

  case 42:
#line 124 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1665 "parserDecaf.tab.c"
    break;

  case 43:
#line 125 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1671 "parserDecaf.tab.c"
    break;

  case 44:
#line 126 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1677 "parserDecaf.tab.c"
    break;

  case 45:
#line 127 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1683 "parserDecaf.tab.c"
    break;

  case 46:
#line 128 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1689 "parserDecaf.tab.c"
    break;

  case 47:
#line 129 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1695 "parserDecaf.tab.c"
    break;

  case 48:
#line 130 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1701 "parserDecaf.tab.c"
    break;

  case 49:
#line 131 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Stmt",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1707 "parserDecaf.tab.c"
    break;

  case 51:
#line 134 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresions",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1713 "parserDecaf.tab.c"
    break;

  case 52:
#line 137 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("IfStmt",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1719 "parserDecaf.tab.c"
    break;

  case 53:
#line 138 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("IfStmt",num_lines,num_caracteres,"NA",(yyvsp[-4].nodo),(yyvsp[-2].nodo),(yyvsp[0].nodo));}
#line 1725 "parserDecaf.tab.c"
    break;

  case 54:
#line 140 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("WhileStmt",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1731 "parserDecaf.tab.c"
    break;

  case 55:
#line 142 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ForStmt",num_lines,num_caracteres,"NA",(yyvsp[-5].nodo),(yyvsp[-3].nodo),(yyvsp[-1].nodo));}
#line 1737 "parserDecaf.tab.c"
    break;

  case 57:
#line 145 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ForExpresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1743 "parserDecaf.tab.c"
    break;

  case 58:
#line 147 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ReturnStmt",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1749 "parserDecaf.tab.c"
    break;

  case 60:
#line 150 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("ReturnExpresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1755 "parserDecaf.tab.c"
    break;

  case 61:
#line 152 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("BreakStmt",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1761 "parserDecaf.tab.c"
    break;

  case 62:
#line 154 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("PrintStmt",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1767 "parserDecaf.tab.c"
    break;

  case 63:
#line 156 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1773 "parserDecaf.tab.c"
    break;

  case 64:
#line 157 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),(yyvsp[0].nodo),NULL);}
#line 1779 "parserDecaf.tab.c"
    break;

  case 65:
#line 159 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaExpList",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1785 "parserDecaf.tab.c"
    break;

  case 66:
#line 160 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("CommaExpList",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1791 "parserDecaf.tab.c"
    break;

  case 67:
#line 162 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1797 "parserDecaf.tab.c"
    break;

  case 68:
#line 163 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1803 "parserDecaf.tab.c"
    break;

  case 69:
#line 164 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1809 "parserDecaf.tab.c"
    break;

  case 70:
#line 165 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1815 "parserDecaf.tab.c"
    break;

  case 71:
#line 166 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1821 "parserDecaf.tab.c"
    break;

  case 72:
#line 167 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1827 "parserDecaf.tab.c"
    break;

  case 73:
#line 168 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1833 "parserDecaf.tab.c"
    break;

  case 74:
#line 169 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1839 "parserDecaf.tab.c"
    break;

  case 75:
#line 170 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1845 "parserDecaf.tab.c"
    break;

  case 76:
#line 171 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1851 "parserDecaf.tab.c"
    break;

  case 77:
#line 172 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1857 "parserDecaf.tab.c"
    break;

  case 78:
#line 173 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),(yyvsp[0].nodo),NULL);}
#line 1863 "parserDecaf.tab.c"
    break;

  case 79:
#line 174 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1869 "parserDecaf.tab.c"
    break;

  case 80:
#line 175 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1875 "parserDecaf.tab.c"
    break;

  case 81:
#line 176 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1881 "parserDecaf.tab.c"
    break;

  case 82:
#line 177 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1887 "parserDecaf.tab.c"
    break;

  case 83:
#line 178 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Expresion",num_lines,num_caracteres,"NA",(yyvsp[-3].nodo),NULL,NULL);}
#line 1893 "parserDecaf.tab.c"
    break;

  case 84:
#line 180 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1899 "parserDecaf.tab.c"
    break;

  case 85:
#line 181 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA",(yyvsp[-2].nodo),NULL,NULL);}
#line 1905 "parserDecaf.tab.c"
    break;

  case 86:
#line 182 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("LValue",num_lines,num_caracteres,"NA",(yyvsp[-3].nodo),(yyvsp[-1].nodo),NULL);}
#line 1911 "parserDecaf.tab.c"
    break;

  case 87:
#line 184 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA",(yyvsp[-1].nodo),NULL,NULL);}
#line 1917 "parserDecaf.tab.c"
    break;

  case 88:
#line 185 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA",(yyvsp[-5].nodo),(yyvsp[-1].nodo),NULL);}
#line 1923 "parserDecaf.tab.c"
    break;

  case 90:
#line 188 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("Call",num_lines,num_caracteres,"NA",(yyvsp[0].nodo),NULL,NULL);}
#line 1929 "parserDecaf.tab.c"
    break;

  case 91:
#line 190 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("INT",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1935 "parserDecaf.tab.c"
    break;

  case 92:
#line 191 "parserDecaf.y"
    {(yyval.nodo) = new Nodo("FLOAT",num_lines,num_caracteres,"NA",NULL,NULL,NULL);}
#line 1941 "parserDecaf.tab.c"
    break;


#line 1945 "parserDecaf.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 196 "parserDecaf.y"


static vector<Nodo*> v ;

static void createNode(Nodo *n){
    v.push_back(n);
    //printf("%s\n","Inserted!");
}

static string path = "/home/dereck05/Desktop/Pruebas";

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
       printf("%s",v[i]->nombre.c_str());
       makeDirectory(v[i]->nombre);
       if(v[i]->valor != "NA"){
           printf("%s","  valor:");
           printf("%s",v[i]->valor.c_str());
	         makeDirectory(v[i]->valor.c_str());
       }
    }
}

static string itostr(int d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;


}
static string ftostr(double d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}
static string stostr(string d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}

static void PrintTree(Nodo * tree){
  if(tree == NULL)return;
  printf("ID: %s",tree->nombre.c_str());
  PrintTree(tree->first);
  PrintTree(tree->second);
  PrintTree(tree->third);
}
