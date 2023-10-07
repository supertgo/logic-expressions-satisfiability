CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/stack.h $(INC)/boolean_expressions.h $(INC)/binary_tree.h 
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/boolean_expressions.o $(OBJ)/binary_tree.o 
CFLAGS = -pg -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/main

all: run gprof

run: $(EXE)
	#$(EXE) -a "0|~ ~ 1" 01
	$(EXE) -s "0 | ~ ~ 1" ea

gprof: $(BIN)/main
	#$(EXE) -s "0 | 1 & 2 | ( 3 | 4 ) & 5 | 6 & 7 | ( 8 | 9 ) & 10 & 11 & 12 | 13 & 14 & 15 & 16 & 17 & 18 | 19 & 20 & 21 & 22 & 23 & 24 | 25 & 26 & 27 & 28 & 29 & 30 | 31 & 32 & 33 & 34 & 35 & 36 | 37 & 38 & 39 & 40 & 41 & 42 | 43 & 44 & 45 & 46 & 47 & 48 | 49 & 50 & 51 & 52 & 53 & 54 | 55 & 56 & 57 & 58 & 59 & 60 | 61 & 62 & 63 & 64 & 65 & 66 | 67 & 68 & 69 & 70 & 71 & 72 | 73 & (74 & 75 & 76 & (77 & 78 | 79 & 80) & 81 & 82 & 83 & 84) | ~~85 & 86 & ~(87 | 88) & 89 & 90 | 91 & 92 & 93 & 94 & 95 & (96 | 97) & 98 & 99 & ~100" eaaaa11111001a1000010aaaaaee0e000e1e111e01a100e00e011111001a1aae000011111001a100e000011111001a1aaaae
	$(EXE) -s "0 | 1 & 2 | ( 3 | 4 ) & 5 | 6 & 7 | ( 8 | 9 ) & 10 & 11 & 12 | 13 & 14 & 15 & 16 & 17 & 18 | 19 & 20 & 21 & 22 & 23 & 24 | 25 & 26 & 27 & 28 & 29 & 30 | 31 & 32 & 33 & 34 & 35 & 36 | 37 & 38 & 39 & 40 & 41 & 42 | 43 & 44 & 45 & 46 & 47 & 48 | 49 & 50 & 51 & 52 & 53 & 54 | 55 & 56 & 57 & 58 & 59 & 60 | 61 & 62 & 63 & 64 & 65 & 66 | 67 & 68 & 69 & 70 & 71 & 72 | 73 & (74 & 75 & 76 & (77 & 78 | 79 & 80) & 81 & 82 & 83 & 84) | ~~85 & 86 & ~(87 | 88) & 89 & 90 | 91 & 92 & 93 & 94 & 95 & (96 | 97) & 98 & 99 & ~100" eaaaa11111001a1ee0010aaaaaee0e0eee1e111e01a1eee0ee011111aaaa1aaeeeee11111001a1eee00001eee1001a1aaaae
	gprof $(EXE) gmon.out > /tmp/fib_gprof.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out
