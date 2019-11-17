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
#include "VarObject.h"
using  namespace  std;
extern void yyerror(const char *);
extern int yylex();
extern int yylineno;
extern int num_lines;
extern int num_caracteres;
static void createNode(Nodo *n);
static void readVector();
static void analizadorSemantico(Nodo* tree);
static vector<vector<VarObject>> construirTabla(Nodo* arbol);
static void printScopes(vector<vector<VarObject>> r);
static void makeDirectory(string nombre);
static char* itostr(int d);
static char* ftostr(double d);
static string stostr(string d);
static void PrintTree(Nodo * tree);
%}


%union{
  struct{
    char* int_val;
    char* double_val;
    string* str_val;
    Nodo *nodo;

    char* tipo;
    char* voidT;
    char* id;
    char* stringValue;
    char* nullValue;
    char* boolValue;
  };

}
%token <stringValue> STRING
%token <nullValue> Null
%token <boolValue> BOOLEAN
%token <id> IDENTIFIER SQRBRACKET
%token <voidT> VOID
%token <tipo> TYPE
%token <int_val> INT
%token <double_val> FLOAT
%token <str_val> OP_LOG OP_ALG SYMBOL S_COMMENT OPEN_STRING HEX TAG SEMICOLON OPENPAR CLOSEPAR COMMA CLASS EXTENDS IMPLEMENTS INTERFACE IF ELSE WHILE FOR RETURN BREAK PRINT OPENBRA CLOSEBRA THIS READINT READLINE NEW NEWARRAY CLOSESQR INTCONST DOUBLECONST BOOLCONST STRCONST

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
%type<nodo> Fields Field StmtBlock Stmts Stmt Expresions CommaExpresions CommaExpList Expresion LValue Constant VariableDecls IfStmt WhileStmt ForExpresion ForStmt ReturnStmt Prototypes Call Actuals


%start Program

%%
Program : Decls {Nodo *arbol = new Nodo("Program",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);
		//PrintTree(arbol);

    vector<vector<VarObject>> v = construirTabla(arbol);
    cout<< v.size();
    //printScopes(v);

		};

Decls: Decl {$$ = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| Decls Decl {$$ =$1;$1 = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);};

Decl : VariableDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| FunctionDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| ClassDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| InterfaceDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

