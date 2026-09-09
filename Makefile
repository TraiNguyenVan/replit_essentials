CXX      := g++

CXXFLAGS := -std=c++17 -Wall -O2 -Iinclude


SRCDIR   := ./src
BUILDDIR := build/cpp
TARGET   := $(BUILDDIR)/demo
SRC      := $(wildcard $(SRCDIR)/*.cpp)
HEADERS  := $(wildcard include/*.hpp)

all: $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(SRC) $(HEADERS) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	python3 script/generate_dataset.py
	./$(TARGET) < data/dataset.txt

clean:
	rm -rf $(BUILDDIR)

.PHONY: all run clean