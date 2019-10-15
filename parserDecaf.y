%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <vector>
#include  <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stdc++.h>

#include "Nodo.h"
using  namespace  std;
extern void yyerror(const char *);
extern int yylex();
extern int yylineno;
extern int num_lines;
extern int num_caracteres;
static void createNode(Nodo *n);
static void readVector();
static void makeDirectory(string nombre);

%}


%union{
    int int_val;
    double double_val;
    string* str_val;

}


%token <int_val> INT
%token <double_val> FLOAT
%token <str_val> BOOLEAN OP_REL OP_LOG OP_ALG SYMBOL IDENTIFIER S_COMMENT OPEN_STRING STRING HEX TYPE SQRBRACKET TAG SEMICOLON OPENPAR CLOSEPAR VOID COMMA CLASS EXTENDS IMPLEMENTS INTERFACE IF ELSE WHILE FOR RETURN BREAK PRINT OPENBRA CLOSEBRA EQUALS THIS NOT READINT READLINE NEW NEWARRAY POINT OPENSQR CLOSESQR INTCONST DOUBLECONST BOOLCONST STRCONST Null
%start Program

%%
Program : Decls {createNode(new Nodo("Program",num_lines,num_caracteres));readVector();}; 

Decls: Decl {createNode(new Nodo("Decls",num_lines,num_caracteres));}
	| Decls Decl {createNode(new Nodo("Decls",num_lines,num_caracteres));};

Decl : VariableDecl {createNode(new Nodo("Decl",num_lines,num_caracteres));}
	| FunctionDecl {createNode(new Nodo("Decl",num_lines,num_caracteres));}
	| ClassDecl {createNode(new Nodo("Decl",num_lines,num_caracteres)); }
	| InterfaceDecl {createNode(new Nodo("Decl",num_lines,num_caracteres));};

VariableDecl: Variable SEMICOLON {createNode(new Nodo("VariableDecl",num_lines,num_caracteres));};  

Variable: TYPE IDENTIFIER {createNode(new Nodo("Variable",num_lines,num_caracteres));}  
	 | TYPE SQRBRACKET IDENTIFIER {createNode(new Nodo("Variable",num_lines,num_caracteres));};   ;//int x;  o int[] x;

FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {createNode(new Nodo("FunctionDecl",num_lines,num_caracteres));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {createNode(new Nodo("FunctionDecl",num_lines,num_caracteres));}; 

Formals: /*empty*/ 
	| CommaVariables {createNode(new Nodo("Formals",num_lines,num_caracteres));};  


CommaVariables: CommaVarList {createNode(new Nodo("CommaVariables",num_lines,num_caracteres));}
	| CommaVariables CommaVarList {createNode(new Nodo("Comma Variables",num_lines,num_caracteres));};  

CommaVarList: Variable {createNode(new Nodo("CommaVarList",num_lines,num_caracteres));}
	| CommaVarList COMMA Variable {createNode(new Nodo("CommaVarList",num_lines,num_caracteres));};

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres));}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres));}
	  ;

CommaIdentifiers: CommaIdentList {createNode(new Nodo("CommaIdentifiers",num_lines,num_caracteres));}
	| CommaIdentifiers CommaIdentList {createNode(new Nodo("CommaIdentifiers",num_lines,num_caracteres));};

CommaIdentList: IDENTIFIER {createNode(new Nodo("CommaIdentList",num_lines,num_caracteres));}
	| CommaIdentList COMMA IDENTIFIER {createNode(new Nodo("CommaIdentList",num_lines,num_caracteres));};

Fields: /*empty*/
      |  Fields Field {createNode(new Nodo("Fields",num_lines,num_caracteres));};

Field: VariableDecl {createNode(new Nodo("Field",num_lines,num_caracteres));}
	| FunctionDecl {createNode(new Nodo("Field",num_lines,num_caracteres));};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {createNode(new Nodo("InterfaceDecl",num_lines,num_caracteres));};

