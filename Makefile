CXX=g++
CFLAGS=-c
LDLIBS=-lglut -lGL -lGLU

objects=s-machine.o drawFunction.o

all: slotMachine

slotMachine: $(objects)
	$(CXX) -o slotMachine $(objects) $(LDLIBS)

s-machine.o: s-machine.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) s-machine.cpp

drawFunction.o: drawFunction.cpp
	$(CXX) $(CFLAGS) $(LDLIBS) drawFunction.cpp

clean:
	rm -rf *o program

