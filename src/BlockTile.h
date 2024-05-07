#pragma once

enum class Colors
{
	Green,
	Blue,
	Grey,
	Yellow,
	Red
};

class BlockTile
{
public:
	BlockTile(int x, int y, float sideLenght, Colors color);
	const int GetX() const { return x; };
	const int GetY() const { return y; };
	const float GetSideLenght() const { return sideLength; };
	const Colors GetColor() const { return myColor; };
private:
	int x;
	int y;
	float sideLength;
	Colors myColor;
};

