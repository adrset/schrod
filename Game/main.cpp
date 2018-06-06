#include <cstdlib>
#include <string>
#include "Game.h"

int main(int argc, char** argv) {

	Game* game = new Game(1400, 800, "Potts", 1000);
	game->start();

	delete game;

	return 0;
}
