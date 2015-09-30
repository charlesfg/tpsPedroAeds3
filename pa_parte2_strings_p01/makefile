### tp 0 - makefile ###

# the compiler: gcc for C program, g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

# target program
PROG1 = pap01

# source files
SRC1 = main.c
SRC2 = lista.c
SRC3 = anagramas.c

all: $(PROG1)

$(PROG1): $(SRC1) 
	$(CC) $(CFLAGS) $(SRC1) -o $(PROG1) 

run: all
	cat entrada.txt | ./$(PROG1)
clean:
	rm -f *.o*~ $(PROG1)
