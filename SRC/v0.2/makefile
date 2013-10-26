##DungeonCrawl by Gedas The Evil
CC=g++
RM=rm -f
CFLAGS=-c -Wall -pedantic -Xlinker -zmuldefs -o3 -march=native
CDFLAGS=-c -Wall -pedantic -Xlinker -zmuldefs
LDFLAGS= -lX11  -lglut -lGL -lGLU -lm -ldl -L/usr/X11R6/lib  `sdl-config --cflags --libs` -lSDL_mixer

SOURCES=main.cpp lib/caesar_string.cpp algorithms/caesar.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=evil_crypt

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(OBJECTSD)

