all: Flex Bison Compile Run

Flex:
	flex scannerDecaf.l
Bison:
	bison -d parserDecaf.y
Compile: 
	g++ -o parserCP lex.yy.c parserDecaf.tab.c Nodo.cpp
Run:
	./parserCP testFile
