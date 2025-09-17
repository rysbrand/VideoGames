#pragma once
#include "../Header/stdafx.h"


enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Player
{
private:

	//thingggsssss i create
	sf::Texture textureSheet;
	sf::Sprite sprite;
	sf::Clock animationTimer;
	short animationState;
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