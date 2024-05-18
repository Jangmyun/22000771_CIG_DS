ds051: ds051.cpp  lib/myqueue.o
	g++ -o ds051 ds051.cpp lib/myqueue.o -I./lib

ds052: ds052.cpp  lib/myqueue.o
	g++ -o ds052  ds052.cpp lib/myqueue.o -I./lib

ds053: ds053.cpp lib/myqueue.o
	g++ ds053.cpp -o ds053 lib/myqueue.o -I./lib

myqueue.o: lib/myqueue.cpp lib/myqueue.h
	g++ -c ./lib/myqueue.cpp

rm: ds051 ds052 ds053
	rm ds051 ds052 ds053