#include "../Header/stdafx.h"
#include "../Header/Game.h"

int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));

	Game game;

	while (game.getWindow().isOpen()) {
		game.update();
		game.render();
	}
	return 0;
}