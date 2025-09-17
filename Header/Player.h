#pragma once
#include "../Header/stdafx.h"

class Player
{
private:


	sf::Texture textureSheet;
	sf::Sprite sprite;

	bool moving;
	sf::Clock animationTimer;

	sf::IntRect currentFrame;

	//core values
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:

	Player();
	virtual ~Player();

	//function

	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);

	//these semicolons look weird, but for some reason if I remove them, it gives me errors
	;;;;;;;;
};;;;;;;