#pragma once

enum class Colors
{
	Green,
	Blue,
	Grey,
	Yellow,
	Red,
	Empty,
};

class BlockTile
{
public:
	BlockTile(int x, int y, float sideLenght, Colors color);
	const int GetX() const { return x; }
	const int GetY() const { return y; }
	const float GetSideLength() const { return sideLength; }
	const Colors GetColor() const { return myColor; }
	const void SetColor(const Colors color) { myColor = color; }
	const void TranslateX(const int addToX) { x += addToX; }

private:
	int x;
	int y;
	float sideLength;
	Colors myColor;
};
