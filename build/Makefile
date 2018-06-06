# GameEngine + Game makefile
# Author: Adrian Setniewski (https://github.com/adrset)
# Date: 10-08-2017
# Prerequisites
#	Operation System: Linux, preferably Debian, Ubuntu based.
#	Compiler: Latest GNU GCC compiler
# 	Libs:
#		glfw3 - Lightweight multiplatform library for OpenGL.
#		glew - OpenGL extension wrangler library.
#		glm - OpenGL mathematics library.
#		assimp - 3D object loader and more.
#
# Explaination:
# $@ means the target
# $^ means all prerequisites
# $< means only the first prerequisite


OS := $(shell uname -s)
CC=g++ -std=c++17 -c -o
CCO=g++ -std=c++17 -o
CFLAGS=-Wall
CFLAGS_RELEASE=-Wall -O3
LIBS_MAC=-lglfw -lm -lGLEW -framework OpenGL
LIBS=-lglfw -lm -lGLEW -lGL -ldl
TARGET = game

$(TARGET): final

final:
ifeq ($(OS), Darwin)
	$(CCO) gameBinary main.o Game.o GameEngine.a $(LIBS_MAC) $(CFLAGS_RELEASE)
endif
ifeq ($(OS), Linux)
	$(CCO) gameBinary main.o Game.o -L. -l:GameEngine.a $(LIBS) $(CFLAGS_RELEASE)
else
	$(Linux and Darwin supported!)

endif
clean:
				rm -f *.o
				rm -f *.a
				rm -f *.gch
