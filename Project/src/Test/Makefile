CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated -I /usr/local/Cellar/boost/1.56.0/include
LDFLAGS=-framework GLUT -framework OpenGL -framework Cocoa
VPATH=../Engine/Input:../Engine/Game:../Engine/Object
SOURCES=Test.cpp InputController.cpp GameController.cpp ObjectController.cpp
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
