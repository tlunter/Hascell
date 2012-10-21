CC=g++
CFLAGS=-c -Wall -std=gnu++0x
LDFLAGS=
SRCDIR=src
OBJDIR=obj
BINDIR=build
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SOURCES))
EXECUTABLE=hascell

all: out $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BINDIR)/$@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

out:
	mkdir -p $(SRCDIR) $(OBJDIR) $(BINDIR)

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/hascell
