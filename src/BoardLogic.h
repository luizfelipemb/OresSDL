#pragma once
#include "BlockTile.h"
#include <vector>

class RenderWrapperBase;

class BoardLogic
{
public:
	BoardLogic(int width, int height);
	void TryBreakTileAt(int PosX, int PosY);
	bool TryAddNewColumn();
	const std::vector<std::vector<BlockTile>>& GetTiles() const { return tiles; };
	const int GetBlocksBroke() const { return blocksBroke; };
	const int GetTotalBlocksBroke() const { return totalBlocksBroke; };
	const void ResetTotalBlocksBroke() { totalBlocksBroke = 0; };
	void ResetBoard();

	int getBoardInitialColumnHeightPos() const { return boardInitialColumnHeightPos; }
	int getTileSide() const { return tileSide; }

	void draw(RenderWrapperBase* renderer);
private:
	void TranslateTilesToLeft();
	void CreateNewRow();
	void BreakTileAtIndexIfColor(const int columnIndex, const int rowIndex, const Colors color);
	void ReorganizeTiles();
	Colors GetRandomColor();
	std::vector<std::vector<BlockTile>> tiles;
	int blocksBroke = 0;
	int totalBlocksBroke = 0;
	int indexOfFirstColumnWithBlocks = 0;
	int width;
	int height;
	int tileSide;
	int boardInitialColumnHeightPos;
};