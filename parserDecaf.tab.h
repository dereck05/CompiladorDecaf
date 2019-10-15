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
    OP_REL = 261,
    OP_LOG = 262,
    OP_ALG = 263,
    SYMBOL = 264,
    IDENTIFIER = 265,
    S_COMMENT = 266,
    OPEN_STRING = 267,
    STRING = 268,
    HEX = 269,
    TYPE = 270,
    SQRBRACKET = 271,
    TAG = 272,
    SEMICOLON = 273,
    OPENPAR = 274,
    CLOSEPAR = 275,
    VOID = 276,
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
    EQUALS = 291,
    THIS = 292,
    NOT = 293,
    READINT = 294,
    READLINE = 295,
    NEW = 296,
    NEWARRAY = 297,
    POINT = 298,
    OPENSQR = 299,
    CLOSESQR = 300,
    INTCONST = 301,
    DOUBLECONST = 302,
    BOOLCONST = 303,
    STRCONST = 304,
    Null = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parserDecaf.y" /* yacc.c:1909  */

    int int_val;
    double double_val;
    string* str_val;


#line 112 "parserDecaf.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERDECAF_TAB_H_INCLUDED  */
