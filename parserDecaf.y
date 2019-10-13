%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include  <iostream>
#define YYSTYPE treeNode *
#define NOTHING -1 //Constante nombrada de un valor nulo del arbol
//#define YYSTYPE BINARY_TREE
using  namespace  std;
extern void yyerror(char *);
extern int yylex();

enum ParseTreeNodeType {PROGRAM,DECLS};

//Estructura del arbol
struct treeNode
{
    int item;
    int nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
};

typedef struct treeNode TREE_NODE;
typedef TREE_NODE  *BINARY_TREE;

//Metodos declarados para construir el arbol 
int evaluate(BINARY_TREE);
BINARY_TREE create_node(int, int,BINARY_TREE,BINARY_TREE);

%}

%union{
    int int_val;
    double double_val;
    string* str_val;
    //BINARY_TREE b_Val;
}


%token <int_val> INT
%token <double_val> FLOAT
%token <str_val> BOOLEAN OP_REL OP_LOG OP_ALG SYMBOL IDENTIFIER S_COMMENT OPEN_STRING STRING HEX TYPE SQRBRACKET TAG SEMICOLON OPENPAR CLOSEPAR VOID COMMA CLASS EXTENDS IMPLEMENTS INTERFACE IF ELSE WHILE FOR RETURN BREAK PRINT OPENBRA CLOSEBRA EQUALS THIS NOT READINT READLINE NEW NEWARRAY POINT OPENSQR CLOSESQR INTCONST DOUBLECONST BOOLCONST STRCONST Null
//%type<b_Val> Decls
%start Program

%%
Program : Decls 
	{ BINARY_TREE ParseTree; 
		ParseTree = create_node(NOTHING,PROGRAM ,NULL,NULL); }
	;

Decls: Decl //{printf("%s\n","Declaration");} 
	{$$ = create_node(NOTHING,DECLS ,NULL,NULL); }
	| Decls Decl ;

Decl : VariableDecl {printf("%s\n","Variable Declaration");}| FunctionDecl {printf("%s\n","Function Declaration");}| ClassDecl {printf("%s\n","Class Declaration");}| InterfaceDecl {printf("%s\n","Interface Declaration");};

VariableDecl: Variable SEMICOLON;  

Variable: TYPE IDENTIFIER | TYPE SQRBRACKET IDENTIFIER ;//int x;  o int[] x;

FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock | VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock ;

Formals: /*empty*/ | CommaVariables;

CommaVariables: CommaVarList | CommaVariables CommaVarList;

CommaVarList: Variable | CommaVarList COMMA Variable;

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA 
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA 
	  ;

CommaIdentifiers: CommaIdentList | CommaIdentifiers CommaIdentList;

CommaIdentList: IDENTIFIER | CommaIdentList COMMA IDENTIFIER;

Fields: /*empty*/
      |
      Fields Field;

Field: VariableDecl | FunctionDecl;

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA;

Prototypes: /*empty*/
	  | Prototypes Prototype;

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON | VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {printf("%s\n","Prototype");}; 

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {printf("%s\n","Statement Block");}; 

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl;

Stmts: /*empty*/
     | Stmts Stmt {printf("%s\n","Statements");};

Stmt : Expresions| IfStmt | WhileStmt | ForStmt | BreakStmt | ReturnStmt| PrintStmt | StmtBlock {printf("%s\n","Statement");};

Expresions:/*empty*/
	  | Expresion SEMICOLON;

IfStmt: 
      IF OPENPAR Expresion CLOSEPAR Stmt
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt;

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt;

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR;

ForExpresion: /*empty*/
	    | Expresion;

ReturnStmt: RETURN ReturnExpresion SEMICOLON;

ReturnExpresion: /*empty*/
	       | Expresion;

BreakStmt: BREAK SEMICOLON;

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {printf("%s\n","Print Statement");};

CommaExpresions: CommaExpList | CommaExpresions CommaExpList {printf("%s\n","Expresions");};

CommaExpList: Expresion | CommaExpList COMMA Expresion {printf("%s\n","ExpresionsList");};

Expresion: LValue EQUALS Expresion | Constant | LValue | THIS | Call | OPENPAR
Expresion CLOSEPAR | Expresion OP_ALG Expresion | Expresion OP_REL Expresion |Expresion OP_LOG Expresion| NOT Expresion|READINT OPENPAR CLOSEPAR|READLINE OPENPAR CLOSEPAR| NEW OPENPAR IDENTIFIER CLOSEPAR| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR ;

LValue: IDENTIFIER| Expresion POINT IDENTIFIER| Expresion OPENSQR Expresion CLOSESQR {printf("%s\n","LValue");};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {printf("%s\n","Call");};

Actuals: /*empty*/
       | CommaExpresions {printf("%s\n","Expresions");};

Constant: INT | FLOAT | BOOLEAN | STRING| Null {printf("%s\n","Constant");};

%%

BINARY_TREE create_node(int int_val,int case_identifier, BINARY_TREE n1, BINARY_TREE n2)
{
	BINARY_TREE t;
	t = (BINARY_TREE)malloc(sizeof(TREE_NODE));
	t->item =int_val;
	t->first=n1;
	t->second=n2;
	return(t);
}


