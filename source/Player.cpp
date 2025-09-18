#include "../Header/stdafx.h"
#include"../Header/Player.h"
#include <array>


void Player::initVariables() 
{
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;
	this->animationState = true;
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
	//this->sprite = sf::Sprite(this->textureSheet);

	//Tells yo what part of texture sheet, sets frame for future animation.
	{
		this->currentFrame = sf::IntRect({ 384, 512 }, { 128, 256 });
		this->sprite.setTextureRect(sf::IntRect(currentFrame));
		this->sprite.setScale({ .5f, .5f });
	}
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics() 
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.87f;
	this->gravity = 1.6f;
	this->velocityMaxY = 22.f;
	this->onGround = false;
}

Player::Player() 
	: sprite(textureSheet)
{
	this->initVariables();;
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

Player::~Player() = default;

const sf::Vector2f Player::getPosition() const 
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y) 
{
	this->sprite.setPosition({ x,y });
}

void Player::resetVelocityY() 
{
	this->velocity.y = 0.f;
}

void Player::move(const float dir_x, const float dir_y) 
{
	//speed up
	this->velocity.x += dir_x * this->acceleration;
	this->velocity.y += dir_y * this->acceleration;
	//limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax) 
	{
		//this says that if velocity x is less than 0, multiply by -1, making it negative (y), otherwise by 1.
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ? -1.0f : 1.0f); 
		//caps velocity for moving left or right ^
	}
}

void Player::updatePhysics() 
{
	//gravity, yay!
	this->velocity.y += 1.0 * this->gravity;

	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		//this says that if velocity x is less than 0, multiply by -1, making it negative (y), otherwise by 1.
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0) ? -1.0f : 1.0f);
		//caps velocity for moving left or right ^
	}
	
	//drag
	this->velocity *= this->drag;
	//limit drag using absolute
	if (std::abs(this->velocity.x) < (this->velocityMin) )
	{
		this->velocity.x = 0.f;
	}

	if (std::abs(this->velocity.y) < (this->velocityMin))
	{
		this->velocity.y = 0.f;
	}

	this->sprite.move(this->velocity);
}


void Player::updateMovement() 
{
	//movement
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;
	bool jumpPressed = false;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
	{
		this->move(-1.f, 0.f);
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}

	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
	{
		this->move( 1.f, 0.f );
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;

	}

	 if (( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) )
	{
		bool jumpNow = true;
		this->playerJump();
	}
}

void Player::playerJump()
{
	// 1st jump
	if (this->onGround)
	{
		this->velocity.y = -this->velocityMaxY; // up is negative!!
		this->onGround = false;
		this->canDoubleJump = true; 
		this->animationState = PLAYER_ANIMATION_STATES::JUMPING;
		return;
	}

	// double jump
	if (this->canDoubleJump)
	{
		this->velocity.y = -this->velocityMaxY;
		this->canDoubleJump = false;
		this->animationState = PLAYER_ANIMATION_STATES::JUMPING;
	}
}

void Player::landOn(float newY)
{
	// place feet on ground and reset vertical speed/flags
	const float x = this->getPosition().x;
	this->setPosition((x), newY);
	this->resetVelocityY();
	this->onGround = true;
	this->canDoubleJump = true;
	if (this->animationState == PLAYER_ANIMATION_STATES::JUMPING)
	{
		this->animationState = PLAYER_ANIMATION_STATES::IDLE;
	}
}

const bool& Player::getanimationSwitch() 
{
	bool anim = this->animationSwitch; 
	this->animationSwitch = false;
	return anim;

}
void Player::resetAnimationTimer() 
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::updateAnimations()
{
	if (this->animationState == PLAYER_ANIMATION_STATES::IDLE)
	{
		currentFrame.position.y = 512;
		currentFrame.position.x = 384;

		this->sprite.setTextureRect(this->currentFrame);

		//c++ is wild, auto literally means hey compiler, heres a variable with a value, figure it out for yourself what type it is
		auto b = this->sprite.getGlobalBounds();
		this->sprite.setOrigin({b.size.x * 0.5f, 0.f});
		//I'm pretty sure the ugly way to write this is this->sprite.setOrigin({sprite.getGlobalBounds().size.x* 0.5f, 0.f});

		return;
	}


	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			if (currentFrame.position.y == 512)
			{
				currentFrame.position.y = 1792;
				currentFrame.position.x = 256;
			}
			else if (currentFrame.position.y == 1792)
			{
				currentFrame.position.y = 1536;
				currentFrame.position.x = 256;
			}
			else
			{
				currentFrame.position.y = 512;
				currentFrame.position.x = 384;
			}
			//setting the origin to center of the image so that when it flips it doesn't look weird
			this->sprite.setTextureRect(this->currentFrame);

			auto b = this->sprite.getGlobalBounds();
			this->sprite.setOrigin({ b.size.x * 0.5f, 0.f });

			this->animationTimer.restart();
		}
		this->sprite.setScale({ 0.5f, 0.5f }); // face right
		return;
	}

	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getanimationSwitch())
		{
			if (currentFrame.position.y == 512)
			{
				currentFrame.position.y = 1792;
				currentFrame.position.x = 256;
			}
			else if (currentFrame.position.y == 1792)
			{
				currentFrame.position.y = 1536;
				currentFrame.position.x = 256;
			}
			else
			{
				currentFrame.position.y = 512;
				currentFrame.position.x = 384;
			}
			this->sprite.setTextureRect(this->currentFrame);

			auto b = this->sprite.getGlobalBounds();
			this->sprite.setOrigin({ b.size.x * 0.5f, 0.f });

			this->animationTimer.restart();
		}
		this->sprite.setScale({-0.5f, 0.5f});
		return;
	}
	
	else if (this->animationState == PLAYER_ANIMATION_STATES::JUMPING) 
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getanimationSwitch()) 
		{
			if (currentFrame.position.y == 512) 
			{
				currentFrame.position.y = 1536;
				currentFrame.position.x = 768;
			}
			this->sprite.setTextureRect(this->currentFrame);

			auto b = this->sprite.getGlobalBounds();
			this->sprite.setOrigin({ b.size.x * 0.5f, 0.f });

			this->animationTimer.restart();
		}
		this->sprite.setScale({ -0.5f, 0.5f });
		return;
	}
}

//function
void Player::update() 
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}


//render to target/window (ie in game.cpp)
void Player::render(sf::RenderTarget& target) 
{
	target.draw(this->sprite);

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(2.f);
	circle.setPosition(this->sprite.getPosition());

	target.draw(circle);
}