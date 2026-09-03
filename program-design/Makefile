CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic-errors

program: test.o queue.o
	$(CC) $(CFLAGS) -o program test.o queue.o

test.o: test.c queue.h
	$(CC) $(CFLAGS) -c test.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f program *.o