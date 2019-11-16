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

vector<VarObject> arbol;


void generarArbol(){
    arbol.push_back(new VarObject("Program","NA","NA","NA"));
    arbol.push_back(new VarObject("Decls","NA","NA","NA"));
    arbol.push_back(new VarObject("Decl","NA","NA","NA"));
    arbol.push_back(new VarObject("ClassDecl","NA","NA","NA"));
    arbol.push_back(new VarObject("VariableDecl","NA","NA","NA"));
    arbol.push_back(new VarObject("Variable","int","x","NA"));
    arbol.push_back(new VarObject("Fields","NA","NA","NA"));
    arbol.push_back(new VarObject("FunctionDecl","NA","NA","NA"));
    arbol.push_back(new VarObject("CommaVarList","NA","NA","NA"));
    arbol.push_back(new VarObject("Variable","int","y","NA"));
    arbol.push_back(new VarObject("StmtBlock","NA","NA","NA"));
    arbol.push_back(new VarObject("VariableDecl","NA","NA","NA"));
    arbol.push_back(new VarObject("Variable","int","var","NA"));
    arbol.push_back(new VarObject("Expresion","NA","NA","NA"));
    arbol.push_back(new VarObject("LValue","NA","x","NA"));
    arbol.push_back(new VarObject("Expresion","NA","NA","NA"));
    arbol.push_back(new VarObject("INT","NA","NA","2"));

}



int  main(int  num_args , char** args) {
    generarArbol();
}
