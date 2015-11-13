### tp 2 - makefile ###

# the compiler: gcc for C program, g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -lm	 math.h
CFLAGS = -g -Wall

# target program
PROG1 = tp2

# source files
SRC1 = main.c
SRC2 = pd.c
SRC3 = ag.c
SRC4 = fb.c

# paradigm type: PD = 1, AG = 2, FB = 3


# input files
INP1 = entrada.txt

# output files (optional) --> insert ./$(PROG1) > $(OUT1)
OUT1 = saida.txt

all: $(PROG1)

$(PROG1): $(SRC1) $(SRC2) $(SRC3) $(SRC4)
	$(CC) $(CFLAGS) $(SRC1) $(SRC2) $(SRC3) $(SRC4) -o $(PROG1) 

run: all
	cat $(INP1) | ./$(PROG1)
clean:
	rm -f *.o*~ $(PROG1)
