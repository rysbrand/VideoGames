#pragma once
#include "../Header/stdafx.h"
#include "../Header/Tile.h"

class TileMap
{
private:
	//vectors! for making maps! bits of maps (or other images for use, kinda like pixels) are called tiles
	//need a vector ARRAY to put all the vectors together
	std::vector<std::vector<Tile* >> tiles;
	
public:

	//constructor
	TileMap();
	//deconstructor
	~TileMap();

	//all my functions

	//unsigned means no negative values allowed
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	void update();
	void render();

};