#include "../Header/stdafx.h"
#include"../Header/Player.h"
#include <array>


void Player::initVariables() 
{
	this->moving = false;
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture() 
{
	if (!this->textureSheet.loadFromFile("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\Platformerpack\\Spritesheets\\spritesheet_players.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load player sheet." << "\n";
	}
}

void Player::initSprite()
{
	this->sprite = sf::Sprite(this->textureSheet);

	//Tells yo what part of texture sheet, sets frame for future animation.
	{
		this->currentFrame = sf::IntRect({ 384, 512 }, { 128, 256 });
		this->sprite.setTextureRect(sf::IntRect(currentFrame));

	}
}

Player::Player() 
	: sprite(textureSheet)
{
	this->initVariables();;
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player() = default;



void Player::updateMovement() 
{
	//movement
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
	{
		this->sprite.move({-1.f, 0.f});
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
		//this->moving=true;
	}

	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
	{
		this->sprite.move({ 1.f, 0.f });
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
		//this->moving = true;
	}
}
void Player::updateAnimations()
{
	if (this->animationState == PLAYER_ANIMATION_STATES::IDLE)
	{
		currentFrame.position.y = 512;
		currentFrame.position.x = 384;
	}

	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) 
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			if (currentFrame.position.y == 512) {
				currentFrame.position.y = 1792;
				currentFrame.position.x = 256;
			}
			else if (currentFrame.position.y == 1792) {
				currentFrame.position.y = 1536;
				currentFrame.position.x = 256;
			}
			else {
				currentFrame.position.y = 512;
				currentFrame.position.x = 384;
			}
			this->sprite.setTextureRect(this->currentFrame);

			this->animationTimer.restart();
		}
	}

	else {
		if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
		{

			if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				if (currentFrame.position.y == 512) {
					currentFrame.position.y = 1792;
					currentFrame.position.x = 256;
				}
				else if (currentFrame.position.y == 1792) {
					currentFrame.position.y = 1536;
					currentFrame.position.x = 256;
				}
				else {
					currentFrame.position.y = 512;
					currentFrame.position.x = 384;
				}
				this->sprite.setTextureRect(this->currentFrame);
				this->animationTimer.restart();
			}
		}
	}
}
void Player::initAnimations() 
{
	this->animationTimer.restart();
}

//function
void Player::update() 
{
	this->updateMovement();
	this->updateAnimations();
}


//render to target/window
void Player::render(sf::RenderTarget& target) 
{
	target.draw(this->sprite);
}