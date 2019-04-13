# Makefile for project 4
#
# You should not modify this file.

CC		= gcc

CFLAGS		= -g  -Og  -Wall -std=c99

all:  problem2

problem2: given/problem2.o functions2.o given/functions2.h
	$(CC) $(CFLAGS) -o problem2 given/problem2.o functions2.o

functions.o: foo.c given/functions2.h
	$(CC) $(CFLAGS) -c functions2.c

run_problem2: problem2
	./problem2

clean:
	rm -f *~ *.o a.out core  problem2 functions2.o
