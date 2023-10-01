CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/stack.h $(INC)/boolean_expressions.h $(INC)/string.h $(INC)/binary_tree.h 
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/boolean_expressions.o $(OBJ)/string.o $(OBJ)/binary_tree.o 
CFLAGS = -pg -Wall -g -c -I$(INC)
EXE = $(BIN)/main

run: $(EXE)
	$(EXE) -s "( 0 | 1 ) & 2" ee0

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $@ $^ $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
