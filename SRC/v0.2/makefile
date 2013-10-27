##DungeonCrawl by Gedas The Evil
CC=g++
RM=rm -f
CFLAGS=-c -Wall -pedantic -Xlinker -zmuldefs -o3 -march=native
CDFLAGS=-c -Wall -pedantic -Xlinker -zmuldefs
LDFLAGS=

SOURCES=main.cpp lib/caesar_string.cpp algorithms/caesar.cpp lib/file_utils.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=evil_crypt

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(OBJECTSD)

