CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: main.o Sorting.o
	$(CC) $(LFLAGS) -o main main.o Sorting.o 

main.o: main.cpp Sorting.h
	$(CC) $(CFLAGS) main.cpp

Sorting.o: Sorting.cpp Sorting.h
	$(CC) $(CFLAGS) Sorting.cpp

run: compile
	./main

clean:
	rm -f main
	rm -f *.o

