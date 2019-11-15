#ifndef NODO_H_
#define NODO_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>

using namespace std;

class Nodo{
    public:
        string nombre;
        int fila;
        int columna;
	      string valor;
        vector<Nodo *> first;
        vector<Nodo *>second;
        vector<Nodo*> third;

    public:
        Nodo(string s,int f, int c,string v,Nodo*,Nodo*,Nodo*);
        Nodo(){};
        virtual ~Nodo(){};
};

#endif
