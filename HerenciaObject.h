#ifndef HERENCIAOBJECT_H_
#define HERENCIAOBJECT_H_

#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>


using namespace std;

class HerenciaObject{
    public:
        string nombre;
        std::vector<string> clases;

    public:
        HerenciaObject(string nombre,std::vector<string> clases);
        HerenciaObject(){};
        virtual ~HerenciaObject(){};
};

#endif
