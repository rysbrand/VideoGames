#include "../Header/stdafx.h"
#include "../Header/Game.h"


void Game::initWindow() {
	//create and title the window
	this->window.create(sf::VideoMode({ 800, 600 }), "Look What I Can Do!", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initPlayer() {
	this->player = new Player();
}

Game::Game() : player{} {

	this->initWindow();
	this->initPlayer();
}

Game::~Game() 
{
	delete this->player;
}

void Game::updatePlayer() 
{
	this->player->update();
}

void Game::updateCollision() 
{
	const sf::Vector2f pos = this->player->getPosition();
	//find player bounds
	const float playerHeight = this->player->getGlobalBounds().size.y;
	//checks bottom of player bounds with bottom of window
	const float playerBottom = pos.y + playerHeight;
	const float windowHeight = static_cast<float>(this->window.getSize().y);

	//keeps player from falling through bottoms of window
	if (playerBottom > windowHeight)
	{
		this->player->resetVelocityY();

		const float newY = windowHeight - playerHeight;
		this->player->setPosition(pos.x, newY);
		this->player->landOn(newY);
	}
}

void Game::update()
{
	//polling window events
	while (const auto event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
		else if (event->is<sf::Event::KeyPressed>() &&
			event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
		{
			window.close();
		}

		//This code is really ugly, should've made it its own little component.
		if (event->is<sf::Event::KeyReleased>()  &&
				((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) 
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))))
		{
			this->player->resetAnimationTimer();
		}
	}
	this->updatePlayer();
	this->updateCollision();
}


void Game::renderPlayer() 
{
	this->player->render(this->window);
}

void Game::render() 
{
	//this->window.clear(sf::Color::Black);
	window.clear(sf::Color::Black);

	//render stuff here
	this->renderPlayer();
	this->window.display();
}
const sf::RenderWindow& Game::getWindow() const
	{
		return this->window;
	}