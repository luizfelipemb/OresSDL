#include "BoardLogic.h"
#include "Configs.h"

BoardLogic::BoardLogic()
{
	for (int i = 0; i < BOARD_COLUMN_BLOCK_NUMBER; ++i)
	{
		float xPos = WINDOW_WIDTH - TILE_SIDE;
		float yPos = WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS - i * TILE_SIDE;
		tiles.emplace_back(xPos, yPos);
	}
}

void BoardLogic::Update()
{

}
