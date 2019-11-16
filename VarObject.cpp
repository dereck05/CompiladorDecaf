#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "VarObject.h"

using namespace std;

Nodo::VarObject(string n,string t,string va,string val)
:name(n),tipo(t),identificador(va),valor(val){}
