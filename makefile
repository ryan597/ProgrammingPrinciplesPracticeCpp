# Compilers
CXX= g++
# Compiler flags
# -g for debugging
# -Wall turns on compiler warnings
CPPFLAGS= -std=c++2a -Wall

# Linker flags
LINKERFLAG= -lm

# Directories and Files
SOURCEDIR:= $(wildcard Chapter*/)
BINDIR:= bin

SOURCES:= $(wildcard $(addsuffix *.cpp, $(SOURCEDIR)))
TARGETS:= $(patsubst %.cpp, %, $(SOURCES))

.PHONY: all
all: $(TARGETS)

$(TARGETS): %: %.cpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CPPFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS)
