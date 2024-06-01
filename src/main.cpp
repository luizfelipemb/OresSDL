#include "Game.h"

#include <iostream>
#include "Configs.h"

#include "SDLRenderWrapper.h"
#include "MenuState.h"

#define WINDOW_WIDTH 640*2
#define WINDOW_HEIGHT 360*2
#define WINDOW_TITLE "Ores Game by Luiz Felipe Bustamante"

int main(int argc, char* argv[])
{
	SDLRenderWrapper renderer(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN);

	Game game(&renderer);

	game.switchState(std::make_unique<MenuState>(&game, &renderer));

	while (game.processEvents())
	{
		game.update();

		game.render();
	}
	return 0;
}