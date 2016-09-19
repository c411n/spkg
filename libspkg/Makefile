#!/usr/bin/make -f

CC      = gcc
LIB_SRC = list.c utils.c
LIB_OBJ = list.o utils.o
SOLIB   = libspkg.so.1
CFLAGS  = -I.

libspkg : $(LIB_SRC)
	$(CC) $(CFLAGS) -Wall -fPIC -c $(LIB_SRC)
	$(CC) $(CFLAGS) -shared -Wl,--soname,$(SOLIB) -o $(SOLIB).0 $(LIB_OBJ)
	ln -svf $(SOLIB).0 $(SOLIB)
	ln -svf $(SOLIB).0 libspkg.so

clean :
	rm -f *.o libspkg.so*
