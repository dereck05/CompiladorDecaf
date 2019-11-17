#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "VarObject.h"

using namespace std;

VarObject::VarObject(string t,string va,string val)
:tipo(t),identificador(va),valor(val){}
