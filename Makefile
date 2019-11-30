CXX=g++
CFLAGS=-c
LDLIBS=-lglut -lGL -lGLU

PROGRAM=slotMachine
OBJECTS=s-machine.o drawFunction.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(LDLIBS)

s-machine.o: s-machine.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) s-machine.cpp

drawFunction.o: drawFunction.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) drawFunction.cpp

clean:
	rm -rf *o program

