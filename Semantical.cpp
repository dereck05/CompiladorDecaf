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




void analizadorSemantico(Nodo* arbol){
  if(arbol == NULL) {
     return;
  }
  switch(arbol->nombre.c_str()){
    case "WhileStmt":
      //analizarWhile()
      break;
    case "ForStmt":
      //analizarFor();
      break;

    default:
      break;
  }
  analizadorSemantico(arbol->first);
  analizadorSemantico(arbol->second);
  analizadorSemantico(arbol->third);
}
