/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 29 "parserDecaf.y" /* yacc.c:1909  */

    int int_val;
    double double_val;
    string* str_val;
    Nodo *nodo;


#line 118 "parserDecaf.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERDECAF_TAB_H_INCLUDED  */
