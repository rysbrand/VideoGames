#include "../Header/stdafx.h"
#include"../Header/Player.h"

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
	//this->sprite.setPosition(100.f, 100.f);
	//this->sprite.setScale(3.f, 3.f);
}

Player::Player() 
	: sprite(textureSheet)
{
	this->initTexture();
	this->initSprite();
}

Player::~Player() = default;


//function
void Player::update() 
{

}


//render to target/window
void Player::render(sf::RenderTarget& target) 
{
	target.draw(this->sprite);
}