%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include  <string.h>
#include <vector>
#include "VarObject.h"
using  namespace  std;
#include "Nodo.h"

#include "parserDecaf.tab.h"   //  output  of  bison on  example1.y

void yyerror(const char *);
int  yyparse(void);
void addRow(int len, const char *token, char *value);
void printTable();
int num_words = 0;
int num_caracteres = 1;
int num_lines=1;
int tableInt[1000][2];
const char* table[1000][2];

%}


DIGIT 		   [0-9]
ID       	   [a-zA-Z][a-zA-Z0-9_]{0,30}
AF    		   [a-f|A-F]
E_ATOM		   (n|t|r|\)
STRESC		   ["\"{E_ATOM}]
HEX   		   0[x|X]({DIGIT}|{AF})+
NOSTR   	   [^{STRESC}|\n|\"]
BEGINCOMMENT 	   [/*]
ENDCOMMENT	   [*/]
TAG          [ \t\r\\]
JUMP         ("\n")
BODY_STRING  ([^"\n])*
OP_REL       (">="|"<="|">"|"<")
OP_IGUALDAD  ("=="|"!=")
BOOLEAN	     (True|False)
BAD_STR      ([^r|^t|^n])*
LOG_AND      ("&&")
LOG_OR	     ("||")
NOT 	     ("!")
SUM_RESTA    ("+"|"-")
MUL_DIV_MOD  ("/"|"*"|"%")
SEMICOLON    (";")
TYPE	     (int|double|bool|string)
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



{BOOLEAN}				   {addRow(yyleng,"BOOLEAN",yytext);return BOOLEAN;}

{OP_REL}              			   {addRow(yyleng,"OP_REL",yytext);return OP_REL;}

{OP_IGUALDAD}              		   {addRow(yyleng,"OP_IGUALDAD",yytext);return OP_IGUALDAD;}

{SUM_RESTA}        			   {addRow(yyleng,"SUM_RESTA",yytext);return SUM_RESTA;}

{MUL_DIV_MOD}        			   {addRow(yyleng,"MUL_DIV_MOD",yytext);return MUL_DIV_MOD;}

{LOG_AND}              			   {addRow(yyleng,"LOG_AND",yytext);return LOG_AND;}

{LOG_OR}              			   {addRow(yyleng,"LOG_OR",yytext);return LOG_OR;}

{NOT}					   {addRow(yyleng,"NOT",yytext);return NOT;}

{SEMICOLON}				   {addRow(yyleng,"SEMICOLON",yytext);return SEMICOLON;}

{TYPE}					   {addRow(yyleng,"TYPE",yytext);return TYPE;}

{SQRBRACKET}				   {addRow(yyleng,"SQRBRACKET",yytext);return SQRBRACKET;}

{EQUALS}				   {addRow(yyleng,"EQUALS",yytext);return EQUALS;}

{OPENPAR}				   {addRow(yyleng,"OPENPAR",yytext);return OPENPAR;}

{CLOSEPAR}				   {addRow(yyleng,"CLOSEPAR",yytext);return CLOSEPAR;}

{OPENBRA}				   {addRow(yyleng,"OPENBRA",yytext);return OPENBRA;}

{CLOSEBRA}				   {addRow(yyleng,"CLOSEBRA",yytext);return CLOSEBRA;}

{VOID}					   {addRow(yyleng,"VOID",yytext);return VOID;}

{COMMA}					   {addRow(yyleng,"COMMA",yytext);return COMMA;}

{CLASS}	     				   {addRow(yyleng,"CLASS",yytext);return CLASS;}

{EXTENDS}     			  	   {addRow(yyleng,"EXTENDS",yytext);return EXTENDS;}

{IMPLEMENTS}      			   {addRow(yyleng,"IMPLEMENTS",yytext);return IMPLEMENTS;}

{INTERFACE}    				   {addRow(yyleng,"INTERFACE",yytext);return INTERFACE;}

{THIS}					   {addRow(yyleng,"THIS",yytext);return THIS;}

{IF} 	     				   {addRow(yyleng,"IF",yytext);return IF;}

{ELSE}         				   {addRow(yyleng,"ELSE",yytext);return ELSE;}

{WHILE}        			  	   {addRow(yyleng,"WHILE",yytext);return WHILE;}

{FOR}	     			 	   {addRow(yyleng,"THIS",yytext);return FOR;}

{RETURN}       				   {addRow(yyleng,"RETURN",yytext);return RETURN;}

{BREAK}	     				   {addRow(yyleng,"BREAK",yytext);return BREAK;}

{PRINT}	     				   {addRow(yyleng,"PRINT",yytext);return PRINT;}

{READINT}				   {addRow(yyleng,"READINT",yytext);return READINT;}

{READLINE}				   {addRow(yyleng,"READLINE",yytext);return READLINE;}

{NEW}					   {addRow(yyleng,"NEW",yytext);return NEW;}

{NEWARRAY}			           {addRow(yyleng,"NEWARRAY",yytext);return NEWARRAY;}

{POINT}					   {addRow(yyleng,"THIS",yytext);return POINT;}

{OPENSQR}				   {addRow(yyleng,"OPENSQR",yytext);return OPENSQR;}

{CLOSESQR}				   {addRow(yyleng,"CLOSESQR",yytext);return CLOSESQR;}

{INTCONST}				   {addRow(yyleng,"INTCONST",yytext);return INTCONST;}

{DOUBLECONST}				   {addRow(yyleng,"DOUBLECONST",yytext);return DOUBLECONST;}

{BOOLCONST}				   {addRow(yyleng,"BOOLCONST",yytext);return BOOLCONST;}

{STRCONST}				   {addRow(yyleng,"STRCONST",yytext);return STRCONST;}

{Null}				           {addRow(yyleng,"NULL",yytext);return Null;}

{DIGIT}+              			   {addRow(yyleng,"INT",yytext);yylval.int_val = atoi(yytext);return INT;}

{HEX}					   {addRow(yyleng,"HEX",yytext);yylval.str_val = new string(yytext);return HEX;}

{DIGIT}+"."{DIGIT}+(E"+"{DIGIT}+)?         {addRow(yyleng,"FLOAT",yytext);yylval.double_val = atof(yytext);return FLOAT;}

{ID}   					   {addRow(yyleng,"IDENTIFIER",yytext);return IDENTIFIER;}

("//".*)|({BEGINCOMMENT}(.*){ENDCOMMENT})  {num_caracteres+=yyleng;}

{JUMP}                                     {num_caracteres=1; num_lines++;}

\"{BAD_STR}\"			           {printf("Secuencia de escape ilegal en linea %d y columna %d\n",num_lines,num_caracteres);num_caracteres+=yyleng;exit(0);}

\"{BODY_STRING}\"                          {addRow(yyleng,"STRING",yytext);return STRING;}

\"{BODY_STRING}                            {printf("STRING no cerrado en linea %d y columna %d\n",num_lines,num_caracteres);exit(0);}



{TAG}+                                     {num_caracteres+=yyleng;}

.           				   {printf("Caracter ilegal <%s> en linea %d y columna %d\n",yytext,num_lines,num_caracteres);num_caracteres+=yyleng;exit(0);}//token ilegal

%%
void  yyerror(const char* str) {
    printf("Parsing error en linea %d , columna %d\n",num_lines,num_caracteres);
    exit(0);
}
int  yywrap(void) {}

void addRow(int len, const char *token, char *value){
      char *str = (char*)malloc(strlen(value)+1);
      if(str != NULL) strcpy(str,value);

      tableInt[num_words][0]=num_lines;
      tableInt[num_words][1]=num_caracteres;
      table[num_words][0]=token;
      table[num_words][1]=str;
      num_words++;
      num_caracteres+=len;
}

void printTable(){
  printf("\nLine     Column     Token           Value\n");
  for(int i=0; i<num_words;i++){
      printf("%d       ",tableInt[i][0]);
      if(tableInt[i][0]<10)printf(" ");
      printf("%d       ",tableInt[i][1]);
      if(tableInt[i][1]<10)printf(" ");
      printf("%s     ",table[i][0]);
      for(int j=0;j<(11-strlen(table[i][0]));j++){
        printf(" ");
      }
      printf("%s\n",table[i][1]);
  }
}

int  main(int  num_args , char** args) {
#if YYDEBUG == 1
 extern int yydebug;
yydebug = 1;
#endif
    if(num_args != 2) {
        printf("usage: ./ parser1  filename\n");
        exit (0);}FILE* file = fopen(args[1],"r");
        if(file == NULL) {
            printf("couldn ’t open %s\n", args [1]);
            exit (0);
        }
        yyin = file;   // now  flex  reads  from  file
        yyparse ();
        //printTable();
        fclose(file);
}
