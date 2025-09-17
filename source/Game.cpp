#include "../Header/stdafx.h"
#include "../Header/Game.h"


void Game::initWindow() {
	//create and title the window
	this->window.create(sf::VideoMode({ 800, 600 }), "Look What I Can Do!", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(144);
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