Prototypes: /*empty*/
	  | Prototypes Prototype {createNode(new Nodo("Prototypes",num_lines,num_caracteres));};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",num_lines,num_caracteres));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",num_lines,num_caracteres));}; 

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {createNode(new Nodo("StmtBlock",num_lines,num_caracteres));}; 

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {createNode(new Nodo("VariableDecls",num_lines,num_caracteres));};

Stmts: /*empty*/
     | Stmts Stmt {createNode(new Nodo("Stmts",num_lines,num_caracteres));};

Stmt : Expresions
	| IfStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| WhileStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| ForStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| BreakStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| ReturnStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| PrintStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres));}
	| StmtBlock {createNode(new Nodo("Stmt",num_lines,num_caracteres));};

Expresions:/*empty*/
	  | Expresion SEMICOLON {createNode(new Nodo("Expressions",num_lines,num_caracteres));};

IfStmt: 
      IF OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("IFStmt",num_lines,num_caracteres));}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {createNode(new Nodo("IFStmt",num_lines,num_caracteres));};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("While Statement",num_lines,num_caracteres));};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR {createNode(new Nodo("ForStmt",num_lines,num_caracteres));};

ForExpresion: /*empty*/
	    | Expresion {createNode(new Nodo("ForExpression",num_lines,num_caracteres));};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {createNode(new Nodo("ReturnStmt",num_lines,num_caracteres));};

ReturnExpresion: /*empty*/
	       | Expresion {createNode(new Nodo("ReturnExpression",num_lines,num_caracteres));};

BreakStmt: BREAK SEMICOLON {createNode(new Nodo("BreakStmt",num_lines,num_caracteres));};

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {createNode(new Nodo("PrintStmt", num_lines, num_caracteres));};

CommaExpresions: CommaExpList {createNode(new Nodo("CommaExpressions",num_lines,num_caracteres));}
	| CommaExpresions CommaExpList {createNode(new Nodo("CommaExpressions",num_lines,num_caracteres));};

CommaExpList: Expresion {createNode(new Nodo("CommaExpList",num_lines,num_caracteres));}
	| CommaExpList COMMA Expresion {createNode(new Nodo("CommaExpList",num_lines,num_caracteres));};

Expresion: LValue EQUALS Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| Constant {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| LValue {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| THIS {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| Call {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| OPENPAR Expresion CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| Expresion OP_ALG Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| Expresion OP_REL Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| Expresion OP_LOG Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| NOT Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| READINT OPENPAR CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| READLINE OPENPAR CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres));}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres));};

LValue: IDENTIFIER {createNode(new Nodo("LValue",num_lines,num_caracteres));}
	| Expresion POINT IDENTIFIER {createNode(new Nodo("LValue",num_lines,num_caracteres));}
	| Expresion OPENSQR Expresion CLOSESQR {createNode(new Nodo("LValue",num_lines,num_caracteres));printf("%s\n","LValue");};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",num_lines,num_caracteres));}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",num_lines,num_caracteres));};

Actuals: /*empty*/
       | CommaExpresions {createNode(new Nodo("Actuals",num_lines,num_caracteres));};

Constant: INT {createNode(new Nodo("Constant",num_lines,num_caracteres));}
	| FLOAT {createNode(new Nodo("Constant",num_lines,num_caracteres));}
	| BOOLEAN {createNode(new Nodo("Constant",num_lines,num_caracteres));}
	| STRING {createNode(new Nodo("Constant",num_lines,num_caracteres));}
	| Null {createNode(new Nodo("Constant",num_lines,num_caracteres));};

%%

static vector<Nodo*> v ;

static void createNode(Nodo *n){
    v.push_back(n);
    //printf("%s\n","Inserted!");
}

static string path = "/home/natalia/Desktop/Pruebas";

static void makeDirectory(string nombre){
	path = path +"/"+ nombre;
	//printf("%s\n",path.c_str());	
	mkdir(path.c_str() ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

static void readVector(){
    for(int i =v.size()-1; i>=0; i--){
       printf("%s","fila:");
       printf("%d",v[i]->fila);
       printf("%s","  columna:");
       printf("%d",v[i]->columna);
       printf("%s","  nombre:");
       printf("%s\n",v[i]->nombre.c_str());
       makeDirectory(v[i]->nombre);
    }
}



