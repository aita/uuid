CC = gcc

# Makefile for uuid.c
example: example.c uuid.c
	$(CC) -Wall -o $@ $^

clean:
	rm -f example *.o
