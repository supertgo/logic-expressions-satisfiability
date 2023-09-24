
CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/boolean_expressions.h
CFLAGS = -pg -Wall -g -c -I$(INC)

EXE = $(BIN)/main
TESTS = $(BIN)/tests

run: $(EXE)
	$(EXE) −s "0 | 1 & 2" eee

tests: $(TESTS)
	$(TESTS)

$(BIN)/main: $(OBJ)/main.o $(OBJ)/boolean_expressions.o
	$(CC) -pg -g -o $(BIN)/main $(OBJ)/main.o $(OBJ)/boolean_expressions.o $(LIBS)

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/boolean_expressions.o
	$(CC) -pg -g -o $(BIN)/tests $(OBJ)/tests.o $(OBJ)/boolean_expressions.o $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/tests.o: $(HDRS) $(SRC)/tests.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tests.o $(SRC)/tests.cpp

$(OBJ)/boolean_expressions.o: $(HDRS) $(SRC)/boolean_expressions.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/boolean_expressions.o $(SRC)/boolean_expressions.cpp

clean:
	rm -f $(EXE) $(TESTS) $(OBJ)/*.o gmon.out
