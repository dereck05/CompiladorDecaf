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
TAG          ("\n"|"\t"|"\r"|"\\")
BODY_STRING  ({TAG})*
OP_REL       (">="|"<="|">"|"<"|"=="|"!=")
BOOLEAN	     (True|False)
OP_LOG       ("&&"|"||")
NOT 	     ("!")
OP_ALG       ("+"|"-"|"/"|"*"|"%")
SEMICOLON    (";")
TYPE	     (int|double|bool|string|id)
SQRBRACKET   ("[\]")
EQUALS       ("=")
OPENBRA	     ("{")
CLOSEBRA     ("}")
COMMA	     (",")
OPENPAR	     ("(")
CLOSEPAR     (")")
VOID         (void)
CLASS	     (class)
EXTENDS      (extends)
IMPLEMENTS   (implements)
INTERFACE    (interface)
IF 	     (if)
ELSE         (else)
WHILE        (while)
FOR	     (for)
RETURN       (return)
THIS         (this)
BREAK	     (break)
PRINT	     (Print)
READINT	     (ReadInteger)
READLINE     (ReadLine)
NEW          (New)
NEWARRAY     (NewArray)
POINT        (".")
OPENSQR      ("[")
CLOSESQR     ("]")
INTCONST     (intConstant)
DOUBLECONST  (doubleConstant)
BOOLCONST    (boolConstant)
STRCONST     (stringConstant)
Null	     (null)
%%

{BOOLEAN}						  {return BOOLEAN;}
{OP_REL}                                 		  {return OP_REL;}
{OP_LOG}        			                  {return OP_LOG;}
{OP_ALG}                 			          {return OP_ALG;}
{NOT}							  {return NOT;}
{SEMICOLON}						  {return SEMICOLON;}
{TYPE}							  {return TYPE;}
{SQRBRACKET}					          {return SQRBRACKET;}
{EQUALS}						  {return EQUALS;}
{OPENPAR}						  {return OPENPAR;}
{CLOSEPAR}						  {return CLOSEPAR;}
{OPENBRA}						  {return OPENBRA;}
{CLOSEBRA}						  {return CLOSEBRA;}
{VOID}							  {return VOID;}
{COMMA}							  {return COMMA;}
{CLASS}	     						  {return CLASS;}
{EXTENDS}     						  {return EXTENDS;}
{IMPLEMENTS}      					  {return IMPLEMENTS;}
{INTERFACE}    						  {return INTERFACE;}
{THIS}							  {return THIS;}
{IF} 	     						  {return IF;}
{ELSE}         						  {return ELSE;}
{WHILE}        						  {return WHILE;}
{FOR}	     						  {return FOR;}
{RETURN}       				                  {return RETURN;}
{BREAK}	     						  {return BREAK;}
{PRINT}	     					          {return PRINT;}
{READINT}						  {return READINT;}
{READLINE}						  {return READLINE;}
{NEW}							  {return NEW;}
{NEWARRAY}						  {return NEWARRAY;}
{POINT}							  {return POINT;}
{OPENSQR}						  {return OPENSQR;}
{CLOSESQR}						  {return CLOSESQR;}
{INTCONST}						  {return INTCONST;}
{DOUBLECONST}						  {return DOUBLECONST;}
{BOOLCONST}						  {return BOOLCONST;}
{STRCONST}						  {return STRCONST;}
{Null}						  	  {return Null;}
{DIGIT}+                                           	  {yylval.int_val = atoi(yytext);return INT;}
{HEX}							  {yylval.str_val = new string(yytext);return HEX;}
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?                        {yylval.double_val = atof(yytext);return FLOAT;}
{ID}					                  {return IDENTIFIER;}
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT})                 {return S_COMMENT;}

\"{BODY_STRING}\"                                         {return STRING;}
{TAG}+						  	  ;


%%
void  yyerror(char* str) {
    printf("Parse  Error: \n%s\n",str );
}
int  yywrap(void) {}
int  main(int  num_args , char** args) {
#if YYDEBUG == 1
 extern int yydebug;
yydebug = 1;
#endif
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
