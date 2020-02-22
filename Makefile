CC=gcc
CFLAGS=-std=c99 -Wall -pedantic

all: lang-parser

lang-parser: main.c csv.c
	$(CC) $(CFLAGS) -o $@ $^
	echo "Lang parser get built successfully!"

clean:
	$(RM) lang-parser *.o