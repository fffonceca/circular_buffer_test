CC=gcc
CFLAGS=-I.
DEPS = cbuffer.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o cbuffer.o 
	$(CC) -o main main.o cbuffer.o
