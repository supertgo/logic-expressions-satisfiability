CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/stack.h $(INC)/boolean_expressions.h $(INC)/binary_tree.h 
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/boolean_expressions.o $(OBJ)/binary_tree.o 
CFLAGS = -pg -Wall -g -c -I$(INC)
EXE = $(BIN)/main

all: run

run: $(EXE)
	$(EXE) -s "( 0 | 1 ) & 2" ee0

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
