lib = lib/sortingDebug.o
lib2 = lib/sorting.o
lib3 =lib/linkedListSorting.o
lib4 = lib/minHeap.o
debug = -D_DEBUG
exe1 = ds101
exe2 = ds102
exe3 = ds103
exe4 = ds104
exe5 = ds105
exe6 = ds106
exe7 = ds107	
exe8 = ds108
exe9 = ds109
exe10 = ds110


all : $(exe1) $(exe2) $(exe3) $(exe4) $(exe5) $(exe6) $(exe7) $(exe8) $(exe9) $(exe10)

$(exe1): $(exe1).cpp $(lib2)
	g++ -o $(exe1) $(exe1).cpp $(lib2) -I./lib 

$(exe2): $(exe2).cpp $(lib2)
	g++ -o $(exe2) $(exe2).cpp $(lib2) -I./lib 

$(exe3): $(exe3).cpp $(lib2)
	g++ -o $(exe3) $(exe3).cpp $(lib2) -I./lib 

$(exe4): $(exe4).cpp $(lib3)
	g++ -o $(exe4) $(exe4).cpp $(lib3) -I./lib 

$(exe5): $(exe5).cpp $(lib3)
	g++ -o $(exe5) $(exe5).cpp $(lib3) -I./lib 

$(exe6): $(exe6).cpp $(lib4)
	g++ -o $(exe6) $(exe6).cpp $(lib4) -I./lib 

ds107: ds107.cpp
	g++ -std=c++11 -o ds107 ds107.cpp

ds108: ds108.cpp
	g++ -std=c++11 -o ds108 ds108.cpp

ds109: ds109.cpp
	g++ -std=c++11 -o ds109 ds109.cpp

lib/sortingDebug.o: lib/sorting.cpp lib/sorting.h
	g++ -c lib/sorting.cpp -o lib/sortingDebug.o $(debug) -I./lib

lib/sorting.o: lib/sorting.cpp lib/sorting.h
	g++ -c lib/sorting.cpp -o lib/sorting.o -I./lib

lib/linkedListSorting.o: lib/linkedListSorting.cpp
	g++ -c lib/linkedListSorting.cpp -o lib/linkedListSorting.o

lib/minHeap.o: lib/minHeap.o
	g++ -c lib/minHeap.cpp -o lib/minHeap.o

clean: 
	rm -f  $(exe1) $(exe2) $(exe3) $(exe4) $(exe5) $(exe6) $(exe7) $(exe8) $(exe9) $(exe10) $(lib) $(lib2) $(lib3) $(lib4)