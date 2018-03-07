CC = g++ -std=c++11
CFLAGS = -c -Wall -DDEBUG -g
LDFLAGS =

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P1_SOURCES = ch06_p1.cpp ray_string.cpp
P2_SOURCES = ch06_p2_studentgrades.cpp median.cpp grade.cpp Student_info.cpp average.cpp 
E3_SOURCES = ch06_e3.cpp
E9_SOURCES = ch06_e9_catstring.cpp
#P8_SOURCES = ch05_p8_frame.cpp ray_string.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P1_OBJECTS = $(P1_SOURCES:.cpp=.o)
P2_OBJECTS = $(P2_SOURCES:.cpp=.o)
E3_OBJECTS = $(E3_SOURCES:.cpp=.o)
E9_OBJECTS = $(E9_SOURCES:.cpp=.o)
#P8_OBJECTS = $(P8_SOURCES:.cpp=.o)

P1_EXECUTABLE = ch06_p1
P2_EXECUTABLE = ch06_p2_studentgrades
E3_EXECUTABLE = ch06_e3
E9_EXECUTABLE = ch06_e9_catstring
#P8_EXECUTABLE = ch05_p8_frame

#.PHONY: all target tests

all: $(P1_EXECUTABLE) $(P2_EXECUTABLE) $(E3_EXECUTABLE) $(E9_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P1_EXECUTABLE): $(COMMON_OBJECTS) $(P1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P2_EXECUTABLE): $(COMMON_OBJECTS) $(P2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E3_EXECUTABLE): $(COMMON_OBJECTS) $(E3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E9_EXECUTABLE): $(COMMON_OBJECTS) $(E9_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

#$(P8_EXECUTABLE): $(COMMON_OBJECTS) $(P8_OBJECTS)
#	$(CC) $(LDFLAGS) $^ -o $@





.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o  

clean-all:
	rm -rf *.o $(P1_EXECUTABLE) $(P2_EXECUTABLE) $(E3_EXECUTABLE) $(E9_EXECUTABLE)
	#$(P5_EXECUTABLE) $(P6_EXECUTABLE) $(P8_EXECUTABLE)


