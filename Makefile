CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o 
HDRS = 
CFLAGS = -pg -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) −a "(1 | 0) & 1" 01

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
