#pragma once
#include "../Header/stdafx.h"

class Game {
private:
	sf::RenderWindow window;
	void initWindow();

public:
	Game();
	virtual ~Game();

}; 
