CC=g++
GCCVERSIONGTEQ4 := $(shell expr `gcc -dumpversion | cut -f1,2 -d. ` \>= 4.7)
DIR := ${CURDIR}/

ifeq ("$(GCCVERSIONGTEQ4)","0")
	STD=c++0x
else
	STD=c++11
endif

INCLUDEDIR=$(DIR)include/
CFLAGS=-c -I$(INCLUDEDIR) -std=$(STD) -Wall

all:
	$(CC) $(DIR)src/OcaBuildMe.cpp $(CFLAGS)

clean:
	rm -f *.o
