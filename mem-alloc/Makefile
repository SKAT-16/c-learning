CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -g

program: main.o mem_alloc.o
	$(CC) $(CFLAGS) -o program main.o mem_alloc.o

main: main.c mem_alloc.h
	$(CC) $(CFLAGS) -c main.c

mem_alloc: mem_alloc.c mem_alloc.h
	$(CC) $(CFLAGS) -c mem_alloc.c

valgrind: program
	valgrind --leak-check=full --track-origins=yes ./program

clean:
	rm -f program *.o