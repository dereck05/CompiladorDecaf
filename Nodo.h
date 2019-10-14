#ifndef NODO_H_
#define NODO_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
using namespace std;

class Nodo{
    private:
        string name;
        int fila;
        int columna;
    public:
        Nodo(string s,int f, int c);
};

#endif
