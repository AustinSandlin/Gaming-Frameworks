CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated
LDFLAGS=-framework GLUT -framework OpenGL -framework OpenAL -framework Cocoa
VPATH=../Engine/Audio:../Engine/Input:../Engine/Game:../Engine/Object:../Engine/Render
SOURCES=Test.cpp AudioController.cpp InputController.cpp GameController.cpp ObjectController.cpp RenderController.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test.exe

all: $(SOURCES) $(EXECUTABLE)
		$(MAKE) clean

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $<

clean:
		rm -rf *.o
