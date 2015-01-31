CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated -framework GLUT -framework OpenGL -framework Cocoa
VPATH=Project/src/Common:Project/src/Demo
SOURCES=main.cpp Objects/ObjectPropertyTable.cpp Objects/ObjectTable.cpp Strings/StringTable.cpp Objects/Object.cpp Events/EventHandlerMap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -rf *.o