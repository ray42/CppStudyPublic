#CC = g++ -std=c++11
CC = g++ -std=c++1y
CFLAGS =  -c -Wall -DDEBUG -g
LDFLAGS =

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P1_SOURCES = ch08_p1_studentgrades.cpp average.cpp grade.cpp Student_info.cpp
P2_SOURCES = ch08_p1_2_template.cpp 
P3_SOURCES = ch08_p2_iterator_categories.cpp 

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P1_OBJECTS = $(P1_SOURCES:.cpp=.o)
P2_OBJECTS = $(P2_SOURCES:.cpp=.o)
P3_OBJECTS = $(P3_SOURCES:.cpp=.o)

P1_EXECUTABLE = ch08_p1_studentgrades
P2_EXECUTABLE = ch08_p1_2_template
P3_EXECUTABLE = ch08_p2_iterator_categories

#.PHONY: all target tests

all: $(P1_EXECUTABLE) $(P2_EXECUTABLE) $(P3_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P1_EXECUTABLE): $(COMMON_OBJECTS) $(P1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P2_EXECUTABLE): $(COMMON_OBJECTS) $(P2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P3_EXECUTABLE): $(COMMON_OBJECTS) $(P3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@



.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(P1_EXECUTABLE) $(P2_EXECUTABLE) $(P3_EXECUTABLE)

