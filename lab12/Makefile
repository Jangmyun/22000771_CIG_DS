all: ds061 ds062 ds063

ds061: ds061.cpp lib/linkedlistq.o
	g++ -o ds061 ds061.cpp ./lib/linkedlistq.o -I./lib

ds062: ds062.cpp lib/linkedlistq.o
	g++ -o ds062 ds062.cpp ./lib/linkedlistq.o -I./lib

ds063: ds063.cpp lib/linkedlistq.o
	g++ -o ds063 ds063.cpp ./lib/linkedlistq.o -I./lib

linkedlistq.o: lib/linkedlistq.cpp lib/linkedlistq.h
	g++ -c ./lib/linkedlistq.cpp

clean: ds061 ds062 ds063
	rm ds061 ds062 ds063