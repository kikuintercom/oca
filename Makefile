CC=g++
CFLAGS=-c -std=c++11 -Wall
INCLUDEDIR=Include/

all:
	$(CC) src/OcaBuildMe.cpp -I$(INCLUDEDIR) $(CFLAGS)

clean:
	rm -f *.o
