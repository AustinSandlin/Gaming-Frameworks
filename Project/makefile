CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated -framework GLUT -framework OpenGL -framework Cocoa
VPATH=src/Common:src/Demo:src/Engine
SOURCES=Events/EventHandlerMap.cpp Objects/Object.cpp Objects/ObjectPropertyTable.cpp Objects/ObjectTable.cpp Strings/StringTable.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -rf *o hello