#pragma once
#include "BlockTile.h"
#include <vector>

class BoardLogic
{
public:
	BoardLogic();
	void Update();
	void TryBreakTileAt(int PosX, int PosY);
	const std::vector<std::vector<BlockTile>>& GetTiles() const { return tiles; };
private:
	Colors GetRandomColor();
	std::vector<std::vector<BlockTile>> tiles;
};