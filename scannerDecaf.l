%{
<<<<<<< Updated upstream
#include<stdio.h>
=======
#include  <cstdio>
#include  <cstdlib>
#include  <string>
using  namespace  std;
#include "parserDecaf.tab.h"   //  output  of  bison on  example1.y
void yyerror(char *);
int  yyparse(void);
int num_lineas = 0, num_caracteres = 0;
>>>>>>> Stashed changes
%}


DIGIT 		   [0-9]
ID       	   [a-zA-Z][a-zA-Z0-9_]{0,30} //CAMBIO MAYUSCULAS
AF    		   [a-f|A-F]
X     		   [x|X]
E_ATOM		   [n|t|\"|\\]
STRESC		   ["\"{E_ATOM}]
<<<<<<< Updated upstream
HEX   		   0{X}{DIGIT}|{AF}
NOSTR   	   [^{STRESC}|\r\n|\"]
BEGINCOMMENT [/*]
ENDCOMMENT	 [*/]
TAG          \\[n | t]
BODY_STRING  ([^"\\])*
OP_REL       [">=" | "<=" | ">" | "<" | "==" | "!=" | "="]
OP_LOG       ["&&" | "!" | "||"]
OP_ALG       ["+" | "-" | "/" | "*" | "%"]
SYMBOL       [";" | "," | "." | "[" | "\]" | "{" | "}" | "(" | ")"]
RESERVED     [void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false]

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
\"{BODY_STRING}\"                                            printf("STRING");
\"{BODY_STRING}                                              printf("OPEN STRING");
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
=======
HEX   		   0[x|X]({DIGIT}|{AF})+
NOSTR   	   [^{STRESC}|\n|\"]
BEGINCOMMENT 	   [/*]
ENDCOMMENT	   [*/]
TAG          \\[n|t]
BLANK        [ \t\n]+
BODY_STRING  ([^\\n"\\])*
OP_REL       (">="|"<="|">"|"<"|"=="|"!="|"=")
OP_LOG       ("&&"|"!"|"||")
OP_ALG       ("+"|"-"|"/"|"*"|"%")
SYMBOL       (";"|","|"."|"["|"\]"|"{"|"}"|"("|")")
RESERVED     (void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false)

%%

True|False                      	                  return "BOOLEAN";
{OP_REL}                                  		  return("OP_REL";)
{OP_LOG}          			                  return("OP_LOG";)
{OP_ALG}                 			          return("OP_ALG";)
{SYMBOL}                                                  return("SYMBOL";)
{RESERVED}                              		  return("RESERVED")
{DIGIT}+|{HEX}                                            return("INT")
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?                        return("FLOAT")
{ID}BLANK					                                            return("IDENTIFIER")
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT})                  {printf("Ignorar")} //eliminar xq ignora los comentarios
\"{BODY_STRING}                                           {printf("String no cerrado en línea %d y columna %d\n",num_lineas,num_caracteres)}//string abierto
\"{BODY_STRING}\"                                         return("STRING")
{BLANK}                                                   printf("BLANK")
.           				                                      {printf("Caracter ilegal <%s> en linea %d y columna %d\n",yytex,num_lineas,num_caracteres);}//token ilegal 

%%
void  yyerror(char* str) {
    printf("Parse  Error: \n%s\n",str );
}
int  yywrap(void) {}
int  main(int  num_args , char** args) {
    if(num_args  != 2) {
        printf("usage: ./ parser1  filename\n");
        exit (0);}FILE* file = fopen(args[1],"r");
        if(file == NULL) {
            printf("couldn ’t open %s\n", args [1]);
            exit (0);
        }
        yyin = file;   // now  flex  reads  from  file
        yyparse ();
        fclose(file);
}
>>>>>>> Stashed changes
