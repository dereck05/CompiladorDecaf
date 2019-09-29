%{
#include<stdio.h>
%}


DIGIT [0-9]

HEX   0[x|X][{DIGIT}|a-f|A-F]+
INT   [{DIGIT}]+
SCI   E[+][DIGIT]+
FLOAT [+|-]?(DIGIT+[.])?[DIGIT]+
STR   ["][.^("|\.[^nt"\])|\r\n]["]
%%


>=|<=|>|<|==|!=|=		printf("OP_REL");
&&|!				printf("OP_LOG");
\|\|				printf("OP_LOG");
\+|-|\/|\*|%			printf("OP_ALG");
;|,|\.|[|]|\{|\}|\(|\)		printf("SYMBOL");
{INT}		                printf("INT");	
{HEX}				printf("INT");
True|False                      printf("BOOLEAN");			
{FLOAT}                         printf("FLOAT");
{STR}                           printf("STRING");


%%
main(argc,argv)
int argc;
char ** argv;
	{
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;
	yylex();
	}


