all: Flex Bison Compile

Flex:
	flex scannerDecaf.l
Bison:
	bison -d parserDecaf.y
Compile:
	g++ -o parserCP lex.yy.c parserDecaf.tab.c -g Nodo.cpp  VarObject.cpp
