CC = g++
CFLAGS = -c -Wall -DDEBUG -g
LDFLAGS =

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P1_SOURCES = ch04_p1_StudentGrades.cpp
P2_SOURCES = ch04_p2_StudentInfo.cpp median.cpp
P3_SOURCES = ch04_p5_studentgrades.cpp median.cpp grade.cpp Student_info.cpp
E2_SOURCES = ch04_e2_squareint.cpp
E3_SOURCES = ch04_e3_squareint.cpp
E4_SOURCES = ch04_e4_squareint.cpp
E5_SOURCES = ch04_e5_wordcount.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P1_OBJECTS = $(P1_SOURCES:.cpp=.o)
P2_OBJECTS = $(P2_SOURCES:.cpp=.o)
P3_OBJECTS = $(P3_SOURCES:.cpp=.o)
E2_OBJECTS = $(E2_SOURCES:.cpp=.o)
E3_OBJECTS = $(E3_SOURCES:.cpp=.o)
E4_OBJECTS = $(E4_SOURCES:.cpp=.o)
E5_OBJECTS = $(E5_SOURCES:.cpp=.o)

P1_EXECUTABLE = ch04_p1_StudentGrades
P2_EXECUTABLE = ch04_p2_StudentInfo
P3_EXECUTABLE = ch04_p5_studentgrades
E2_EXECUTABLE = ch04_e2_squareint
E3_EXECUTABLE = ch04_e3_squareint
E4_EXECUTABLE = ch04_e4_squareint
E5_EXECUTABLE = ch04_e5_wordcount

#.PHONY: all target tests

all: $(P1_EXECUTABLE) $(P2_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P1_EXECUTABLE): $(COMMON_OBJECTS) $(P1_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P2_EXECUTABLE): $(COMMON_OBJECTS) $(P2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P3_EXECUTABLE): $(COMMON_OBJECTS) $(P3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E2_EXECUTABLE): $(COMMON_OBJECTS) $(E2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E3_EXECUTABLE): $(COMMON_OBJECTS) $(E3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E4_EXECUTABLE): $(COMMON_OBJECTS) $(E4_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(E5_EXECUTABLE): $(COMMON_OBJECTS) $(E5_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@








.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o  

clean-all:
	rm -rf *.o $(P1_EXECUTABLE) $(P2_EXECUTABLE) $(P3_EXECUTABLE) \
	$(E2_EXECUTABLE) $(E3_EXECUTABLE) $(E4_EXECUTABLE) $(E5_EXECUTABLE)


