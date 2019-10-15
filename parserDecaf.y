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

Decls: Decl {createNode(new Nodo("Declarations",2,2));printf("%s\n","Declaration");}
	| Decls Decl {createNode(new Nodo("Declarations",3,2));};

Decl : VariableDecl {createNode(new Nodo("Variable Declaration",3,2)); printf("%s\n","Variable Declaration");}
	| FunctionDecl {createNode(new Nodo("Function Declaration",3,2)); printf("%s\n","Function Declaration");}
	| ClassDecl {createNode(new Nodo("Class Declaration",3,2)); printf("%s\n","Class Declaration");}
	| InterfaceDecl {createNode(new Nodo("Interface Declaration",3,2)); printf("%s\n","Interface Declaration");};

VariableDecl: Variable SEMICOLON {createNode(new Nodo("Variable SEMICOLON",3,2));};  

Variable: TYPE IDENTIFIER {createNode(new Nodo("Variable",3,2));}  
	 | TYPE SQRBRACKET IDENTIFIER {createNode(new Nodo("Variable",3,2));};   ;//int x;  o int[] x;

FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {createNode(new Nodo("Function Declaration",3,2));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {createNode(new Nodo("Function Declaration",3,2));}; 

Formals: /*empty*/ 
	| CommaVariables {createNode(new Nodo("Formals",3,2));};  


CommaVariables: CommaVarList {createNode(new Nodo("Comma Variables",3,2));}
	| CommaVariables CommaVarList {createNode(new Nodo("Comma Variables",3,2));};  

CommaVarList: Variable {createNode(new Nodo("Comma Variables List",3,2));}
	| CommaVarList COMMA Variable {createNode(new Nodo("Comma Variables List",3,2));};

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("Class Declaration",3,2));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("Class Declaration",3,2));}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("Class Declaration",3,2));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("Class Declaration",3,2));}
	  ;

CommaIdentifiers: CommaIdentList {createNode(new Nodo("Comma Identifiers",3,2));}
	| CommaIdentifiers CommaIdentList {createNode(new Nodo("Comma Identifiers",3,2));};

CommaIdentList: IDENTIFIER {createNode(new Nodo("Comma Identifiers List",3,2));}
	| CommaIdentList COMMA IDENTIFIER {createNode(new Nodo("Comma Identifiers List",3,2));};

Fields: /*empty*/
      |  Fields Field {createNode(new Nodo("Fields",3,2));};

Field: VariableDecl {createNode(new Nodo("Field",3,2));}
	| FunctionDecl {createNode(new Nodo("Field",3,2));};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {createNode(new Nodo("Interface Declaration",3,2));};;

Prototypes: /*empty*/
	  | Prototypes Prototype {createNode(new Nodo("Prototypes",3,2));};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",3,2));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",3,2));printf("%s\n","Prototype");}; 

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {createNode(new Nodo("Statement Block",3,2));printf("%s\n","Statement Block");}; 

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {createNode(new Nodo("Variable Declarations",3,2));};

Stmts: /*empty*/
     | Stmts Stmt {createNode(new Nodo("Statements",3,2));printf("%s\n","Statements");};

Stmt : Expresions
	| IfStmt {createNode(new Nodo("Statement",3,2));}
	| WhileStmt {createNode(new Nodo("Statement",3,2));}
	| ForStmt {createNode(new Nodo("Statement",3,2));}
	| BreakStmt {createNode(new Nodo("Statement",3,2));}
	| ReturnStmt {createNode(new Nodo("Statement",3,2));}
	| PrintStmt {createNode(new Nodo("Statement",3,2));}
	| StmtBlock {createNode(new Nodo("Statement",3,2));printf("%s\n","Statement");};

Expresions:/*empty*/
	  | Expresion SEMICOLON {createNode(new Nodo("Expression",3,2));};

IfStmt: 
      IF OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("IF Statement",3,2));}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {createNode(new Nodo("IF Statement",3,2));};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("While Statement",3,2));};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR {createNode(new Nodo("For Statement",3,2));};

ForExpresion: /*empty*/
	    | Expresion {createNode(new Nodo("For Expression",3,2));};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {createNode(new Nodo("Return Statement",3,2));};

ReturnExpresion: /*empty*/
	       | Expresion {createNode(new Nodo("Return Expression",3,2));};

BreakStmt: BREAK SEMICOLON {createNode(new Nodo("Break Statement",3,2));};

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {createNode(new Nodo("Print Statement",3,2));printf("%s\n","Print Statement");};

CommaExpresions: CommaExpList {createNode(new Nodo("Comma Expressions",3,2));}
	| CommaExpresions CommaExpList {createNode(new Nodo("Comma Expressions",3,2));printf("%s\n","Expresions");};

CommaExpList: Expresion {createNode(new Nodo("Comma Expression List",3,2));}
	| CommaExpList COMMA Expresion {createNode(new Nodo("Comma Expression List",3,2));printf("%s\n","ExpresionsList");};

Expresion: LValue EQUALS Expresion {createNode(new Nodo("Expression",3,2));}
	| Constant {createNode(new Nodo("Expression",3,2));}
	| LValue {createNode(new Nodo("Expression",3,2));}
	| THIS {createNode(new Nodo("Expression",3,2));}
	| Call {createNode(new Nodo("Expression",3,2));}
	| OPENPAR Expresion CLOSEPAR {createNode(new Nodo("Expression",3,2));}
	| Expresion OP_ALG Expresion {createNode(new Nodo("Expression",3,2));}
	| Expresion OP_REL Expresion {createNode(new Nodo("Expression",3,2));}
	| Expresion OP_LOG Expresion {createNode(new Nodo("Expression",3,2));}
	| NOT Expresion {createNode(new Nodo("Expression",3,2));}
	| READINT OPENPAR CLOSEPAR {createNode(new Nodo("Expression",3,2));}
	| READLINE OPENPAR CLOSEPAR {createNode(new Nodo("Expression",3,2));}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {createNode(new Nodo("Expression",3,2));}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {createNode(new Nodo("Expression",3,2));};

LValue: IDENTIFIER {createNode(new Nodo("LValue",3,2));}
	| Expresion POINT IDENTIFIER {createNode(new Nodo("LValue",3,2));}
	| Expresion OPENSQR Expresion CLOSESQR {createNode(new Nodo("LValue",3,2));printf("%s\n","LValue");};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",3,2));}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",3,2));printf("%s\n","Call");};

Actuals: /*empty*/
       | CommaExpresions {createNode(new Nodo("Actuals",3,2));printf("%s\n","Expresions");};

Constant: INT {createNode(new Nodo("Constant",3,2));}
	| FLOAT {createNode(new Nodo("Constant",3,2));}
	| BOOLEAN {createNode(new Nodo("Constant",3,2));}
	| STRING {createNode(new Nodo("Constant",3,2));}
	| Null {createNode(new Nodo("Constant",3,2));printf("%s\n","Constant");};

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



