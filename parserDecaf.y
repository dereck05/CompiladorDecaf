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
#include <stack>




using  namespace  std;
extern void yyerror(const char *);
extern int yylex();
extern int yylineno;
extern int num_lines;
extern int num_caracteres;

static void readVector();
static void makeDirectory(string nombre);
static string itostr(int d);
static string ftostr(double d);
static string stostr(string d);


struct Nodo{
  string nombre;
  int fila;
  int columna;
  string valor;
  vector<Nodo*> first;
  vector<Nodo*> second;
  vector<Nodo*> third;
};
typedef struct Nodo * nodo;
void PrintTree(nodo tree);
nodo createNodo(string s,int f, int c,string v,vector<nodo> n1,vector<nodo> n2,vector<nodo> n3);
%}



%union{
    int int_val;
    double double_val;
    string* str_val;
    Nodo *nodo;

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

%type<nodo> Decls Decl ClassDecl VariableDecl FunctionDecl InterfaceDecl Variable Formals CommaVariables CommaVarList CommaIdentifiers CommaIdentList ReturnExpresion BreakStmt PrintStmt Prototype
%type<nodo> Fields Field StmtBlock Stmts Stmt Expresions CommaExpresions CommaExpList Expresion LValue Constant VariableDecls IfStmt WhileStmt ForExpresion ForStmt ReturnStmt Prototypes Call Actuals Program


%start Program

%%
Program : Decls {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;Nodo*n = createNodo("Program",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);};

Decls: Decl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decls",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| Decls Decl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decls",num_lines,num_caracteres,"NA",v1.push_back($1),v2.push_back($2),v3);};

Decl : VariableDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decl",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| FunctionDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decl",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| ClassDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decl",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| InterfaceDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Decl",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);};

VariableDecl: Variable SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("VariableDecl",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);};

Variable: TYPE IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Variable",num_lines,num_caracteres,"NA",v1,v2,v3);}
  | TYPE SQRBRACKET IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Variable",num_lines,num_caracteres,"NA",v1,v2,v3);};



FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("FunctionDecl",num_lines,num_caracteres,"NA",v1.push_back($4),$v2.push_back($6),0\v3);}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("FunctionDecl",num_lines,num_caracteres,"NA",v1.push_back($4),$v2.push_back($6),v3);};

Formals: %empty
	| CommaVariables {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Formals",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);};


CommaVariables: CommaVarList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaVariables",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| CommaVariables CommaVarList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaVariables",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2),v3);};

CommaVarList: Variable {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaVarList",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| CommaVarList COMMA Variable {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaVarList",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($3),v3);};

ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ClassDecl",num_lines,num_caracteres,"NA",$v1.push_back($4),v2,v3);}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ClassDecl",num_lines,num_caracteres,"NA",$v1.push_back($6),v2,v3);}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ClassDecl",num_lines,num_caracteres,"NA",$v1.push_back($4),$v2.push_back($6),v3);}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ClassDecl",num_lines,num_caracteres,"NA",$v1.push_back($6),$v2.push_back($8),v3);};


CommaIdentifiers: CommaIdentList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaIdentifiers",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| CommaIdentifiers CommaIdentList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaIdentifiers",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2),v3);};

CommaIdentList: IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaIdentList",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| CommaIdentList COMMA IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaIdentList",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);};

Fields:
      |  Fields Field {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Fields",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2),v3);};

Field: VariableDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Field",num_lines,num_caracteres,"NA",v1.push_back($1),v2,v3);}
	| FunctionDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Field",num_lines,num_caracteres,"NA",v1.push_back($1)v2,v3);};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("InterfaceDecl",num_lines,num_caracteres,"NA",$v1.push_back($4),v2,v3);};

Prototypes: /*empty*/
	  | Prototypes Prototype {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Prototypes",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2),v3);};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Prototype",num_lines,num_caracteres,"NA",$v2.push_back($4),v2,v3;}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Prototype",num_lines,num_caracteres,"NA",$v1.push_back($4),v2,v3);};

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("StmtBlock",num_lines,num_caracteres,"NA",$v1.push_back($2),$v2.push_back($3),v3);};

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("VariableDecls",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2),v3);};

