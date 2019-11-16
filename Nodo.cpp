#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "Nodo.h"

using namespace std;

Nodo::Nodo(string s,int f, int c,string v,Nodo* n1,Nodo* n2,Nodo* n3)
:nombre(s),fila(f),columna(c),valor(v),first(n1),second(n2),third(n3){}
