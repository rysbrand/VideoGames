#pragma once
#include "../Header/stdafx.h"
#include "../Header/Player.h"

class Game {
private:

	sf::RenderWindow window;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void updatePlayer();
	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
	
}; 
