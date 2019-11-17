#ifndef VAROBJECT_H_
#define VAROBJECT_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

class VarObject{
    public:
        string tipo;
        string identificador;
        string valor;

        VarObject(string,string,string);
        VarObject(){};
        virtual ~VarObject(){};
};

#endif
