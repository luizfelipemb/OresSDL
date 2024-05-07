#include "BoardLogic.h"
#include "Configs.h"
#include <iostream>
#include <random>

BoardLogic::BoardLogic()
{
	for (int columnIndex = 0; columnIndex < BOARD_GAMESTART_COLUMNS; ++columnIndex)
	{
		tiles.emplace_back();
		for (int rowIndex = 0; rowIndex < BOARD_COLUMN_BLOCK_NUMBER; ++rowIndex)
		{
			float xPos = WINDOW_WIDTH - TILE_SIDE - columnIndex * TILE_SIDE;
			float yPos = WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS - TILE_SIDE - rowIndex * TILE_SIDE;
			tiles[columnIndex].emplace_back(xPos, yPos, TILE_SIDE, GetRandomColor());
		}
	}
}

void BoardLogic::Update()
{

}

void BoardLogic::TryBreakTileAt(int PosX, int PosY)
{
	for (std::vector<BlockTile> columns : tiles)
	{
		for (BlockTile row : columns)
		{
			if (row.GetX() < PosX && row.GetX() + row.GetSideLenght() > PosX &&
				row.GetY() < PosY && row.GetY() + row.GetSideLenght() > PosY)
			{
				std::cout << "Tile to Break At:" << row.GetX() << "; " << row.GetY() << std::endl;
			}
		}
	}
}

Colors BoardLogic::GetRandomColor()
{
	// Initialize random number generator
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, static_cast<int>(Colors::Red));

	// Generate a random index
	int randomIndex = dist(gen);

	// Convert the random number to a Colors enum value
	return static_cast<Colors>(randomIndex);
}
