CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/stack.h $(INC)/boolean_expressions.h $(INC)/binary_tree.h 
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/boolean_expressions.o $(OBJ)/binary_tree.o 
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/tp1.out

all: run

run: $(EXE)
	$(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 00000000001

$(BIN)/tp1.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp1.out $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
