CC := g++
TARGET := bin/run
VPATH = build src
OBJECTS = main.o mkdisk.o parser.o

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

build/main.o: main.cpp
	$(CC) -c $< -o $@

build/mkdisk.o: mkdisk.cpp
	$(CC) -c $< -o $@

build/parser.o: parser.cpp
	$(CC) -c $< -o $@
clean:
	rm -rf buid $(TARGET)

.PHONY: clean