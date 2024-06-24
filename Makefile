CC = g++
CFLAGS =

all: task clean

task: main.o scanner.o
	$(CC) $(CFLAGS) main.o scanner.o -o task

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

scanner.o: scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c scanner.cpp -o scanner.o

clean:
	rm -f *.o
