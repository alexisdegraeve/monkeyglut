CC=gcc
CFLAGS= -std=c99 -Wall -lGL -lGLU -lglut -lSOIL
SOURCES=main.c menu.c controlplayer.c controldisplay.c readimage.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=jumpb

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) $(CFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	-rm -f -R *.o
	-rm -f -R $(EXECUTABLE)
