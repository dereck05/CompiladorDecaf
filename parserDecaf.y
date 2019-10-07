%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include  <iostream>
using  namespace  std;
extern void yyerror(char *);
extern int yylex();
%}

%union{
    int int_val;
    double double_val;
    string* str_val;

}


%token <int_val> INT END_OF_FILE
%token <double_val> FLOAT
%token <str_val> BOOLEAN OP_REL OP_LOG OP_ALG SYMBOL RESERVED IDENTIFIER S_COMMENT OPEN_STRING STRING ERROR HEX
%start Program

%%
Program : Decl;

Decl :  Decl Example|Example;

Example : BOOLEAN {printf("%s\n","El scanner dio: BOOLEAN");}
        |INT SYMBOL {printf("%s\n","El scanner dio: INT SYMBOL");};




