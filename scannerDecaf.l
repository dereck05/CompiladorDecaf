%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
using  namespace  std;
#include "parserDecaf.tab.h"   //  output  of  bison on  example1.y
void yyerror(char *);
int  yyparse(void);
%}


DIGIT 		   [0-9]
ID       	   [a-z][a-z0-9_]{0,31}
AF    		   [a-f|A-F]
E_ATOM		   [n|t|\"|\\]
STRESC		   ["\"{E_ATOM}]
HEX   		   0[x|X]({DIGIT}|{AF})+
NOSTR   	   [^{STRESC}|\n|\"]
BEGINCOMMENT 	   [/*]
ENDCOMMENT	   [*/]
TAG          \\[n|t]
BODY_STRING  ([^\\n"\\])*
OP_REL       (">="|"<="|">"|"<"|"=="|"!="|"=")
OP_LOG       ("&&"|"!"|"||")
OP_ALG       ("+"|"-"|"/"|"*"|"%")
SYMBOL       (";"|","|"."|"["|"\]"|"{"|"}"|"("|")")
RESERVED     (void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false)

%%

True|False                      	                  return "BOOLEAN";
{OP_REL}                                 		  return("OP_REL";)
{OP_LOG}        			                  return("OP_LOG";)
{OP_ALG}                 			          return("OP_ALG";)
{SYMBOL}                                                  return("SYMBOL";)
{RESERVED}                              		  return("RESERVED")
{DIGIT}+|{HEX}                                            return("INT")
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?                        return("FLOAT")
{ID}					                  return("IDENTIFIER")
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT})                 return("S_COMMENT")
\"{BODY_STRING}                                           return("OPEN STRING")
\"{BODY_STRING}\"                                         return("STRING")

.           				                  return("ERROR")

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

