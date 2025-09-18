#pragma once
#include "../Header/stdafx.h"

class Tile 
{
private:

	sf::Sprite sprite;
	const bool damaging;



public:

	Tile(sf::Texture& texturesheet, sf::IntRect texturerect, bool damaging = false);

	const sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);
};