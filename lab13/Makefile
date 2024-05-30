lib = lib/sorting.o
sort = sorting.o
exe1 = ds071
exe2 = ds072
exe3 = ds073
exe4 = ds074
exe5 = ds075
debug = -D_DEBUG

all: $(exe1) $(exe2) $(exe3) $(exe4) $(exe5)

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

lib/sorting.o: lib/sorting.cpp lib/sorting.h
	g++ -c lib/sorting.cpp -o lib/sorting.o $(debug) -I./lib

clean:
	rm -f $(exe1) $(exe2) $(exe3) $(exe4) $(exe5) lib/sorting.o