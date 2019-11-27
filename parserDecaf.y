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
static void analizarWhile(Nodo* tree);
static void analizarThis(Nodo * tree);
static void analizarFor(Nodo* tree);
static void analizarIf(Nodo* tree);
static void analizarPrint(Nodo * arbol);
static void analizarOperacionArim(Nodo* tree);
static void analizarOperacionIgual(Nodo* tree);
static void analizarOperacionBinario(Nodo* tree);
static vector< vector<VarObject> > construirTabla(Nodo* arbol);
static void printScopes(vector< vector<VarObject> > r);
static void analizarFuncion(Nodo *tree);
static void makeDirectory(string nombre);
static void analizarIndexacion(Nodo * );
static string getReturn(Nodo * tree);
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
    char* sqr;
  };

}
%token <stringValue> STRING
%token <nullValue> Null
%token <boolValue> BOOLEAN
%token <id> IDENTIFIER
%token <sqr> SQRBRACKET
%token <voidT> VOID
%token <tipo> TYPE
%token <int_val> INT
%token <double_val> DOUBLE
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
    vector< vector<VarObject> > v = construirTabla(arbol);
    analizadorSemantico(arbol);

		};

Decls: Decl {$$ = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| Decls Decl {$$ =$1;$1 = new Nodo("Decls",num_lines,num_caracteres,"NA","NA","NA",$2,NULL,NULL);};

Decl : VariableDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| FunctionDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| ClassDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
	| InterfaceDecl {$$ = new Nodo("Decl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

VariableDecl: Variable SEMICOLON {$$ = new Nodo("VariableDecl",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

Variable: TYPE IDENTIFIER {$$ = new Nodo("Variable",num_lines,num_caracteres,$1,$2,"NA",NULL,NULL,NULL);}
  | SQRBRACKET IDENTIFIER {$$ = new Nodo("Variable",num_lines,num_caracteres,$1,$2,"NA",NULL,NULL,NULL);};



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
  | ClassDecl {$$ = new Nodo("Field",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
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
     | Stmt Stmts {($$ =$1) = new Nodo("Stmts",num_lines,num_caracteres,"NA","NA","NA",$1,$2,NULL);};

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

ReturnExpresion: /*empty*/ {$$ = new Nodo("ReturnExpresionVoid",num_lines,num_caracteres,"void","NA","NA",NULL,NULL,NULL);};
	       | Constant {$$ = new Nodo("ReturnExpresionConst",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);}
         | IDENTIFIER {$$ = new Nodo("ReturnExpresionIdent",num_lines,num_caracteres,"NA",$1,"NA",NULL,NULL,NULL);};

BreakStmt: BREAK SEMICOLON {$$ = new Nodo("BreakStmt",num_lines,num_caracteres,"NA","NA","NA",NULL,NULL,NULL);};

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
	| NEWARRAY OPENPAR Expresion COMMA TYPE CLOSEPAR {$$ = new Nodo("NewArrExpresion",num_lines,num_caracteres,$5,"NA","NA",$3,NULL,NULL);}
  | IDENTIFIER OPENSQR Expresion CLOSESQR {$$ = new Nodo("IndexExpresion",num_lines,num_caracteres,"NA",$1,"NA",$3,NULL,NULL);}
  | THIS POINT IDENTIFIER EQUALS Expresion {$$ = new Nodo("THISExpresion",num_lines,num_caracteres,"NA",$3,"NA",$5,NULL,NULL);}
  | LValue EQUALS Expresion {$$ = new Nodo("EqualExpresion",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};

LValue: IDENTIFIER {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA",$1,"NA",NULL,NULL,NULL);}
	| Expresion POINT IDENTIFIER {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA",$3,"NA",$1,NULL,NULL);}
	| Expresion OPENSQR Expresion CLOSESQR {$$ = new Nodo("LValue",num_lines,num_caracteres,"NA","NA","NA",$1,$3,NULL);};

Call: IDENTIFIER OPENPAR Actuals CLOSEPAR {$$ = new Nodo("Call",num_lines,num_caracteres,"NA",$1,"NA",$3,NULL,NULL);}
	| Expresion POINT IDENTIFIER OPENPAR Actuals CLOSEPAR {$$ = new Nodo("Call",num_lines,num_caracteres,"NA",$3,"NA",$1,$5,NULL);};

Actuals: /*empty*/
       | CommaExpresions {$$ = new Nodo("Call",num_lines,num_caracteres,"NA","NA","NA",$1,NULL,NULL);};

Constant: INT {$$ = new Nodo("INT",num_lines,num_caracteres,"int","NA",$1,NULL,NULL,NULL);}
	| DOUBLE {$$ = new Nodo("FLOAT",num_lines,num_caracteres,"double","NA",$1,NULL,NULL,NULL);}
	| BOOLEAN {$$ = new Nodo("BOOLEAN",num_lines,num_caracteres,"bool","NA",$1,NULL,NULL,NULL);}
	| STRING {$$ = new Nodo("STRING",num_lines,num_caracteres,"string","NA",$1,NULL,NULL,NULL);}
	| Null {$$ = new Nodo("Null",num_lines,num_caracteres,"Null","NA",$1,NULL,NULL,NULL);};

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

static vector< vector<VarObject> > result;
static string typeRetDecl;
static string funcName;
static vector < char* > funcNames;
static void analizadorSemantico(Nodo* tree){
    if(tree == NULL) {
       return;
    }
    string s = tree->nombre.c_str();
    if((s.compare("IfStmt")) == 0){
        analizarIf(tree);
    }
    if((s.compare("WhileStmt")) == 0){
        analizarWhile(tree);
    }
    if((s.compare("ForStmt")) == 0){
      analizarFor(tree);
    }
    if(s.compare("IndexExpresion") == 0){
      analizarIndexacion(tree);
    }
    if(s.compare("PrintStmt")){
      //analizarPrint(tree);
    }
    if(s.compare("FunctionDecl")== 0){
      typeRetDecl = tree->tipo;

      funcName = tree->identificador;
    }
    if(s.compare("THISExpresion")==0){

      analizarThis(tree);
    }
    if(s.compare("ReturnStmt")==0){

      string s = tree->first->nombre.c_str();
      string tipoDado;
      if(s.compare("ReturnExpresionVoid")==0){
        tipoDado = tree->first->tipo;
        if(tipoDado.compare(typeRetDecl)!= 0){
          cout<<"Error, la funcion: "<<funcName<<" ,debe tener retorno vacio (void)\n";
          exit(0);
        }
      }
      if(s.compare("ReturnExpresionConst")==0){
        tipoDado = tree->first->first->tipo;
        if(tipoDado.compare(typeRetDecl)!= 0){
          cout<<"Error, la funcion: "<<funcName<<" ,debe tener retorno "<< typeRetDecl<<"\n" ;
          exit(0);
        }
      }
      if(s.compare("ReturnExpresionIdent")==0){
        string tipoD;
        string ident = tree->first->identificador;
        for(int i = 0;i<result.size();i++){
          for(int j = 0; j<result.at(i).size();j++){
            VarObject v = result.at(i).at(j);
            string name = v.identificador;
            if(name.compare(ident) == 0){
              tipoD = v.tipo;
              break;
            }
          }
        }
        if(tipoD.compare(typeRetDecl)!= 0){
          cout<<"Error, la funcion: "<<funcName<<" ,debe tener retorno "<< typeRetDecl<< " y la variable es tipo " << tipoD<<"\n" ;
          exit(0);
        }
      }
    }
    if(s.compare("SumExpresion") == 0){
      analizarOperacionArim(tree);
    }
    if(s.compare("MulDivModExpresion") == 0){
      analizarOperacionArim(tree);
    }
    if(s.compare("OpRelExpresion") == 0){
      analizarOperacionIgual(tree);
    }
    if(s.compare("OpIgualExpresion") == 0){
      analizarOperacionIgual(tree);
    }
    analizadorSemantico(tree->first);
    analizadorSemantico(tree->second);
    analizadorSemantico(tree->third);
}


static void analizarOperacionArim(Nodo* tree){
  string s1 = tree->first->first->nombre.c_str();
  string s2 = tree->second->first->nombre.c_str();
  int intOp = 0;
  if(s1.compare(s2) == 0){
    intOp = 1;
  }
  if(intOp == 0){
    cout<<"Error semantico, operandos de operacion aritmetica son incompatibles. "<<endl;
    exit(0);
  }
}

static void analizarThis(Nodo * tree){
  string var = tree->identificador;
  string tipoDado = tree->first->first->tipo;
  string tipoDecl;
  int found =0;
  for(int i = 0;i< result[0].size();i++){
    if(var.compare(result[0][i].identificador) ==0){
      found = 1;
      tipoDecl = result[0][i].tipo;
    }
  }
  if (found == 0){
    cout<< "Error, el THIS de la variable "<<var<<" referencia a un valor que no es atributo de clase."<<endl;
    exit(0);
  }
  if(tipoDado.compare(tipoDecl) != 0){
    cout<<"Error, el tipo declarado de la variable "<<var<<" no coincide con la asignacion"<<endl;
    exit(0);
  }
}


static void analizarOperacionIgual(Nodo* arbol){
  VarObject var;
  var.tipo = arbol->tipo;
  var.identificador = arbol->identificador;
  var.valor = "";
  string v1;
  string v2;
  int cont = 0;
  int pos = result.size()-1;
  for(int i = 0; i< result.size(); i++){
    for(int j = 0; j < result.at(i).size();j++){
      if(cont == 0){
        string idet = var.identificador;
        v1 = result.at(i).at(j).tipo;
      } if(cont > 0){
        v2 = result.at(i).at(j).tipo;
        int c = v1.compare(v2);
        //cout << "V1: " << v1 << endl;
        //cout << "V2: " << v2 << endl;
        if(c != 0){
          cout<<"Error, los operandos de igualdad o desigualdad no son compatibles."<<endl;
          exit(0);
        }
      }
        cont = cont + 1;
    }
  }
}


static void analizarOperacionBinario(Nodo* tree){
  string s1 = tree->first->first->first->nombre.c_str();
  string s2 = tree->second->first->first->nombre.c_str();
  int contOp = 0;
  if(s1.compare("OpIgualExpresion") == 0){
      contOp = 1;
    }
  if(s1.compare("OpRelExpresion") == 0){
    contOp = 1;
  }
  if(contOp == 0){
     cout<<"Error semantico, los operandos de los operadores binarios y unarios deben ser bool. "<<endl;
     exit(0);
  }
}


static void analizarIf(Nodo* tree){
    string s1 = tree->first->nombre.c_str();
    string s2 = tree->second->nombre.c_str();
    int contIf = 0;
    if(s1.compare("OpIgualExpresion") == 0){
      if(s2.compare("Stmt") == 0){
        analizarOperacionIgual(tree);
        contIf = 1;
      }
    }
    if((s1.compare("OpRelExpresion")) == 0){
	     if((s2.compare("Stmt")) == 0){
	        contIf = 1;
	     }
     }
     if((s1.compare("AndExpresion")) == 0){
 	     if((s2.compare("Stmt")) == 0){
         analizarOperacionBinario(tree);
 	        contIf = 1;
 	     }
      }
      if((s1.compare("OrExpresion")) == 0){
  	     if((s2.compare("Stmt")) == 0){
           analizarOperacionBinario(tree);
  	        contIf = 1;
  	     }
       }
     if(contIf == 0){
        cout<<"Error semantico, uso de if invalido "<<endl;
        exit(0);
     }
}

static void analizarPrint(Nodo * arbol){
  cout<<arbol->first->nombre.c_str()<<endl;

}


static void analizarWhile(Nodo* tree){
    string s1 = tree->first->nombre.c_str();
    string s2 = tree->second->nombre.c_str();
    int contWhile = 0;
    if((s1.compare("OpIgualExpresion")) == 0){
      if((s2.compare("Stmt")) == 0){
        contWhile = 1;
	     }
    }
    if((s1.compare("OpRelExpresion")) == 0){
	     if((s2.compare("Stmt")) == 0){
	        contWhile = 1;
	     }
     }
    if(contWhile == 0){
       cout<<"Error semantico, uso de while invalido "<<endl;
       exit(0);
    }
}


static void analizarFor(Nodo* tree){
    string s1 = tree->first->nombre.c_str();
    string s2 = tree->second->nombre.c_str();
    string s3 = tree->third->nombre.c_str();
    int contFor = 0;
    if((s1.compare("ForExpresion")) == 0){
      if((s2.compare("ForExpresion")) == 0){
        if((s3.compare("ForExpresion")) == 0){
	   	     contFor = 1;
	      }
      }
    }
    if(contFor == 0){
	     cout<<"Error semantico, uso de for invalido "<<endl;
       exit(0);
     }
}


static void analizarIndexacion(Nodo * tree){
  string id = tree->identificador;
  string valorDeseado = tree->first->first->valor;
  string valorMax;
  for(int i = 0;i<result.size();i++){
    for(int j = 0; j<result.at(i).size();j++){
      VarObject v = result.at(i).at(j);
      string name = v.identificador;
      int x = name.compare(id);
      if(x == 0){
        valorMax = v.valor;
        break;
      }
    }
  }
  int vd = atoi(valorDeseado.c_str());
  int vm = atoi (valorMax.c_str());
  if(vd>=vm){
    cout<<"Error, indice fuera de rango en variable "<<id<<endl;
    exit(0);
  }
}


static vector< vector<VarObject> > construirTabla(Nodo* arbol){
  if(arbol==NULL){

    return result;
  }
  string s = arbol->nombre.c_str();
  int c = s.compare("ClassDecl");
  if(c==0){
    vector<VarObject> v;
    result.push_back(v);


  }
  c = s.compare("FunctionDecl");
  if(c == 0){
    int found = 0;
    string id = arbol->identificador;
    for(int i =0;i< funcNames.size();i++){
      if(id.compare(funcNames.at(i)) == 0){
        found =1 ;
      }
    }
    if(found == 0){
      vector<VarObject> v;
      result.push_back(v);
      funcNames.push_back(arbol->identificador);
    }
    else{
      cout<<"Error, ya existe una funcion declarada con el identificador "<<id<<endl;
      exit(0);
    }


  }
  c = s.compare("Variable");
  if(c == 0){
    VarObject var;
    var.tipo = arbol->tipo;
    var.identificador = arbol->identificador;
    var.valor = "";
    int pos = result.size()-1;
    for(int i = 0; i< result.size(); i++){
      for(int j = 0; j < result.at(i).size();j++){
        string v1 = var.identificador;
        string v2 = result.at(i).at(j).identificador;
        int c = v1.compare(v2);
        if(c == 0){
          cout<<"Error, la variable "<<v1<<" ya existe"<<endl;
          exit(0);
        }

      }
    }
    result.at(pos).push_back(var);
  }
  c = s.compare("EqualExpresion");
  if(c == 0){
    string id = arbol->first->identificador;
    string val = arbol->second->first->valor;
    string type = arbol->second->first->tipo;
    string type2Array;
    int found = 0;
    for(int i = 0;i<result.size();i++){
      for(int j = 0; j<result.at(i).size();j++){
        int x = result.at(i).at(j).identificador.compare(id);
        if(x == 0 ){
          int z = arbol->second->nombre.compare("NewArrExpresion");
          if(z == 0){
            type = string(arbol->second->first->first->tipo)+"[]";
            val = arbol->second->first->first->valor;
            type2Array = string(arbol->second->tipo)+"[]";
            z = result.at(i).at(j).tipo.compare(type2Array);
            if(z != 0){
              cout<<"Error, el tipo "<<type2Array<< " asignado al array "<<id<<" no coincide con la declaracion previa: "<<result.at(i).at(j).tipo<<endl;
              exit(0);
            }
          }
          z = arbol->second->nombre.compare("IndexExpresion");
          if(z == 0){
            type = arbol->second->first->first->tipo;
            int t = type.compare("int");
            if(t!=0){
              cout<<"Error, el indice del array "<<id<<" debe ser entero"<<endl;
              exit(0);
            }

          }
          int y = result.at(i).at(j).tipo.compare(type);
          if(y==0){
            result.at(i).at(j).valor = val;
            found = 1;
          }
          else{
            cout<<"Error, el tipo declarado de la variable "<<id<<" no coincide con la asignacion"<<endl;
            exit(0);
          }
        }
      }
    }
    if(found == 0){
      cout<<"Error, la variable "<<id<<" no fue declarada previamente"<<endl;
      exit(0);
    }
  }
  construirTabla(arbol->first);
  construirTabla(arbol->second);
  construirTabla(arbol->third);
  return result;
}


static void printScopes(vector< vector<VarObject> > r){

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
