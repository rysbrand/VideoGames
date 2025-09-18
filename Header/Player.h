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
	float gravity;
	float velocityMaxY;

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
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	

	//Bounds and Collision
	void setPosition(const float x, const float y);
	void resetVelocityY();

	//functions
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updateMovement();
	void updatePhysics();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);

};