CC = g++
SRC = main.cpp card.cpp cardManager.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -std=c++11 -o $@ $^

%.o: %.cpp %.h
	$(CC) -std=c++11 -c $<

clean:
	rm -f $(OBJ) $(EXEC)