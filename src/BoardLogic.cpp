#include "BoardLogic.h"
#include "Configs.h"
#include <iostream>
#include <random>

BoardLogic::BoardLogic()
{
	ResetBoard();
}

void BoardLogic::TryBreakTileAt(int PosX, int PosY)
{
	for (size_t columnIndex = 0; columnIndex < tiles.size(); ++columnIndex)
	{
		for (size_t rowIndex = 0; rowIndex < tiles[columnIndex].size(); ++rowIndex)
		{
			BlockTile& tile = tiles[columnIndex][rowIndex];

			if (tile.GetColor() == Colors::Empty)
				continue;

			if (tile.GetX() <= PosX && tile.GetX() + tile.GetSideLength() >= PosX &&
				tile.GetY() <= PosY && tile.GetY() + tile.GetSideLength() >= PosY)
			{
				std::cout << "Tile to Break At: " << tile.GetX() << "; " << tile.GetY() << std::endl;

				bool hasSameColorNeighbor = false;
				const Colors tileColor = tile.GetColor();

				if (rowIndex + 1 < tiles[columnIndex].size() && tileColor == tiles[columnIndex][rowIndex + 1].GetColor())
					hasSameColorNeighbor = true;
				else if (rowIndex > 0 && tileColor == tiles[columnIndex][rowIndex - 1].GetColor())
					hasSameColorNeighbor = true;
				else if (columnIndex > 0 && tileColor == tiles[columnIndex - 1][rowIndex].GetColor())
					hasSameColorNeighbor = true;
				else if (columnIndex + 1 < tiles.size() && tileColor == tiles[columnIndex + 1][rowIndex].GetColor())
					hasSameColorNeighbor = true;

				if (hasSameColorNeighbor || HACK_BREAK_EVERY_BLOCK)
				{
					tile.SetColor(Colors::Empty);
					BreakTileAtIndexIfColor(columnIndex + 1, rowIndex, tileColor);
					BreakTileAtIndexIfColor(columnIndex - 1, rowIndex, tileColor);
					BreakTileAtIndexIfColor(columnIndex, rowIndex - 1, tileColor);
					BreakTileAtIndexIfColor(columnIndex, rowIndex + 1, tileColor);
					blocksBroke++;
					totalBlocksBroke++;
				}
				ReorganizeTiles();

				return;
			}
		}
	}
}

bool BoardLogic::TryAddNewColumn()
{
	//game over
	if (tiles.size() >=  indexOfFirstColumnWithBlocks + BOARD_MAX_COLUMN_SIZE) {
		return false;
	}
		
	TranslateTilesToLeft();
	CreateNewRow();

	return true;
}

void BoardLogic::TranslateTilesToLeft()
{
	for (size_t columnIndex = 0; columnIndex < tiles.size(); ++columnIndex)
	{
		for (size_t rowIndex = 0; rowIndex < tiles[columnIndex].size(); ++rowIndex)
		{
			BlockTile& tile = tiles[columnIndex][rowIndex];
			tile.TranslateX(-TILE_SIDE);
		}
	}
}

void BoardLogic::CreateNewRow()
{
	tiles.emplace_back();
	for (int rowIndex = 0; rowIndex < BOARD_COLUMN_BLOCK_NUMBER; ++rowIndex)
	{
		int xPos = WINDOW_WIDTH - TILE_SIDE;
		int yPos = WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS - TILE_SIDE - rowIndex * TILE_SIDE;
		tiles[tiles.size() - 1].emplace_back(xPos, yPos, TILE_SIDE, GetRandomColor());
	}
}

void BoardLogic::ResetBoard()
{
	blocksBroke = 0;
	indexOfFirstColumnWithBlocks = 0;
	tiles.clear();
	for (int columnIndex = 0; columnIndex < BOARD_GAMESTART_COLUMNS; ++columnIndex)
	{
		tiles.emplace_back();
		for (int rowIndex = 0; rowIndex < BOARD_COLUMN_BLOCK_NUMBER; ++rowIndex)
		{
			int xPos = WINDOW_WIDTH - ((BOARD_GAMESTART_COLUMNS - columnIndex) * TILE_SIDE);
			int yPos = WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS - TILE_SIDE - rowIndex * TILE_SIDE;
			tiles[columnIndex].emplace_back(xPos, yPos, TILE_SIDE, GetRandomColor());
		}
	}
}

void BoardLogic::BreakTileAtIndexIfColor(const int columnIndex, const int rowIndex, const Colors color)
{
	if (!(columnIndex < tiles.size()) || !(columnIndex >= 0) || !(rowIndex >= 0) || !(rowIndex < tiles[columnIndex].size()))
		return;

	BlockTile& tile = tiles[columnIndex][rowIndex];
	if (tile.GetColor() == color) 
	{
		tile.SetColor(Colors::Empty);
		blocksBroke++;
		totalBlocksBroke++;
		BreakTileAtIndexIfColor(columnIndex + 1, rowIndex, color);
		BreakTileAtIndexIfColor(columnIndex - 1, rowIndex, color);
		BreakTileAtIndexIfColor(columnIndex, rowIndex + 1, color);
		BreakTileAtIndexIfColor(columnIndex, rowIndex - 1, color);
	}
}

void BoardLogic::ReorganizeTiles()
{
	for (size_t columnIndex = 0; columnIndex < tiles.size(); ++columnIndex)
	{
		//check if entire column is empty
		bool isEntireColumnEmpty = true;
		for (size_t rowIndex = 0; rowIndex < tiles[columnIndex].size(); ++rowIndex)
		{
			if (tiles[columnIndex][rowIndex].GetColor() != Colors::Empty) {
				isEntireColumnEmpty = false;
				break;
			}
		}
		if (isEntireColumnEmpty)
		{
			if (columnIndex == indexOfFirstColumnWithBlocks)
				indexOfFirstColumnWithBlocks = columnIndex + 1;

			for (size_t columnIndex2 = columnIndex; columnIndex2 > 0; --columnIndex2)
			{
				for (size_t rowIndex = 0; rowIndex < tiles[columnIndex].size(); ++rowIndex)
				{
					Colors temp = tiles[columnIndex2][rowIndex].GetColor();
					tiles[columnIndex2][rowIndex].SetColor(tiles[columnIndex2-1][rowIndex].GetColor());
					tiles[columnIndex2 - 1][rowIndex].SetColor(temp);
				}
			}
		}

		//check empty rows
		for (size_t rowIndex = 0; rowIndex < tiles[columnIndex].size() - 1; ++rowIndex)
		{
			if (tiles[columnIndex][rowIndex].GetColor() != Colors::Empty)
				continue;

			int addToIndex = 1;
			bool foundOne = false;
			do
			{
				if (tiles[columnIndex][rowIndex + addToIndex].GetColor() != Colors::Empty)
				{
					tiles[columnIndex][rowIndex].SetColor(tiles[columnIndex][rowIndex + addToIndex].GetColor());
					tiles[columnIndex][rowIndex + addToIndex].SetColor(Colors::Empty);
					foundOne = true;
				}
				addToIndex++;

			} while (addToIndex + rowIndex < tiles[columnIndex].size() && !foundOne);

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
