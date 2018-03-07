# Usage: make FILE=p0001
BIN_DIR=./../bin/
FILE=
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(FILE).cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(BIN_DIR)$(FILE)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o  

clean-all:
	rm -rf *.o $(BIN_DIR)* 
