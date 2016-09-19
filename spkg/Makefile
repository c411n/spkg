#!/usr/bin/make -f

CC = gcc
SPKG_SRC = main.c spkg.c
SPKG_OBJ = main.o spkg.o
SPKG_CFLAGS = -I. -I../libspkg -L../libspkg -lspkg
SPKG_BINARY = spkg

all : binaries

binaries : $(SPKG_OBJ)
	$(CC) $(SPKG_CFLAGS) -o $(SPKG_BINARY) $(SPKG_OBJ)

clean :
	rm -f *.o $(SPKG_BINARY)