VariableDecl: Variable SEMICOLON {$$ = new Nodo("VariableDecl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

Variable: TYPE IDENTIFIER {$$ = new Nodo("Variable",num_lines,num_caracteres,$1,$2,"NA",NULL,NULL,NULL);}
  | TYPE SQRBRACKET IDENTIFIER {$$ = new Nodo("Variable",num_lines,num_caracteres,$1,$3,"NA",NULL,NULL,NULL);};



FunctionDecl: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock  {$$ = new Nodo("FunctionDecl",num_lines,num_caracteres,$1,$2,"NA",$4,$6,NULL);}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR StmtBlock {$$ = new Nodo("FunctionDecl",num_lines,num_caracteres,$1,$2,"NA",$4,$6,NULL);};

Formals:/*empty*/
        | CommaVariables {$$ = new Nodo("Formals",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};




CommaVariables: CommaVarList {$$ = new Nodo("CommaVariables",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| CommaVariables CommaVarList {$$ = new Nodo("CommaVariables",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

CommaVarList: Variable {$$ = new Nodo("CommaVarList",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| CommaVarList COMMA Variable {$$ = new Nodo("CommaVarList",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};


ClassDecl : CLASS IDENTIFIER OPENBRA Fields CLOSEBRA {$$ = new Nodo("ClassDecl",num_lines,num_caracteres,"NA",$2,"NA",$4,NULL,NULL);}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER OPENBRA Fields CLOSEBRA {$$ = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",$6,NULL,NULL);}
	  | CLASS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {$$ = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",$4,$6,NULL);}
	  | CLASS IDENTIFIER EXTENDS IDENTIFIER IMPLEMENTS CommaIdentifiers OPENBRA Fields CLOSEBRA {$$ = new Nodo("ClassDecl",num_lines,num_caracteres,"NA","NA","NA",$6,$8,NULL);};

CommaIdentifiers: CommaIdentList {$$ = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| CommaIdentifiers CommaIdentList {$$ = new Nodo("CommaIdentifiers",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

CommaIdentList: IDENTIFIER {$$ = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",$1,"NA",NULL,NULL,NULL);}
	| CommaIdentList COMMA IDENTIFIER {$$ = new Nodo("CommaIdentList",num_lines,num_caracteres,"NA",$3,"NA",$1,NULL,NULL);};

Fields: /*empty*/
      | Field Fields {($$=$1) =new Nodo("Fields",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

Field: VariableDecl {$$ = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| FunctionDecl {$$ = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

InterfaceDecl: INTERFACE IDENTIFIER OPENBRA Prototypes CLOSEBRA {$$ = new Nodo("InterfaceDecl",num_lines,num_caracteres,"NA","NA","NA",$4,NULL,NULL);};

Prototypes: /*empty*/
	  | Prototypes Prototype {$$ = new Nodo("Prototypes",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

Prototype: TYPE IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {$$ = new Nodo("Prototype",num_lines,num_caracteres,"NA","NA","NA",$4,NULL,NULL);}
	| VOID IDENTIFIER OPENPAR Formals CLOSEPAR SEMICOLON {$$ = new Nodo("Prototype",num_lines,num_caracteres,"NA","NA","NA",$4,NULL,NULL);};

StmtBlock: OPENBRA VariableDecls Stmts CLOSEBRA {$$ = new Nodo("StmtBlock",num_lines,num_caracteres,"NA","NA","NA",$2,$3,NULL);};

VariableDecls: /*empty*/
	     | VariableDecls VariableDecl {$$ = new Nodo("VariableDecls",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);};

Stmts: /*empty*/
     | Stmts Stmt {$$ = new Nodo("Stmts",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

Stmt : Expresions {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| IfStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| WhileStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| ForStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| BreakStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| ReturnStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| PrintStmt {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| StmtBlock {$$ = new Nodo("Stmt",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

Expresions:/*empty*/
	  | Expresion SEMICOLON {$$ = new Nodo("Expresions",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

IfStmt:
      IF OPENPAR Expresion CLOSEPAR Stmt {$$ = new Nodo("IfStmt",num_lines,num_caracteres,"NA","NA","NA",$3,$5,NULL);}
      | IF OPENPAR Expresion CLOSEPAR Stmt ELSE Stmt {$$ = new Nodo("IfStmt",num_lines,num_caracteres,"NA","NA","NA",$3,$5,$7);};

WhileStmt: WHILE OPENPAR Expresion CLOSEPAR Stmt {$$ = new Nodo("WhileStmt",num_lines,num_caracteres,"NA","NA","NA",$3,$5,NULL);};

ForStmt: FOR OPENPAR ForExpresion SEMICOLON ForExpresion SEMICOLON ForExpresion CLOSEPAR {$$ = new Nodo("ForStmt",num_lines,num_caracteres,"NA","NA","NA",$3,$5,$7);};

ForExpresion: /*empty*/
	    | Expresion {$$ = new Nodo("ForExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

ReturnStmt: RETURN ReturnExpresion SEMICOLON {$$ = new Nodo("ReturnStmt",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);};;

ReturnExpresion: /*empty*/
	       | Expresion {$$ = new Nodo("ReturnExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};;

BreakStmt: BREAK SEMICOLON {$$ = new Nodo("BreakStmt",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);};;

PrintStmt: PRINT OPENPAR CommaExpresions CLOSEPAR SEMICOLON {$$ = new Nodo("PrintStmt",num_lines,num_caracteres,"NA","NA","NA",$3,NULL,NULL);};;

CommaExpresions: CommaExpList {$$ = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| CommaExpresions CommaExpList {$$ = new Nodo("CommaExpresions",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

CommaExpList: Expresion {$$ = new Nodo("CommaExpList",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| CommaExpList COMMA Expresion {$$ = new Nodo("CommaExpList",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};

Expresion: Constant {$$ = new Nodo("ConstantExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| LValue {$$ = new Nodo("LValueExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| THIS   {$$ = new Nodo("ThisExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
	| Call   {$$ = new Nodo("CallExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| OPENPAR Expresion CLOSEPAR {$$ = new Nodo("Expresion",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);}
	| Expresion SUM_RESTA Expresion {$$ = new Nodo("SumExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| Expresion MUL_DIV_MOD Expresion {$$ = new Nodo("MulDivModExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| Expresion OP_REL Expresion {$$ = new Nodo("OpRelExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| Expresion OP_IGUALDAD Expresion {$$ = new Nodo("OpIgualExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| Expresion LOG_AND Expresion {$$ = new Nodo("AndExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| Expresion LOG_OR Expresion {$$ = new Nodo("OrExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);}
	| NOT Expresion {$$ = new Nodo("NotExpresion",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);}
	| READINT OPENPAR CLOSEPAR {$$ = new Nodo("ReadIntExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
	| READLINE OPENPAR CLOSEPAR {$$ = new Nodo("ReadLineExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
	| NEW OPENPAR IDENTIFIER CLOSEPAR {$$ = new Nodo("NewExpresion",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);}
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {$$ = new Nodo("NewArrExpresion",num_lines,num_caracteres,"NA","NA","NA",$3,NULL,NULL);}
  | LValue EQUALS Expresion {$$ = new Nodo("EqualExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};

LValue: IDENTIFIER {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA",$1,"NA",NULL,NULL,NULL);}
	| Expresion POINT IDENTIFIER {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA",$3,"NA",$1,NULL,NULL);}
	| Expresion OPENSQR Expresion CLOSESQR {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {$$ = new Nodo("Call",num_lines,num_caracteres,"NA",$1,"NA",$3,NULL,NULL);}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {$$ = new Nodo("Call",num_lines,num_caracteres,"NA",$3,"NA",$1,$5,NULL);};

Actuals: /*empty*/
       | CommaExpresions {$$ = new Nodo("Call",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

Constant: INT {$$ = new Nodo("INT",num_lines,num_caracteres,"NA","NA",$1,NULL,NULL,NULL);}
	| FLOAT {$$ = new Nodo("FLOAT",num_lines,num_caracteres,"NA","NA",$1,NULL,NULL,NULL);}
	| BOOLEAN {$$ = new Nodo("BOOLEAN",num_lines,num_caracteres,"NA","NA",$1,NULL,NULL,NULL);}
	| STRING {$$ = new Nodo("STRING",num_lines,num_caracteres,"NA","NA",$1,NULL,NULL,NULL);}
	| Null {$$ = new Nodo("Null",num_lines,num_caracteres,"NA","NA",$1,NULL,NULL,NULL);};

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
    for(int i =0;i<v.size(); i++){
       printf("\n%s","fila:");
       printf("%d",v[i]->fila);
       printf("%s","  columna:");
       printf("%d",v[i]->columna);
       printf("%s","  nombre:");
       printf("%s",v[i]->nombre);
       makeDirectory(v[i]->nombre);
       if(v[i]->valor != "NA"){
           printf("%s","  valor:");
           printf("%s",v[i]->valor);
	         makeDirectory(v[i]->valor);
       }
    }
}


static string stostr(string d){
    string out;
    stringstream ss;
    ss << d;
    out = ss.str();
    return out;

}

static void PrintTree(Nodo* tree){
  if(tree == NULL) {
     return;
  }
  printf("ID: %s",tree->nombre.c_str());
  if(tree->tipo != "NA")cout<<" Tipo:"<<string(tree->tipo);
  if(tree->identificador != "NA")cout<<" identificador:"<<string(tree->identificador);
  if(tree->valor != "NA")cout<<" Valor:"<<string(tree->valor);
  printf("\n");
  PrintTree(tree->first);
  PrintTree(tree->second);
  PrintTree(tree->third);
}


//_________________________________________________Semantical____________________________________________

static void analizadorSemantico(Nodo* tree){
    if(tree == NULL) {
       return;
    }
    if(tree->nombre.c_str() == "WhileStmt"){
      //analizarWhile()
    }
    if(tree->nombre.c_str() == "ForStmt"){
      //analizarWhile()
    }

    analizadorSemantico(tree->first);
    analizadorSemantico(tree->second);
    analizadorSemantico(tree->third);
}


static vector<vector<VarObject>> result;

static vector<vector<VarObject>> construirTabla(Nodo* arbol){

  if(arbol==NULL){

    return result;
  }
  cout<<arbol->nombre.c_str()<<endl;
  string s = arbol->nombre.c_str();
  int c = s.compare("ClassDecl");
  if(c==0){
    vector<VarObject> v;
    result.push_back(v);
    cout<<"Scope de clase!"<<endl;
  }
  c = s.compare("FunctionDecl");
  if(c == 0){
    VarObject var;
    vector<VarObject> v;
    result.push_back(v);
    vector<VarObject> ve = result.at(0);
    ve.push_back(var);
    cout<<ve.size()<<endl;
    cout<<"Scope de funcion!"<<endl;
  }
  c = s.compare("Variable");
  if(c == 0){
    VarObject var;
    var.tipo = arbol->tipo;
    var.identificador = arbol->identificador;
    var.valor = "";




    //int pos = result.size()-1;
    //cout<<pos<<endl;
    //result.at(result.size()-1).push_back(var);
    result.at(0).push_back(var);
    cout<<result.at(0).size();
  }
  c = s.compare("EqualExpresion");
  if(c == 0){
    string id = arbol->first->identificador;
    string val = arbol->second->first->valor;
    for(int i = 0;i<result.size();i++){
      vector<VarObject> v = result.at(i);
      for(int j = 0; j<v.size();j++){
        VarObject var = v.at(j);
        if(var.identificador == id){
          var.valor = val;
        }

      }
    }
  }
  construirTabla(arbol->first);
  construirTabla(arbol->second);
  construirTabla(arbol->third);


}

static void printScopes(vector<vector<VarObject>> r){

  for(int i = 0;i<r.size();i++){
    vector<VarObject> v = r.at(i);
    cout<<"--------------Scope--------------"<<endl;
    for(int j = 0; j<v.size();j++){
      VarObject var = v.at(j);
      cout<< "Tipo:"<<var.tipo;
      cout<< " ID:"<<var.identificador;
      cout<< " Valor:"<<var.valor<<endl;

    }
  }

}
