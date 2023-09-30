
CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/boolean_expressions.h $(INC)/string.h $(INC)/binary_tree.h
CFLAGS = -pg -Wall -g -c -I $(INC) -std=c++11

EXE = $(BIN)/main
TESTS = $(BIN)/tests

run: $(EXE)
	$(EXE) -s "0 | 1 & 2 " aaa
	$(EXE) -s "0 | 1 & 2 " a1a
	$(EXE) -s "0 | 1 & 2 | ( 3 | 4 )" e11ee
	$(EXE) -s "0 | 1 & 2 | ( 3 | 4 )" a11aa
	$(EXE) -s "0 | 1 & 2 " 0e0
	$(EXE) -s "0 | 1 & 2 " e00
	$(EXE) -s "0 | 1 & 2 " e11

tests: $(TESTS)
	$(TESTS)

$(BIN)/main: $(OBJ)/main.o $(OBJ)/boolean_expressions.o $(OBJ)/string.o $(OBJ)/binary_tree.o
	$(CC) -pg -g -o $(BIN)/main $(OBJ)/main.o $(OBJ)/boolean_expressions.o $(OBJ)/string.o $(OBJ)/binary_tree.o $(LIBS)

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/boolean_expressions.o $(OBJ)/binary_tree.o
	$(CC) -pg -g -o $(BIN)/tests $(OBJ)/tests.o $(OBJ)/boolean_expressions.o $(OBJ)/binary_tree.o $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/tests.o: $(HDRS) $(SRC)/tests.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tests.o $(SRC)/tests.cpp

$(OBJ)/boolean_expressions.o: $(HDRS) $(SRC)/boolean_expressions.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/boolean_expressions.o $(SRC)/boolean_expressions.cpp

$(OBJ)/string.o: $(HDRS) $(SRC)/string.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/string.o $(SRC)/string.cpp

$(OBJ)/binary_tree.o: $(HDRS) $(SRC)/binary_tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/binary_tree.o $(SRC)/binary_tree.cpp

clean:
	rm -f $(EXE) $(TESTS) $(OBJ)/*.o gmon.out
