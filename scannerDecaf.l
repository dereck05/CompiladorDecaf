%{
#include<stdio.h>
%}


DIGIT 		[0-9]
ID       	[a-z][a-z0-9_]{0,31}
AF    		[a-f|A-F]
X     		[x|X]
E_ATOM		[n|t|\"|\]
STRESC		["\"{E_ATOM}]
HEX   		{DIGIT}|{AF}
NOSTR   	[^{STRESC}|\r\n|\"]
BEGINCOMMENT	[/*]
ENDCOMMENT	[*/]

%%

{DIGIT}+		                printf("INT");	
0{X}{HEX}+				printf("HEX"); /* HEX */
True|False                      	printf("BOOLEAN");			
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?      printf("FLOAT");
void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false			                printf("RESERVED");
\"([^"\\])*\"                           printf("STRING");
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT}) printf("S_COMMENT");
{ID}					printf("IDENTIFIER");
">="|"<="|">"|"<"|"=="|"!="|"="		printf("OP_REL");
"&&"|"!"|"||"				printf("OP_LOG");
"+"|"-"|"/"|"*"|"%"			printf("OP_ALG");
";"|","|"."|"["|"]"|"{"|\]"}"|"("|")"	printf("SYMBOL");
.           				printf( "Unrecognized character");

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

