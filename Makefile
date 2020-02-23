CC=gcc
CFLAGS=-std=c99 -Wall -pedantic

all: lang-parser

lang-parser: main.c csv.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) lang-parser *.o