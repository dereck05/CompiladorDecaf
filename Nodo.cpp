#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "Nodo.h"

using namespace std;

Nodo::Nodo(string s,int f, int c,char* t,char* i,char* v,Nodo* n1,Nodo* n2,Nodo* n3)
:nombre(s),fila(f),columna(c),tipo(t),identificador(i),valor(v),first(n1),second(n2),third(n3){}
