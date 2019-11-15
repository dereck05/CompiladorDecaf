#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include "Nodo.h"

using namespace std;

Nodo::Nodo(string s,int f, int c,string v,vector<Nodo*> n1,vector<Nodo*> n2,vector<Nodo*> n3)
:nombre(s),fila(f),columna(c),valor(v),first(n1),second(n2),third(n3){}
