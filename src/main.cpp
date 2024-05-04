#include "SDL.h" 
#include "Game.h"
#include "Configs.h"
#include <iostream>

Game* game = nullptr;
int main(int argc, char* argv[])
{
	game = new Game();
	while (game->Running)
	{
		game->Update();
	}
	return 0;
}