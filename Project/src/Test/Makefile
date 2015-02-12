CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated -I /usr/local/Cellar/boost/1.56.0/include
LDFLAGS=-framework Cocoa -framework OpenGL
VPATH=../Engine/
SOURCES=Test.cpp Input/View.cpp Input/Controller.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
		$(MAKE) clean

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $<

clean:
		rm -rf *.o
