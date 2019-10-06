%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>

extern void yyerror(char *);
extern int yylex();
%}

%token BOOLEAN OP_REL OP_LOG OP_ALG SYMBOL RESERVED INT FLOAT IDENTIFIER S_COMMENT OPEN_STRING STRING ERROR
%start Program

%%
Program : Decl;

Decl :  BOOLEAN	{printf{$1;}}
        |INT SYMBOL {printf{$1,$2;}};




