#Compilador
CC=gcc

#Flags do Compilador
CFLAGS=-Wall -ansi -O3

iamroot: main.o util.o
	$(CC) $(CFLAGS) -o iamroot main.o util.o

main.o: main.c util.o
	$(CC) -c $(CFLAGS) main.c

util.o: util.c util.h
	$(CC) -c $(CFLAGS) util.c


clean:
	    rm -f *.o core a.out iamroot *~
