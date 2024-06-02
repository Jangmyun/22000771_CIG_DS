lib = lib/sortingDebug.o
lib2 = lib/sorting.o
lib3 = lib/linkedListSorting.o
sort = sorting.o
exe1 = ds071
exe2 = ds072
exe3 = ds073
exe4 = ds074
exe5 = ds075
exe6 = ds076

exe11 = ds101
exe12 = ds102
exe13 = ds103
exe14 = ds104
exe15 = ds105
debug = -D_DEBUG

all: $(exe1) $(exe2) $(exe3) $(exe4) $(exe5) $(exe6) $(exe11) $(exe12) $(exe13) $(exe14) $(exe15)

$(exe1): $(exe1).cpp $(lib)
	g++ -o $(exe1) $(exe1).cpp $(lib) -I./lib $(debug)

$(exe2): $(exe2).cpp $(lib)
	g++ -o $(exe2) $(exe2).cpp $(lib) -I./lib $(debug)

$(exe3): $(exe3).cpp $(lib)
	g++ -o $(exe3) $(exe3).cpp $(lib) -I./lib $(debug)

$(exe4): $(exe4).cpp $(lib)
	g++ -o $(exe4) $(exe4).cpp $(lib) -I./lib $(debug)

$(exe5): $(exe5).cpp $(lib)
	g++ -o $(exe5) $(exe5).cpp $(lib) -I./lib $(debug)

$(exe6): $(exe6).cpp $(lib)
	g++ -o $(exe6) $(exe6).cpp $(lib) -I./lib $(debug)

$(exe11): $(exe11).cpp $(lib2)
	g++ -o $(exe11) $(exe11).cpp $(lib2) -I./lib 

$(exe12): $(exe12).cpp $(lib2)
	g++ -o $(exe12) $(exe12).cpp $(lib2) -I./lib 

$(exe13): $(exe13).cpp $(lib2)
	g++ -o $(exe13) $(exe13).cpp $(lib2) -I./lib 

$(exe14): $(exe14).cpp $(lib3)
	g++ -o $(exe14) $(exe14).cpp $(lib3) -I./lib 

$(exe15): $(exe15).cpp $(lib3)
	g++ -o $(exe15) $(exe15).cpp $(lib3) -I./lib 

lib/sortingDebug.o: lib/sorting.cpp lib/sorting.h
	g++ -c lib/sorting.cpp -o lib/sortingDebug.o $(debug) -I./lib

lib/sorting.o: lib/sorting.cpp lib/sorting.h
	g++ -c lib/sorting.cpp -o lib/sorting.o -I./lib

lib/linkedListSorting.o: lib/linkedListSorting.cpp
	g++ -c lib/linkedListSorting.cpp -o lib/linkedListSorting.o

clean:
	rm -f $(exe1) $(exe2) $(exe3) $(exe4) $(exe5) $(exe6) $(exe11) $(exe12) $(exe13) $(exe14) $(exe15) lib/sorting.o lib/sortingDebug.o
