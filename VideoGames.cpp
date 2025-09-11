// VideoGames.cpp : Defines the entry point for the application.
//

#include "VideoGames.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;

int main()
{
	float x = 0;
	float y = 0;

	const int windowWidth = 1000;
	const int windowHeight = 700;
	sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight }), "My window");
	window.setFramerateLimit(60);

	sf::Texture texture("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\cute_pixelperson.png");
	sf::Sprite sprite(texture);
	sprite.setOrigin(sf::Vector2f(0, 0));
	sprite.setPosition({ 10.f, 50.f });

	float spritespeed = 5.0f;

	sf::Clock clock;
	sf::Time t1 = sf::microseconds(10000);
	sf::Time t2 = sf::milliseconds(10);
	sf::Time t3 = sf::seconds(0.0f);
	
	sf::Font font ("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\fonts\\love-days-love-font\\LoveDays-2v7Oe.ttf");
	sf::Text text(font,"Hello SFML", 50);

	sf::Vector2f pos = sprite.getPosition();

	while(window.isOpen())
	{
		while (const std::optional<sf::Event> event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			if (event->is<sf::Event::KeyReleased>()) {
				//handle key release. here for debugging purposes.
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			pos.x += spritespeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			pos.x -= spritespeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			pos.y -= spritespeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			pos.y += spritespeed;
		}

		sprite.setPosition(pos);
		window.clear();
		window.draw(sprite);;
		window.draw(text);
		window.display();
	}
	return 0;
}
