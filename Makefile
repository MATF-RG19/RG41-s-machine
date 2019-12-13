CXX=g++
CC=gcc
CFLAGS=-c
LDLIBS=-lglut -lGL -lGLU

#Opcije koje su potrebne za povezivanje sa muzikom
OPTS =  -I"irrKlangLib/include" -L"/usr/lib" irrKlangLib/bin/linux-gcc-64/libIrrKlang.so -pthread

PROGRAM=slotMachine
OBJECTS=s-machine.o drawFunction.o slotFunction.o image.o 
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(LDLIBS) $(OPTS)

s-machine.o: s-machine.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) s-machine.cpp 

drawFunction.o: drawFunction.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) drawFunction.cpp

slotFunction.o: slotFunction.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) slotFunction.cpp
	
image.o: image.c
	$(CC) $(CFLAGS) image.c 

clean:
	rm -rf *o program

