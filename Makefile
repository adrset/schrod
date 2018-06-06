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

CCO=g++ -std=c++1z
CFLAGS=-Wall
CFLAGS_RELEASE=-Wall -O2
LIBS=-lglfw -lm -lGLEW -lGLU -lGL -lassimp
TARGET = game

$(TARGET):
	+$(MAKE) -C GameEngine
	+$(MAKE) -C Game
	+$(MAKE) -C build

clean:
				rm -f GameEngine/*.o Game/*.o build/*.o
				rm -f GameEngine/*.a Game/*.a build/*.a
				rm -f GameEngine/*.gch Game/*.gch build/*.gch
run:
				cd build && ./gameBinary
				cd ..


