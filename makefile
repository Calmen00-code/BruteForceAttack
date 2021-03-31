CC = gcc
CFLAGS = -Werror -Wall -ansi -pedantic -g
OBJ = affine.o alphabet.o euclidean.o file.o main.o
EXEC = main

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c file.h header.h
	$(CC) $(CFLAGS) -c main.c

affine.o : affine.c affine.h alphabet.h euclidean.h header.h
	$(CC) $(CFLAGS) -c affine.c

alphabet.o : alphabet.c alphabet.h
	$(CC) $(CFLAGS) -c alphabet.c

euclidean.o : euclidean.c euclidean.h
	$(CC) $(CFLAGS) -c euclidean.c

file.o : file.c file.h header.h alphabet.h affine.h
	$(CC) $(CFLAGS) -c file.c

clean:
	rm -f $(OBJ) $(EXEC)
