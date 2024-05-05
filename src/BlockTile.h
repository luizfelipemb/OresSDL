#pragma once
class BlockTile
{
public:
	BlockTile(int x, int y);
	const int GetX() const { return x; };
	const int GetY() const { return y; };
private:
	int x;
	int y;
};

