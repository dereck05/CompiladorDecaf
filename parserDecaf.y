%{
#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <sstream>
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
static string itostr(int d);
static string ftostr(double d);

%}


%union{
    int int_val;
    double double_val;
    string* str_val;

}

%token <int_val> INT
%token <double_val> FLOAT
%token <str_val> BOOLEAN OP_LOG OP_ALG SYMBOL IDENTIFIER S_COMMENT OPEN_STRING STRING HEX TYPE SQRBRACKET TAG SEMICOLON OPENPAR CLOSEPAR VOID COMMA CLASS EXTENDS IMPLEMENTS INTERFACE IF ELSE WHILE FOR RETURN BREAK PRINT OPENBRA CLOSEBRA THIS READINT READLINE NEW NEWARRAY CLOSESQR INTCONST DOUBLECONST BOOLCONST STRCONST Null 
 
%token EQUALS
%left LOG_OR
%left LOG_AND
%token OP_IGUALDAD
%token OP_REL
%left SUM_RESTA
%left MUL_DIV_MOD
%token NOT
%token OPENSQR
%token POINT






%start Program

%%
Program : Decls {createNode(new Nodo("Program",num_lines,num_caracteres,"NA"));readVector();}; 

Decls: Decl {createNode(new Nodo("Decls",num_lines,num_caracteres,"NA"));}
	| Decls Decl {createNode(new Nodo("Decls",num_lines,num_caracteres,"NA"));};

Decl : VariableDecl {createNode(new Nodo("Decl",num_lines,num_caracteres,"NA"));}
	| FunctionDecl {createNode(new Nodo("Decl",num_lines,num_caracteres,"NA"));}
	| ClassDecl {createNode(new Nodo("Decl",num_lines,num_caracteres,"NA")); }
	| InterfaceDecl {createNode(new Nodo("Decl",num_lines,num_caracteres,"NA"));};

VariableDecl: Variable SEMICOLON {createNode(new Nodo("VariableDecl",num_lines,num_caracteres,"NA"));};  

Variable: TYPE IDENTIFIER {createNode(new Nodo("Variable",num_lines,num_caracteres,"NA"));}  
	 | TYPE SQRBRACKET IDENTIFIER {createNode(new Nodo("Variable",num_lines,num_caracteres,"NA"));};   ;//int x;  o int[] x;

FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {createNode(new Nodo("FunctionDecl",num_lines,num_caracteres,"NA"));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {createNode(new Nodo("FunctionDecl",num_lines,num_caracteres,"NA"));}; 

Formals: /*empty*/ 
	| CommaVariables {createNode(new Nodo("Formals",num_lines,num_caracteres,"NA"));};  


CommaVariables: CommaVarList {createNode(new Nodo("CommaVariables",num_lines,num_caracteres,"NA"));}
	| CommaVariables CommaVarList {createNode(new Nodo("Comma Variables",num_lines,num_caracteres,"NA"));};  

CommaVarList: Variable {createNode(new Nodo("CommaVarList",num_lines,num_caracteres,"NA"));}
	| CommaVarList COMMA Variable {createNode(new Nodo("CommaVarList",num_lines,num_caracteres,"NA"));};

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres,"NA"));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres,"NA"));}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres,"NA"));}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {createNode(new Nodo("ClassDecl",num_lines,num_caracteres,"NA"));}
	  ;

CommaIdentifiers: CommaIdentList {createNode(new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA"));}
	| CommaIdentifiers CommaIdentList {createNode(new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA"));};

CommaIdentList: IDENTIFIER {createNode(new Nodo("CommaIdentList",num_lines,num_caracteres,"NA"));}
	| CommaIdentList COMMA IDENTIFIER {createNode(new Nodo("CommaIdentList",num_lines,num_caracteres,"NA"));};

Fields: /*empty*/
      |  Fields Field {createNode(new Nodo("Fields",num_lines,num_caracteres,"NA"));};

Field: VariableDecl {createNode(new Nodo("Field",num_lines,num_caracteres,"NA"));}
	| FunctionDecl {createNode(new Nodo("Field",num_lines,num_caracteres,"NA"));};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {createNode(new Nodo("InterfaceDecl",num_lines,num_caracteres,"NA"));};

Prototypes: /*empty*/
	  | Prototypes Prototype {createNode(new Nodo("Prototypes",num_lines,num_caracteres,"NA"));};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",num_lines,num_caracteres,"NA"));}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {createNode(new Nodo("Prototype",num_lines,num_caracteres,"NA"));}; 

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {createNode(new Nodo("StmtBlock",num_lines,num_caracteres,"NA"));}; 

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {createNode(new Nodo("VariableDecls",num_lines,num_caracteres,"NA"));};

Stmts: /*empty*/
     | Stmts Stmt {createNode(new Nodo("Stmts",num_lines,num_caracteres,"NA"));};

Stmt : Expresions
	| IfStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| WhileStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| ForStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| BreakStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| ReturnStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| PrintStmt {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));}
	| StmtBlock {createNode(new Nodo("Stmt",num_lines,num_caracteres,"NA"));};

Expresions:/*empty*/
	  | Expresion SEMICOLON {createNode(new Nodo("Expressions",num_lines,num_caracteres,"NA"));};

IfStmt: 
      IF OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("IFStmt",num_lines,num_caracteres,"NA"));}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {createNode(new Nodo("IFStmt",num_lines,num_caracteres,"NA"));};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {createNode(new Nodo("While Statement",num_lines,num_caracteres,"NA"));};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR {createNode(new Nodo("ForStmt",num_lines,num_caracteres,"NA"));};

