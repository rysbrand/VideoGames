#pragma once
#include "../Header/stdafx.h"
#include "../Header/Tile.h"

class TileMap
{
private:
	//vectors! for making maps! bits of maps (or other images for use, kinda like pixels) are called tiles
	//need a vector ARRAY to put all the vectors together
	std::vector<std::vector<Tile* >> tiles;
	sf::Texture* tileSheet;
	unsigned tileSize;
	
public:

	//constructor
	TileMap();
	//constructor that lets us load texturesheet and stuffs
	TileMap(unsigned width, unsigned height, sf::Texture* tile_sheet, unsigned tile_size);
	//deconstructor
	~TileMap();

	//all my functions

	//unsigned means no negative values allowed
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	void update();
	//will render this in game also!
	void render(sf::RenderTarget& target);

};