#include "../Header/stdafx.h"
#include "../Header/TileMap.h"


TileMap::TileMap()
{
	//possible cause * pointer. using for debugging purposes
	this->tileSheet = NULL;
	this->tileSize = 0;
}

TileMap::TileMap(unsigned width, unsigned height, sf::Texture* tile_sheet, unsigned tile_size) 
{
	this->tileSheet = tile_sheet;
	this->tileSize = tile_size;

	this->tiles.resize(width);

		for (int i = 0; i < this->tiles.size();i++)
		{
		
			this->tiles[i].resize(height, nullptr);

		}
}

TileMap::~TileMap() 
{
	//deconstructor for 2d grid columnnnsss
	for (int i = 0; i < this->tiles.size(); i++)
	{
		for (int j = 0; i < this->tiles[i].size(); j++)
		{
			delete this->tiles[i][j];
			this->tiles[i][j] = nullptr;
		}

	}
}

void TileMap::addTile(unsigned x, unsigned y) 
{
	//first make sure we are within our tilemap. outside it will crash it
	if (x < this->tiles.size()) 
	{
		if (y < this->tiles[x].size())
		{
			if (this->tiles[x][y] != nullptr)
			{
				//remember intrect tells the program what part of the tilsheet to grab
				this->tiles[x][y] = new Tile(this->tileSheet, sf::IntRect({ 0,0 }, { this->tileSize, this->tileSize }));
			}
		}
	}

}

void TileMap::removeTile(unsigned x, unsigned y) 
{

}

void TileMap::update() 
{

}

void TileMap::render(sf::RenderTarget& target) 
{

}
