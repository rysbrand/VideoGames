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

	//animation stuffs
	bool animationSwitch;
	short animationState;
	sf::IntRect currentFrame;
	
	//Physics nonsense
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;

	//core values to initialize
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();

public:

	Player();
	virtual ~Player();

	const bool& getanimationSwitch();

	//functions

	//tells it what directions you can move
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updateMovement();
	void updatePhysics();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);

	//these semicolons look weird, but for some reason if I remove them, it gives me errors
	;;;;;;;;
};;;;;;;