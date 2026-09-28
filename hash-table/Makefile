CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic-errors -g

program: main.o hash.o
	$(CC) $(CFLAGS) -o program main.o hash.o

main.o: main.c hash.h
	$(CC) $(CFLAGS) -c main.c
	
hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

valgrind: program
	valgrind --leak-check=full --track-origins=yes ./program

clean:
	rm -f program *.o