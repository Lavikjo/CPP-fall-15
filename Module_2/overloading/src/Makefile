CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
SOURCES=main.cpp overload.cpp overload.hpp
OBJECTS=main.o overload.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cc.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main
