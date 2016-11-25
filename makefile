# Compiler
CC = gcc

# Directories
BIN = bin/
SRC = src/
INCL = -Iinclude/

# Make commands
part1: inputModule.o sceneModule.o
	$(CC) $(INCL) -o bin/part1 src/part1.c build/inputModule.o build/sceneModule.o -lGL -lGLU -lglut

inputModule.o:
	$(CC) $(INCL) -c src/inputModule.c -o build/inputModule.o -lGL -lGLU -lglut

sceneModule.o:
	$(CC) $(INCL) -c src/sceneModule.c -o build/sceneModule.o -lGL -lGLU -lglut

clean:
	rm -f bin/* build/*
