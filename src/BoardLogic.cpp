#include "BoardLogic.h"
#include "Configs.h"

BoardLogic::BoardLogic()
{
	for (int columnIndex = 0; columnIndex < BOARD_GAMESTART_COLUMNS; ++columnIndex)
	{
		tiles.emplace_back();
		for (int rowIndex = 0; rowIndex < BOARD_COLUMN_BLOCK_NUMBER; ++rowIndex)
		{
			float xPos = WINDOW_WIDTH - TILE_SIDE - columnIndex * TILE_SIDE;
			float yPos = WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS - TILE_SIDE - rowIndex * TILE_SIDE;
			tiles[0].emplace_back(xPos, yPos);
		}
	}
}

void BoardLogic::Update()
{

}
