#pragma once
#include "../Header/stdafx.h"

class Player 
{

private:
	sf::Texture textureSheet;
	sf::Sprite sprite;

	//any future animation goes here

	//movement goes here

	//core values

	void initTexture();
	void initSprite();


public:

	Player();
	virtual ~Player();

	//function

	void update();
	void render(sf::RenderTarget& target);
};