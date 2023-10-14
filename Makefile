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

$(BIN)/tp1.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp1.out $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
