CC=g++
CFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
SOURCES=main.cpp first.cpp first.hpp
OBJECTS=main.o first.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main
