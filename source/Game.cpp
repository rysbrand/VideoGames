#include "../Header/stdafx.h"
#include "../Header/Game.h"

void Game::initWindow() {
	//create and title the window
	this->window.create(sf::VideoMode({ 800, 600 }), "Look What I Can Do!", sf::Style::Close | sf::Style::Titlebar);
}
Game::Game() {
	this->initWindow();
}

Game::~Game() {

}