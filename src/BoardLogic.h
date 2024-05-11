#pragma once
#include "BlockTile.h"
#include <vector>

class BoardLogic
{
public:
	BoardLogic();
	void TryBreakTileAt(int PosX, int PosY);
	void AddNewColumn();
	const std::vector<std::vector<BlockTile>>& GetTiles() const { return tiles; };
	const int GetBlocksBroke() const { return blocksBroke; };
	void ResetBoard();
private:
	void BreakTileAtIndexIfColor(const int columnIndex, const int rowIndex, const Colors color);
	void ReorganizeTiles();
	Colors GetRandomColor();
	std::vector<std::vector<BlockTile>> tiles;
	int blocksBroke = 0;
};