Stmts: /*empty*/
     | Stmts Stmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmts",num_lines,num_caracteres,"NA",v1.push_back($1),$v2.push_back($2},0);};

Stmt : Expresions {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| IfStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| WhileStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| ForStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| BreakStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| ReturnStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| PrintStmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| StmtBlock {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Stmt",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);};

Expresions:/*empty*/
	  | Expresion SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresions",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);};

IfStmt:
      IF OPENPAR Expresion CLOSEPAR Stmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("IfStmt",num_lines,num_caracteres,"NA",$3,$5,0);}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("IfStmt",num_lines,num_caracteres,"NA",$3,$5,$7);};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("WhileStmt",num_lines,num_caracteres,"NA",$3,$5,0);};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR{vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ForStmt",num_lines,num_caracteres,"NA",$3,$5,$7);};

ForExpresion: /*empty*/
	    | Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ForExpresion",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ReturnStmt",num_lines,num_caracteres,"NA",$2,0,0);};;

ReturnExpresion: /*empty*/
	       | Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("ReturnExpresion",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);};;

BreakStmt: BREAK SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("BreakStmt",num_lines,num_caracteres,"NA",v1,v2,v3);};;

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("PrintStmt",num_lines,num_caracteres,"NA",$3,0,0);};;

CommaExpresions: CommaExpList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaExpresions",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| CommaExpresions CommaExpList {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaExpresions",num_lines,num_caracteres,"NA",v1.push_back($1),$2,0);};

CommaExpList: Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaExpList",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| CommaExpList COMMA Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("CommaExpList",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);};

Expresion: LValue EQUALS Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Constant {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| LValue {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| THIS   {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| Call   {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| OPENPAR Expresion CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",$2,0,0);}
	| Expresion SUM_RESTA Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Expresion MUL_DIV_MOD Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Expresion OP_REL Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Expresion OP_IGUALDAD Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Expresion LOG_AND Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| Expresion LOG_OR Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);}
	| NOT Expresion {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",$2,0,0);}
	| READINT OPENPAR CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| READLINE OPENPAR CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Expresion",num_lines,num_caracteres,"NA",$3,0,0);};

LValue: IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("LValue",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| Expresion POINT IDENTIFIER {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("LValue",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);}
	| Expresion OPENSQR Expresion CLOSESQR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("LValue",num_lines,num_caracteres,"NA",v1.push_back($1),$3,0);};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Call",num_lines,num_caracteres,"NA",$3,0,0);}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Call",num_lines,num_caracteres,"NA",v1.push_back($1),$5,0);};

Actuals: /*empty*/
       | CommaExpresions {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("Call",num_lines,num_caracteres,"NA",v1.push_back($1),0,0);};

Constant: INT {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("INT",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| FLOAT {vector<nodo>v1;vector<nodo>v2;vector<nodo>v3;$$ = createNodo("FLOAT",num_lines,num_caracteres,"NA",v1,v2,v3);}
	| BOOLEAN
	| STRING
	| Null ;

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
    for(int i =0;i<v.size(); i++){
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
static string stostr(string d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}

void PrintTree(nodo tree){
  if(tree==0)return;
  cout<<tree->first->first->first->first->first->nombre;
  //PrintTree(tree->first);



}


nodo createNodo(string s,int f, int c,string v,nodo n1,nodo n2,nodo n3){
  Nodo *nd = new Nodo();
  nd->nombre = s;
  nd->fila = f;
  nd->columna=c;
  nd->valor = v;
  nd->first = n1;
  nd->second=n2;
  nd->third = n3;
  return nd;
}
