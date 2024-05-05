#pragma once
#include "BlockTile.h"
#include <vector>

class BoardLogic
{
public:
	BoardLogic();
	void Update();
	const std::vector<BlockTile>& GetTiles() const { return tiles; };
private:
	std::vector<BlockTile> tiles;
};

