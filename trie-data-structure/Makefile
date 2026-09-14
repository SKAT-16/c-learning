CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic-errors

program: trie.o
	$(CC) $(CFLAGS) -o program trie.o
	
trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

clean:
	rm -f program *.o