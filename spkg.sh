#!/bin/bash

export LD_LIBRARY_PATH=./libspkg

if [ -e spkg/spkg ]
then
	./spkg/spkg $@
else
	printf '"%s" executable not found\n' 'spkg'
	exit 1
fi

exit $?
