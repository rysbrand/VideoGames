#pragma once
#include "../Header/stdafx.h"

class Tile 
{
private:

	sf::Sprite sprite;
	const bool damaging;



public:

	//I still don't quite get the difference between & as a pointer and *. I know * can be used with null, and can be reassigned
	//to a different thing? and apparently &, once declared with a variable can only be used for the one memory address
	Tile(sf::Texture* texturesheet, sf::IntRect texturerect, bool damaging = false);

	const sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);
};