CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
SOURCES=main.cpp cdragon.cpp  cdragon.hpp  dragon.cpp  dragon.hpp  fdragon.cpp  fdragon.hpp  mdragon.cpp  mdragon.hpp 
OBJECTS=main.o cdragon.o dragon.o fdragon.o mdragon.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cpp.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main
