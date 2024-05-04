#include "SDL.h" 
#include "Game.h"
#include "Configs.h"
#include <iostream>

Game* game = nullptr;
int main(int argc, char* argv[])
{
	game = new Game();
	game->Init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	while (game->Running)
	{
		game->Update();
	}
	//game->clean();

	return 0;
}