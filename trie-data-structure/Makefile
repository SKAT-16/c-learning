CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic-errors -g

program: main.o trie.o
	$(CC) $(CFLAGS) -o program main.o trie.o

main.o: main.c trie.h
	$(CC) $(CFLAGS) -c main.c
	
trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

test: program
	valgrind --leak-check=full --error-exitcode=1 ./program

clean:
	rm -f program *.o