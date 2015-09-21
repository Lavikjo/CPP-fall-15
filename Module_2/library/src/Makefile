CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
SOURCES=main.cpp book.cpp book.hpp customer.cpp customer.hpp library.cpp library.hpp
OBJECTS=main.o book.o customer.o library.o
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
