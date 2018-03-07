CC = g++ -std=c++11
CFLAGS =  -c -Wall -DDEBUG -g
LDFLAGS =

#COMMON_SOURCES = ch04_p3_median.cpp
COMMON_SOURCES =

P2_SOURCES = ch07_p2_countingwords.cpp
P3_SOURCES = ch07_p3_reftable.cpp ray_string.cpp
P4_SOURCES = ch07_p4_sentences.cpp ray_string.cpp
#E9_SOURCES = ch06_e9_catstring.cpp
#P8_SOURCES = ch05_p8_frame.cpp ray_string.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
P2_OBJECTS = $(P2_SOURCES:.cpp=.o)
P3_OBJECTS = $(P3_SOURCES:.cpp=.o)
P4_OBJECTS = $(P4_SOURCES:.cpp=.o)
#E9_OBJECTS = $(E9_SOURCES:.cpp=.o)
#P8_OBJECTS = $(P8_SOURCES:.cpp=.o)

P2_EXECUTABLE = ch07_p2_countingwords
P3_EXECUTABLE = ch07_p3_reftable
P4_EXECUTABLE = ch07_p4_sentences
#E9_EXECUTABLE = ch06_e9_catstring
#P8_EXECUTABLE = ch05_p8_frame

#.PHONY: all target tests

all: $(P2_EXECUTABLE) $(P3_EXECUTABLE) $(P4_EXECUTABLE)
	#$(E3_EXECUTABLE) $(E9_EXECUTABLE)

#P1: $(P1_EXECUTABLE)

#P2: $(P2_EXECUTABLE)

$(P2_EXECUTABLE): $(COMMON_OBJECTS) $(P2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P3_EXECUTABLE): $(COMMON_OBJECTS) $(P3_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(P4_EXECUTABLE): $(COMMON_OBJECTS) $(P4_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

#$(E9_EXECUTABLE): $(COMMON_OBJECTS) $(E9_OBJECTS)
#	$(CC) $(LDFLAGS) $^ -o $@
#
#$(P8_EXECUTABLE): $(COMMON_OBJECTS) $(P8_OBJECTS)
#	$(CC) $(LDFLAGS) $^ -o $@





.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o  

clean-all:
	rm -rf *.o $(P2_EXECUTABLE) $(P3_EXECUTABLE) $(P4_EXECUTABLE)


