# CompiladorDecaf
El siguiente proyecto consiste en un scanner desarrollado en Flex y un parser desarrollado en Bison en lenguaje C++. Estos forman parte de las dos primeras partes de un compilador: el análisis lexico y análisis sintáctico. El análisis lexico forma la tabla de simbolos del scanner y el análisis sintáctico el arbol respectivo.

A continuación se presentan los pasos para ejecutar el programa:

1. Se debe instalar Flex, en la terminal de Linux se digitan los siguientes comandos:
  ```
  sudo apt-get update
  
  sudo apt-get install flex
  ```

2. Se debe instalar Bison, en la terminal de Linux se digitan los siguientes comandos:
  ```
  sudo apt-get install bison
  ```
3. Se debe de ingresar al directorio donde se encuentre el proyecto, el "Path" se debe especificar segun los directorios donde tenga guardado el proyecto:
  ```
  cd "Path"/CompiladorDecaf
  ```
4. A continuación, se digita los siguientes comandos en la terminal de Linux para ejecutar el proyecto:
  
  Se puede ejecutar utilizando en Makefile, digitando los siguientes comandos en la termianl de Linux:
  ```
  make
  ```
  Otra manera de ejecutar es digitar cada uno de los siguientes comandos:
  ```
  flex scannerDecaf.l
  
  bison -d parserDecaf.y
  
  g++ -o parserCP lex.yy.c parserDecaf.tab.c Nodo.cpp
  
  ./parserCP testFile
  ```
  
