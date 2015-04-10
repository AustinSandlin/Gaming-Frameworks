CC=g++
CFLAGS=-std=c++11 -Wall -Wno-deprecated
LDFLAGS=-framework GLUT -framework OpenGL -framework OpenAL -framework Cocoa
VPATH=../Engine/Audio:../Engine/Game:../Engine/Input:../Engine/Object:../Engine/Render:../Engine/Trigger:../Engine/Variable
SOURCES=Game.cpp AudioController.cpp GameController.cpp InputController.cpp ObjectController.cpp RenderController.cpp TriggerController.cpp VariableController.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
		$(MAKE) clean

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $<

clean:
		rm -rf *.o
