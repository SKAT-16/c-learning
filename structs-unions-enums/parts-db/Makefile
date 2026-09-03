CC = gcc
CFLAGS = --std=c99 -Wall -Wextra -Werror -pedantic-errors

parts_db: inventory.o read_line.o
	$(CC) $(CFLAGS) -o parts_db inventory.o read_line.o
inventory.o: inventory.c read_line.h
	$(CC) $(CFLAGS) -c inventory.c
read_line.o: read_line.c read_line.h
	$(CC) $(CFLAGS) -c read_line.c

clean:
	rm -f parts_db *.o