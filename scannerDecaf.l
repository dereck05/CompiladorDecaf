%{
#include<stdio.h>
#include  <cstdio>
#include  <cstdlib>
#include  <string.h>
#include  <string>
using  namespace  std;
#include "parserDecaf.tab.h"   //  output  of  bison on  example1.y
void yyerror(char *);
int  yyparse(void);
void addRow(int line, int len, char* token, char* value);

int num_words = 0, num_caracteres = 1;
int tableInt[1000][2];
string table[1000][2];

%}

DIGIT 		   [0-9]
ID       	   [a-zA-Z][a-zA-Z0-9_]{0,30}
AF    		   [a-f|A-F]
E_ATOM		   [n|t|\"|\\]
STRESC		   ["\"{E_ATOM}]
HEX   		   0[x|X]({DIGIT}|{AF})+
NOSTR   	   [^{STRESC}|\n|\"]
BEGINCOMMENT 	   [/*]
ENDCOMMENT	   [*/]
BLANK        [ \t\n]+
OP_REL       (">="|"<="|">"|"<"|"=="|"!="|"=")
OP_REL       (">="|"<="|">"|"<"|"=="|"!=")
OP_ALG       ("+"|"-"|"/"|"*"|"%")
TAG          (\t"|"\r"|"\\")
JUMP         ("\n")
BODY_STRING  ([^"\n])*
BOOLEAN	     (True|False)
NOT 	     ("!")
OP_LOG       ("&&"|"||")
NOT 	     ("!")
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
SYMBOL       (";"|","|"."|"["|"\]"|"{"|"}"|"("|")")
RESERVED     (void|string|this|while|break|ReadInteger|int|class|extends|if|New|ReadLine|double|interface|implements|else|NewArray|true|bool|null|for|return|Print|false)

%%
{BOOLEAN}						  { addRow(yylineno,yyleng,"BOOLEAN",yytex);
                        return BOOLEAN;}
{OP_REL}              {addRow(yylineno,yyleng,"OP_REL",yytex);
                        return OP_REL;}
{OP_LOG}        			{ addRow(yylineno,yyleng,"OP_LOG",yytex);
                        return OP_LOG;}
{OP_ALG}              {addRow(yylineno,yyleng,"OP_ALG",yytex);
                        return OP_ALG;}
{NOT}							    {addRow(yylineno,yyleng,"NOT",yytex);
                        return NOT;}
{SEMICOLON}						{addRow(yylineno,yyleng,"SEMICOLON",yytex);
                        return SEMICOLON;}
{TYPE}							  {addRow(yylineno,yyleng,"TYPE",yytex);
                        return TYPE;}
{SQRBRACKET}					{addRow(yylineno,yyleng,"SQRBRACKET",yytex);
                        return SQRBRACKET;}
{EQUALS}						  {addRow(yylineno,yyleng,"EQUALS",yytex);
                        return EQUALS;}
{OPENPAR}						  {addRow(yylineno,yyleng,"OPENPAR",yytex);
                        return OPENPAR;}
{CLOSEPAR}						{addRow(yylineno,yyleng,"CLOSEPAR",yytex);
                        return CLOSEPAR;}
{OPENBRA}						  {addRow(yylineno,yyleng,"OPENBRA",yytex);
                        return OPENBRA;}
{CLOSEBRA}						{addRow(yylineno,yyleng,"CLOSEBRA",yytex);
                        return CLOSEBRA;}
{VOID}							  {addRow(yylineno,yyleng,"VOID",yytex);
                        return VOID;}
{COMMA}							  {addRow(yylineno,yyleng,"COMMA",yytex);
                        return COMMA;}
{CLASS}	     				  {addRow(yylineno,yyleng,"CLASS",yytex);
                        return CLASS;}
{EXTENDS}     			  {addRow(yylineno,yyleng,"EXTENDS",yytex);
                        return EXTENDS;}
{IMPLEMENTS}      		{addRow(yylineno,yyleng,"IMPLEMENTS",yytex);
                        return IMPLEMENTS;}
{INTERFACE}    				{addRow(yylineno,yyleng,"INTERFACE",yytex);
                        return INTERFACE;}
{THIS}							  {addRow(yylineno,yyleng,"THIS",yytex);
                        return THIS;}
{IF} 	     						{addRow(yylineno,yyleng,"IF",yytex);
                        return IF;}
{ELSE}         				{addRow(yylineno,yyleng,"ELSE",yytex);
                        return ELSE;}
{WHILE}        			  {addRow(yylineno,yyleng,"WHILE",yytex);
                        return WHILE;}
{FOR}	     					  {addRow(yylineno,yyleng,"THIS",yytex);
                        return FOR;}
{RETURN}       				{addRow(yylineno,yyleng,"RETURN",yytex);
                        return RETURN;}
{BREAK}	     				  {addRow(yylineno,yyleng,"BREAK",yytex);
                        return BREAK;}
{PRINT}	     					{addRow(yylineno,yyleng,"PRINT",yytex);
                        return PRINT;}
{READINT}						  {addRow(yylineno,yyleng,"READINT",yytex);
                        return READINT;}
{READLINE}						{addRow(yylineno,yyleng,"READLINE",yytex);
                        return READLINE;}
{NEW}							    {addRow(yylineno,yyleng,"NEW",yytex);
                        return NEW;}
{NEWARRAY}					  {addRow(yylineno,yyleng,"NEWARRAY",yytex);
                        return NEWARRAY;}
{POINT}							  {addRow(yylineno,yyleng,"THIS",yytex);
                        return POINT;}
{OPENSQR}						  {addRow(yylineno,yyleng,"OPENSQR",yytex);
                        return OPENSQR;}
{CLOSESQR}						{addRow(yylineno,yyleng,"CLOSESQR",yytex);
                        return CLOSESQR;}
{INTCONST}						{addRow(yylineno,yyleng,"INTCONST",yytex);
                        return INTCONST;}
{DOUBLECONST}					{addRow(yylineno,yyleng,"DOUBLECONST",yytex);
                        return DOUBLECONST;}
{BOOLCONST}						{addRow(yylineno,yyleng,"BOOLCONST",yytex);
                        return BOOLCONST;}
{STRCONST}						{addRow(yylineno,yyleng,"STRCONST",yytex);
                        return STRCONST;}
{Null}						  	{addRow(yylineno,yyleng,"NULL",yytex);
                        return Null;}
{DIGIT}+              {addRow(yylineno,yyleng,"INT",yytex);
                        yylval.int_val = atoi(yytext);
                        return INT;}
{HEX}							  {addRow(yylineno,yyleng,"HEX",yytex);
                        yylval.str_val = new string(yytext);
                        return HEX;}
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?        {addRow(yylineno,yyleng,"FLOAT",yytex);
                                            yylval.double_val = atof(yytext);
                                            return FLOAT;}
{ID}   					                          {addRow(yylineno,yyleng,"IDENTIFIER",yytex);
                                            return IDENTIFIER;}
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT}) {num_caracteres+=yyleng;
                                            }
{JUMP}                                    {num_caracteres=1;}
\"{BODY_STRING}\"                         {addRow(yylineno,yyleng,"STRING",yytex);
                                            return STRING;}
\"{BODY_STRING}                            {printf("STRING no cerrado en linea %d y columna %d\n",yylineno,num_caracteres);
                                            }
{TAG}+                                    {num_caracteres+=yyleng;}
.           				                      {printf("Caracter ilegal <%s> en linea %d y columna %d\n",yytex,yylineno,num_caracteres);
                                             num_caracteres+=yyleng;}//token ilegal

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


void addRow(int line, int len, char* token, char* value){
      tableInt[num_words][0]=line;
      tableInt[num_words][1]=num_caracteres;
      table[num_words][0]=token;
      table[num_words][1]=value;
      num_words++;
      num_caracteres+=len;
}
