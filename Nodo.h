#ifndef NODO_H_
#define NODO_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

class Nodo{
    public:
        string nombre;
        int fila;
        int columna;
	string valor;
    public:
        Nodo(string s,int f, int c,string v);
};

#endif
