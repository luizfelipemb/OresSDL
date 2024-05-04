#include "Game.h"
#include "Configs.h"
#include "SDL.h"
#include <iostream>

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	
}

void Game::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
	last_frame_time = SDL_GetTicks();
}
