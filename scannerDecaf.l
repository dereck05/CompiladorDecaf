%{
#include<stdio.h>
%}


DIGIT 		[0-9]
ID       	[a-z][a-z0-9_]{0,31}
AF    		[a-f|A-F]
X     		[x|X]
E_ATOM		[n|t|\"|\\]
STRESC		["\"{E_ATOM}]
HEX   		0{X}{DIGIT}|{AF}
NOSTR   	[^{STRESC}|\r\n|\"]
BEGINCOMMENT	[/*]
ENDCOMMENT	[*/]
TAG      \\[r  | n]
OP_REL   [">=" | "<=" | ">" | "<" | "==" | "!=" | "="]
OP_LOG   ["&&" | "!" | "||"]
OP_ALG   ["+" | "-" | "/" | "*" | "%"]
SYMBOL   [";" | "," | "." | "[" | "]" | "{" | "}" | "(" | ")"]
RESERVED [void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false]

%%

True|False                      	                           printf("BOOLEAN");
{OP_REL}                                  		               printf("OP_REL");
{OP_LOG}        			                                       printf("OP_LOG");
{OP_ALG}                  			                             printf("OP_ALG");
{SYMBOL}	                                                   printf("SYMBOL");
{RESERVED}                              			               printf("RESERVED");
{DIGIT}+ | {HEX}+                                            printf("INT");
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?                           printf("FLOAT");
{ID}					                                               printf("IDENTIFIER");
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT})                    printf("S_COMMENT");
\"([^"\\])*\"                                                printf("STRING");
.           				                                         printf( "Unrecognized character");

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
