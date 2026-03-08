CXXFLAGS = -g -std=c++23 -Wall

OBJECTS = main.o types.o TSPInstance.o FileDecoder.o Graph.o
EXECUTABLE = main

build: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)
	rm -f $(OBJECTS)

debug: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
