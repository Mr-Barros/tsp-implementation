CXXFLAGS = -g -std=c++23 -Wall

OBJECTS = src/main.o src/types.o src/Graph.o src/Multigraph.o src/FileDecoder.o src/TSPInstance.o src/Solution.o
EXECUTABLE = main

build: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)
	rm -f $(OBJECTS)

debug: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
