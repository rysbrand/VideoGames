#include "../Header/stdafx.h"
#include "../Header/Game.h"


void Game::initWindow() {
	//create and title the window
	this->window.create(sf::VideoMode({ 800, 600 }), "Look What I Can Do!", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initPlayer() {
	this->player = new Player();
}

Game::Game() {

	this->initWindow();
	this->initPlayer();
}

Game::~Game() 
{
	delete this->player;
}

void Game::updatePlayer() 
{

}

void Game::update()
{
	//polling window events
	while (window.isOpen())
	{
		bool jumpPressed = false;
		while (const auto event = window.pollEvent()) 
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			else if (event->is<sf::Event::KeyPressed>() &&
				event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
		}
	}
}

void Game::render() 
{
	this->window.clear(sf::Color::Black);

	//render stuff here

	this->window.display();
}
const sf::RenderWindow& Game::getWindow() const
	{
		return this->window;
	}