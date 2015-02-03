CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated -I /usr/local/Cellar/boost/1.56.0/include
LDFLAGS=-framework GLUT -framework OpenGL -framework Cocoa
VPATH=Project/src/Common/Objects:Project/src/Common/Strings:Project/src/Common/Events:Project/src/Demo
SOURCES=main.cpp ObjectPropertyTable.cpp ObjectTable.cpp StringTable.cpp Object.cpp EventHandlerMap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
		$(MAKE) clean

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $<

clean:
		rm -rf *.o