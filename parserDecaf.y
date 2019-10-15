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
Program : Decls {createNode(new Nodo("Program",1,2));printf("%s\n","PROGRAM");readVector();}; 

Decls: Decl {createNode(new Nodo("Declaration",2,2));printf("%s\n","Declaration");}
	| Decls Decl {createNode(new Nodo("Declarations Declaration",3,2));};

Decl : VariableDecl {createNode(new Nodo("Variable Declaration",3,2)); printf("%s\n","Variable Declaration");}
	| FunctionDecl {createNode(new Nodo("Function Declaration",3,2)); printf("%s\n","Function Declaration");}
	| ClassDecl {createNode(new Nodo("Class Declaration",3,2)); printf("%s\n","Class Declaration");}
	| InterfaceDecl {createNode(new Nodo("Interface Declaration",3,2)); printf("%s\n","Interface Declaration");};

VariableDecl: Variable SEMICOLON {createNode(new Nodo("Variable SEMICOLON",3,2));};  

Variable: TYPE IDENTIFIER {createNode(new Nodo("TYPE IDENTIFIER",3,2));}  
	 | TYPE SQRBRACKET IDENTIFIER {createNode(new Nodo("TYPE SQRBRACKET IDENTIFIER",3,2));};   ;//int x;  o int[] x;

FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {createNode(new Nodo("TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock",3,2));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {createNode(new Nodo("VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock",3,2));}; 

Formals: /*empty*/ 
	| CommaVariables {createNode(new Nodo("CommaVariables",3,2));};  


CommaVariables: CommaVarList {createNode(new Nodo("CommaVarList",3,2));}
	| CommaVariables CommaVarList {createNode(new Nodo("CommaVariables CommaVarList",3,2));};  

CommaVarList: Variable {createNode(new Nodo("Variable",3,2));}
	| CommaVarList COMMA Variable {createNode(new Nodo("CommaVarList COMMA Variable",3,2));};

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("CLASS IDENTIFIER OPENBRA Fields CLOSEBRA",3,2));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA",3,2));}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA",3,2));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA",3,2));}
	  ;

CommaIdentifiers: CommaIdentList {createNode(new Nodo("CommaIdentList",3,2));}
	| CommaIdentifiers CommaIdentList {createNode(new Nodo("CommaIdentifiers CommaIdentList",3,2));};

CommaIdentList: IDENTIFIER {createNode(new Nodo("IDENTIFIER",3,2));}
	| CommaIdentList COMMA IDENTIFIER {createNode(new Nodo("CommaIdentList COMMA IDENTIFIER",3,2));};

Fields: /*empty*/
      |  Fields Field {createNode(new Nodo("Fields Field",3,2));};

Field: VariableDecl {createNode(new Nodo("VariableDecl",3,2));}
	| FunctionDecl {createNode(new Nodo("FunctionDecl",3,2));};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {createNode(new Nodo("INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA",3,2));};;

Prototypes: /*empty*/
	  | Prototypes Prototype {createNode(new Nodo("Prototypes Prototype",3,2));};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON",3,2));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON",3,2));printf("%s\n","Prototype");}; 

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {createNode(new Nodo("OPENBRA VariableDecls Stmts CLOSEBRA",3,2));printf("%s\n","Statement Block");}; 

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {createNode(new Nodo("VariableDecls VariableDecl",3,2));};

Stmts: /*empty*/
     | Stmts Stmt {createNode(new Nodo("Stmts Stmt",3,2));printf("%s\n","Statements");};

Stmt : Expresions
	| IfStmt {createNode(new Nodo("IfStmt",3,2));}
	| WhileStmt {createNode(new Nodo("WhileStmt",3,2));}
	| ForStmt {createNode(new Nodo("ForStmt",3,2));}
	| BreakStmt {createNode(new Nodo("BreakStmt",3,2));}
	| ReturnStmt {createNode(new Nodo("ReturnStmt",3,2));}
	| PrintStmt {createNode(new Nodo("PrintStmt",3,2));}
	| StmtBlock {createNode(new Nodo("StmtBlock",3,2));printf("%s\n","Statement");};

Expresions:/*empty*/
	  | Expresion SEMICOLON {createNode(new Nodo("Expresion SEMICOLON",3,2));};

