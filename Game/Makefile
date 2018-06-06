# GameEngine + Game makefile
# Author: Adrian Setniewski (https://github.com/adrset)
# Date: 10-08-2017

CC=g++ -std=c++1z -c -o
CCO=g++ -std=c++17
CFLAGS=-Wall
CFLAGS_RELEASE=-Wall -O3
LIBS=-lglfw -lm -lGLEW -lGLU -lGL -lassimp
INC=-I../ -I../include/
TARGET = game

$(TARGET): main.o Game.o move

main.o: main.cpp
	$(CC) -c $< -o $@ $(INC) $(CFLAGS_RELEASE)

Game.o: Game.cpp
	$(CC) -c $< -o $@ $(INC) $(CFLAGS_RELEASE)


move:
	mv Game.o ../build
	mv main.o ../build

# Cleanup

clean:
				rm -f *.o
				rm -f *.a
				rm -f *.gch
