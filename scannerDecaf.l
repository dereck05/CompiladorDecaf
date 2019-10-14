%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include  <string.h>


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
TAG          (\t"|"\r"|"\\")
JUMP         ("\n")
BODY_STRING  ([^"\n])*
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

{BOOLEAN}						  {addRow(yylineno,yyleng,"BOOLEAN",yytext);
                        return BOOLEAN;}
{OP_REL}              {addRow(yylineno,yyleng,"OP_REL",yytext);
                        return OP_REL;}
{OP_LOG}        			{addRow(yylineno,yyleng,"OP_LOG",yytext);
                        return OP_LOG;}
{OP_ALG}              {addRow(yylineno,yyleng,"OP_ALG",yytext);
                        return OP_ALG;}
{NOT}							    {addRow(yylineno,yyleng,"NOT",yytext);
                        return NOT;}
{SEMICOLON}						{addRow(yylineno,yyleng,"SEMICOLON",yytext);
                        return SEMICOLON;}
{TYPE}							  {addRow(yylineno,yyleng,"TYPE",yytext);
                        return TYPE;}
{SQRBRACKET}					{addRow(yylineno,yyleng,"SQRBRACKET",yytext);
                        return SQRBRACKET;}
{EQUALS}						  {addRow(yylineno,yyleng,"EQUALS",yytext);
                        return EQUALS;}
{OPENPAR}						  {addRow(yylineno,yyleng,"OPENPAR",yytext);
                        return OPENPAR;}
{CLOSEPAR}						{addRow(yylineno,yyleng,"CLOSEPAR",yytext);
                        return CLOSEPAR;}
{OPENBRA}						  {addRow(yylineno,yyleng,"OPENBRA",yytext);
                        return OPENBRA;}
{CLOSEBRA}						{addRow(yylineno,yyleng,"CLOSEBRA",yytext);
                        return CLOSEBRA;}
{VOID}							  {addRow(yylineno,yyleng,"VOID",yytext);
                        return VOID;}
{COMMA}							  {addRow(yylineno,yyleng,"COMMA",yytext);
                        return COMMA;}
{CLASS}	     				  {addRow(yylineno,yyleng,"CLASS",yytext);
                        return CLASS;}
{EXTENDS}     			  {addRow(yylineno,yyleng,"EXTENDS",yytext);
                        return EXTENDS;}
{IMPLEMENTS}      		{addRow(yylineno,yyleng,"IMPLEMENTS",yytext);
                        return IMPLEMENTS;}
{INTERFACE}    				{addRow(yylineno,yyleng,"INTERFACE",yytext);
                        return INTERFACE;}
{THIS}							  {addRow(yylineno,yyleng,"THIS",yytext);
                        return THIS;}
{IF} 	     						{addRow(yylineno,yyleng,"IF",yytext);
                        return IF;}
{ELSE}         				{addRow(yylineno,yyleng,"ELSE",yytext);
                        return ELSE;}
{WHILE}        			  {addRow(yylineno,yyleng,"WHILE",yytext);
                        return WHILE;}
{FOR}	     					  {addRow(yylineno,yyleng,"THIS",yytext);
                        return FOR;}
{RETURN}       				{addRow(yylineno,yyleng,"RETURN",yytext);
                        return RETURN;}
{BREAK}	     				  {addRow(yylineno,yyleng,"BREAK",yytext);
                        return BREAK;}
{PRINT}	     					{addRow(yylineno,yyleng,"PRINT",yytext);
                        return PRINT;}
{READINT}						  {addRow(yylineno,yyleng,"READINT",yytext);
                        return READINT;}
{READLINE}						{addRow(yylineno,yyleng,"READLINE",yytext);
                        return READLINE;}
{NEW}							    {addRow(yylineno,yyleng,"NEW",yytext);
                        return NEW;}
{NEWARRAY}					  {addRow(yylineno,yyleng,"NEWARRAY",yytext);
                        return NEWARRAY;}
{POINT}							  {addRow(yylineno,yyleng,"THIS",yytext);
                        return POINT;}
{OPENSQR}						  {addRow(yylineno,yyleng,"OPENSQR",yytext);
                        return OPENSQR;}
{CLOSESQR}						{addRow(yylineno,yyleng,"CLOSESQR",yytext);
                        return CLOSESQR;}
{INTCONST}						{addRow(yylineno,yyleng,"INTCONST",yytext);
                        return INTCONST;}
{DOUBLECONST}					{addRow(yylineno,yyleng,"DOUBLECONST",yytext);
                        return DOUBLECONST;}
{BOOLCONST}						{addRow(yylineno,yyleng,"BOOLCONST",yytext);
                        return BOOLCONST;}
{STRCONST}						{addRow(yylineno,yyleng,"STRCONST",yytext);
                        return STRCONST;}
{Null}						  	{addRow(yylineno,yyleng,"NULL",yytext);
                        return Null;}
{DIGIT}+              {addRow(yylineno,yyleng,"INT",yytext);
                        yylval.int_val = atoi(yytext);
                        return INT;}
{HEX}							  {addRow(yylineno,yyleng,"HEX",yytext);
                        yylval.str_val = new string(yytext);
                        return HEX;}
{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?        {addRow(yylineno,yyleng,"FLOAT",yytext);
                                            yylval.double_val = atof(yytext);
                                            return FLOAT;}
{ID}   					                          {addRow(yylineno,yyleng,"IDENTIFIER",yytext);
                                            return IDENTIFIER;}
("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT}) {num_caracteres+=yyleng;
                                            }
{JUMP}                                    {num_caracteres=1;}
\"{BODY_STRING}\"                         {addRow(yylineno,yyleng,"STRING",yytext);
                                            return STRING;}
\"{BODY_STRING}                            {printf("STRING no cerrado en linea %d y columna %d\n",yylineno,num_caracteres);
                                            }
{TAG}+                                    {num_caracteres+=yyleng;}
.           				                      {printf("Caracter ilegal <%s> en linea %d y columna %d\n",yytext,yylineno,num_caracteres);
                                             num_caracteres+=yyleng;}//token ilegal

%%
void  yyerror(char* str) {
    printf("Parse  Error: \n%s\n",str );
}
int  yywrap(void) {}

void addRow(int line, int len, char* token, char* value){
      tableInt[num_words][0]=line;
      tableInt[num_words][1]=num_caracteres;
      table[num_words][0]=token;
      table[num_words][1]=value;
      num_words++;
      num_caracteres+=len;
}

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
