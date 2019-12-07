CXX=g++
CC=gcc
CFLAGS=-c
LDLIBS=-lglut -lGL -lGLU

PROGRAM=slotMachine
OBJECTS=s-machine.o drawFunction.o image.o
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(LDLIBS)

s-machine.o: s-machine.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) s-machine.cpp

drawFunction.o: drawFunction.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) drawFunction.cpp

image.o: image.c
	$(CC) $(CFLAGS) image.c 

clean:
	rm -rf *o program

