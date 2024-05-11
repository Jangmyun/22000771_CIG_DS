# make ds문제번호로 컴파일
ds041: ds041.cpp lib/mystack.o
	g++ -o ds041 ds041.cpp ./lib/mystack.o -I./lib

ds042: ds042.cpp  lib/mystack.o
	g++ -std=c++11 -o ds042 ds042.cpp ./lib/mystack.o -I./lib

ds043: ds043.cpp lib/mystack_char.o
	g++ -std=c++11 -o ds043 ds043.cpp ./lib/mystack_char.o -I./lib

mystack.o: lib/mystack.cpp lib/mystack.h
	g++ -c mystack.cpp

mystack_char.o: lib/mystack_char.cpp lib/mystack_char.h
	g++ -c mystack_char.cpp