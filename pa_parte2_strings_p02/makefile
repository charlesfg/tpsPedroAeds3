### pa_parte2_strings_p02 - makefile ###

# the compiler: gcc for C program, g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

# target program
PROG1 = pa22

# source files
SRC1 = main.c

# input files
INP1 = entrada.txt

all: $(PROG1)

$(PROG1): $(SRC1)
	$(CC) $(CFLAGS) $(SRC1) -o $(PROG1) 

run: all
	cat $(INP1) | ./$(PROG1)
clean:
	rm -f *.o*~ $(PROG1)
