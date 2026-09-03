CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic-errors

rpn: calc.o scanner.o parser.o read_line.o stack.o
	$(CC) $(CFLAGS) -o rpn calc.o scanner.o read_line.o stack.o
calc.o: calc.c scanner.h read_line.h
	$(CC) $(CFLAGS) -c calc.c
scanner.o: scanner.c scanner.h token.h stack.h
	$(CC) $(CFLAGS) -c scanner.c
parser.o: parser.c parser.h stack.h token.h
	$(CC) $(CFLAGS) -c parser.c
read_line.o: read_line.c read_line.h
	$(CC) $(CFLAGS) -c read_line.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f rpn *.o