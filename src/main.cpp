#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>();
	while (game->Running)
	{
		game->Update();
	}
	return 0;
}