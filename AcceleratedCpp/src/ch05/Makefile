CC = g++
CFLAGS = -c -Wall -DDEBUG -g
LDFLAGS =

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P1_SOURCES = ch05_p1_studentgrades.cpp median.cpp grade.cpp Student_info.cpp
P3_SOURCES = ch05_p3_studentgrades.cpp median.cpp grade.cpp Student_info.cpp
P5_SOURCES = ch05_p5_studentgrades.cpp median.cpp grade.cpp Student_info.cpp
P6_SOURCES = ch05_p6_splitstring.cpp ray_string.cpp
P8_SOURCES = ch05_p8_frame.cpp ray_string.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P1_OBJECTS = $(P1_SOURCES:.cpp=.o)
P3_OBJECTS = $(P3_SOURCES:.cpp=.o)
P5_OBJECTS = $(P5_SOURCES:.cpp=.o)
P6_OBJECTS = $(P6_SOURCES:.cpp=.o)
P8_OBJECTS = $(P8_SOURCES:.cpp=.o)

P1_EXECUTABLE = ch05_p1_studentgrades
P3_EXECUTABLE = ch05_p3_studentgrades
P5_EXECUTABLE = ch05_p5_studentgrades
P6_EXECUTABLE = ch05_p6_splitstring
P8_EXECUTABLE = ch05_p8_frame

#.PHONY: all target tests

all: $(P1_EXECUTABLE) $(P3_EXECUTABLE) $(P5_EXECUTABLE) $(P6_EXECUTABLE) $(P8_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P1_EXECUTABLE): $(COMMON_OBJECTS) $(P1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P3_EXECUTABLE): $(COMMON_OBJECTS) $(P3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P5_EXECUTABLE): $(COMMON_OBJECTS) $(P5_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P6_EXECUTABLE): $(COMMON_OBJECTS) $(P6_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P8_EXECUTABLE): $(COMMON_OBJECTS) $(P8_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@





.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o  

clean-all:
	rm -rf *.o $(P1_EXECUTABLE) $(P3_EXECUTABLE) $(P5_EXECUTABLE) $(P6_EXECUTABLE) $(P8_EXECUTABLE)


