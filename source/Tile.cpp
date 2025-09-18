#include "../Header/Tile.h"
#include "../Header/stdafx.h"

Tile::Tile(sf::Texture* texturesheet, sf::IntRect texturerect, bool damaging)
	: damaging(damaging), sprite(*texturesheet)
{
	//see? * makes it so it can be a null reference rn. this is what allows plug and play, i guess
	this->sprite.setTexture(*texturesheet);
	this->sprite.setTextureRect(texturerect);
}

const sf::FloatRect Tile::getGlobalBounds() const 
{
	return this->sprite.getGlobalBounds();
}

void Tile::update() 
{
	
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}