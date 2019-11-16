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
        char* tipo;
        char* identificador;
	      char* valor;
        Nodo * first;
        Nodo * second;
        Nodo* third;

    public:
        Nodo(string s,int f, int c,char*tipo,char* ident,char* v,Nodo*,Nodo*,Nodo*);
        Nodo(){};
        virtual ~Nodo(){};
};

#endif
