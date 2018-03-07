#CC = g++ -std=c++11
CC = g++ -std=c++1y
CFLAGS =  -c -Wall -DDEBUG -g
LDFLAGS =

P1_BASE = ch12_p1_teststr
E1_BASE = ch12_e1_teststrchar
P2_BASE = test

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P1_SOURCES = $(P1_BASE).cpp
E1_SOURCES = $(E1_BASE).cpp




COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P1_OBJECTS = $(P1_SOURCES:.cpp=.o)
E1_OBJECTS = $(E1_SOURCES:.cpp=.o)




P1_EXECUTABLE = $(P1_BASE)
E1_EXECUTABLE = $(E1_BASE)


#.PHONY: all target tests

all: $(P1_EXECUTABLE) $(E1_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P1_EXECUTABLE): $(COMMON_OBJECTS) $(P1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@
$(E1_EXECUTABLE): $(COMMON_OBJECTS) $(E1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@




.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(P1_EXECUTABLE) $(E1_EXECUTABLE)