ForExpresion: /*empty*/
	    | Expresion {createNode(new Nodo("ForExpression",num_lines,num_caracteres,"NA"));};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {createNode(new Nodo("ReturnStmt",num_lines,num_caracteres,"NA"));};

ReturnExpresion: /*empty*/
	       | Expresion {createNode(new Nodo("ReturnExpression",num_lines,num_caracteres,"NA"));};

BreakStmt: BREAK SEMICOLON {createNode(new Nodo("BreakStmt",num_lines,num_caracteres,"NA"));};

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {createNode(new Nodo("PrintStmt", num_lines, num_caracteres,"NA"));};

CommaExpresions: CommaExpList {createNode(new Nodo("CommaExpressions",num_lines,num_caracteres,"NA"));}
	| CommaExpresions CommaExpList {createNode(new Nodo("CommaExpressions",num_lines,num_caracteres,"NA"));};

CommaExpList: Expresion {createNode(new Nodo("CommaExpList",num_lines,num_caracteres,"NA"));}
	| CommaExpList COMMA Expresion {createNode(new Nodo("CommaExpList",num_lines,num_caracteres,"NA"));};

Expresion: LValue EQUALS Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Constant {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| LValue {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| THIS {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Call {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| OPENPAR Expresion CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion SUM_RESTA Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion MUL_DIV_MOD Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion OP_REL Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion OP_IGUALDAD Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion LOG_AND Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| Expresion LOG_OR Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| NOT Expresion {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| READINT OPENPAR CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| READLINE OPENPAR CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {createNode(new Nodo("Expression",num_lines,num_caracteres,"NA"));};

LValue: IDENTIFIER {createNode(new Nodo("LValue",num_lines,num_caracteres,"NA"));}
	| Expresion POINT IDENTIFIER {createNode(new Nodo("LValue",num_lines,num_caracteres,"NA"));}
	| Expresion OPENSQR Expresion CLOSESQR {createNode(new Nodo("LValue",num_lines,num_caracteres,"NA"));};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",num_lines,num_caracteres,"NA"));}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {createNode(new Nodo("Call",num_lines,num_caracteres,"NA"));};

Actuals: /*empty*/
       | CommaExpresions {createNode(new Nodo("Actuals",num_lines,num_caracteres,"NA"));};

Constant: INT {createNode(new Nodo("Constant",num_lines,num_caracteres,itostr($1)));}
	| FLOAT {createNode(new Nodo("Constant",num_lines,num_caracteres,ftostr($1)));}
	| BOOLEAN {createNode(new Nodo("Constant",num_lines,num_caracteres,"NA"));}
	| STRING {createNode(new Nodo("Constant",num_lines,num_caracteres,"NA"));}
	| Null {createNode(new Nodo("Constant",num_lines,num_caracteres,"NA"));};

%%

static vector<Nodo*> v ;

static void createNode(Nodo *n){
    v.push_back(n);
    //printf("%s\n","Inserted!");
}

static string path = "/home/dereck05/Desktop/Pruebas";

static void makeDirectory(string nombre){
	path = path +"/"+ nombre;
	//printf("%s\n",path.c_str());	
	mkdir(path.c_str() ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

static void readVector(){
    for(int i =v.size()-1; i>=0; i--){
       printf("\n%s","fila:");
       printf("%d",v[i]->fila);
       printf("%s","  columna:");
       printf("%d",v[i]->columna);
       printf("%s","  nombre:");
       printf("%s",v[i]->nombre.c_str());
       makeDirectory(v[i]->nombre);
       if(v[i]->valor != "NA"){
           printf("%s","  valor:");
           printf("%s",v[i]->valor.c_str());
	   makeDirectory(v[i]->valor.c_str());
       }
    }
}

static string itostr(int d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;


}
static string ftostr(double d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}