IfStmt: 
      IF OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("IF OPENPAR Expresion CLOSEPAR Stmt",3,2));}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {createNode(new Nodo("IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt",3,2));};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("WHILE OPENPAR Expresion CLOSEPAR Stmt",3,2));};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR {createNode(new Nodo("FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR",3,2));};

ForExpresion: /*empty*/
	    | Expresion {createNode(new Nodo("Expresion",3,2));};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {createNode(new Nodo("RETURN ReturnExpresion SEMICOLON",3,2));};

ReturnExpresion: /*empty*/
	       | Expresion {createNode(new Nodo("Expresion",3,2));};

BreakStmt: BREAK SEMICOLON {createNode(new Nodo("BREAK SEMICOLON",3,2));};

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {createNode(new Nodo("PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON",3,2));printf("%s\n","Print Statement");};

CommaExpresions: CommaExpList {createNode(new Nodo("CommaExpList",3,2));}
	| CommaExpresions CommaExpList {createNode(new Nodo("CommaExpresions CommaExpList",3,2));printf("%s\n","Expresions");};

CommaExpList: Expresion {createNode(new Nodo("Expresion",3,2));}
	| CommaExpList COMMA Expresion {createNode(new Nodo("CommaExpList COMMA Expresion",3,2));printf("%s\n","ExpresionsList");};

Expresion: LValue EQUALS Expresion {createNode(new Nodo("LValue EQUALS Expresion",3,2));}
	| Constant {createNode(new Nodo("Constant",3,2));}
	| LValue {createNode(new Nodo("LValue",3,2));}
	| THIS {createNode(new Nodo("THIS",3,2));}
	| Call {createNode(new Nodo("Call",3,2));}
	| OPENPAR Expresion CLOSEPAR {createNode(new Nodo("OPENPAR Expresion CLOSEPAR",3,2));}
	| Expresion OP_ALG Expresion {createNode(new Nodo("Expresion OP_ALG Expresion",3,2));}
	| Expresion OP_REL Expresion {createNode(new Nodo("Expresion OP_REL Expresion",3,2));}
	| Expresion OP_LOG Expresion {createNode(new Nodo("Expresion OP_LOG Expresion",3,2));}
	| NOT Expresion {createNode(new Nodo("NOT Expresion",3,2));}
	| READINT OPENPAR CLOSEPAR {createNode(new Nodo("READINT OPENPAR CLOSEPAR",3,2));}
	| READLINE OPENPAR CLOSEPAR {createNode(new Nodo("READLINE OPENPAR CLOSEPAR",3,2));}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {createNode(new Nodo("NEW OPENPAR IDENTIFIER CLOSEPAR",3,2));}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {createNode(new Nodo("NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR",3,2));};

LValue: IDENTIFIER {createNode(new Nodo("IDENTIFIER",3,2));}
	| Expresion POINT IDENTIFIER {createNode(new Nodo("Expresion POINT IDENTIFIER",3,2));}
	| Expresion OPENSQR Expresion CLOSESQR {createNode(new Nodo("Expresion OPENSQR Expresion CLOSESQR",3,2));printf("%s\n","LValue");};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("IDENTIFIER OPENPAR Actuals CLOSEPAR",3,2));}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR",3,2));printf("%s\n","Call");};

Actuals: /*empty*/
       | CommaExpresions {createNode(new Nodo("CommaExpresions",3,2));printf("%s\n","Expresions");};

Constant: INT {createNode(new Nodo("INT",3,2));}
	| FLOAT {createNode(new Nodo("FLOAT",3,2));}
	| BOOLEAN {createNode(new Nodo("BOOLEAN",3,2));}
	| STRING {createNode(new Nodo("STRING",3,2));}
	| Null {createNode(new Nodo("Null",3,2));printf("%s\n","Constant");};


%%

static vector<Nodo*> v ;

static void createNode(Nodo *n){
    v.push_back(n);
    printf("%s\n","Inserted!");
}

static string path = "/home/natalia/Desktop/Pruebas";

static void makeDirectory(string nombre){
	path = path +"/"+ nombre;
	printf("%s\n",path.c_str());	
	mkdir(path.c_str() ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

static void readVector(){
    for(int i =v.size()-1; i>=0; i--){
       printf("%d\n",v[i]->fila);
       makeDirectory(v[i]->nombre);
    }
}



