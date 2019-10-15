#include  <cstdio>
#include  <cstdlib>
#include  <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "Nodo.h"

using namespace std;

Nodo::Nodo(string s,int f, int c)
:nombre(s),fila(f),columna(c){}


/*int main(int argc, cha r** argv){
	Nodo a("a",1,2);
	printf("%i\n",a.makeDirectory("hola","hola"));
	cout << "hola";
	return 0;
}*/

