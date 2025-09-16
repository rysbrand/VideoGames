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

	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void updatePlayer();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
	
}; 
