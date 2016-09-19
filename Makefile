#!/usr/bin/make -f

.PHONY: all libspkg spkg

all : libspkg spkg

libspkg : 
	$(MAKE) -C libspkg


spkg :
	$(MAKE) -C spkg


clean :
	$(MAKE) -C libspkg clean
	$(MAKE) -C spkg clean
