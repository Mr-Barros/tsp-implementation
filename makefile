CXXFLAGS = -Wall -std=c++23

OBJECTS = main.o types.o TSPInstance.o FileDecoder.o
EXECUTABLE = main

$(EXECUTABLE): $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)
	rm -f $(OBJECTS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
