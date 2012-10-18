CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Showable.cpp String.cpp Monad.cpp Maybe.cpp Enum.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hascell
BINDIR=build/

all: out $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BINDIR)$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

out:
	mkdir -p $(BINDIR)

clean:
	rm -rf *.o hascell
