all: ds081 ds082 ds083 binaryTree.o

ds081: ds081.cpp lib/binaryTree.o
	g++ -o ds081 ds081.cpp ./lib/binaryTree.o -I./lib

ds082: ds082.cpp lib/binaryTree.o
	g++ -o ds082 ds082.cpp ./lib/binaryTree.o -I./lib

ds083: ds083.cpp
	g++ -o ds083 ds083.cpp

binaryTree.o: lib/binaryTree.cpp lib/binaryTree.h
	g++ -c ./lib/binaryTree.cpp

clean: ds081 ds082 ds083
	rm ds081 ds082 ds083