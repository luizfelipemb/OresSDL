#include "Game.h"
#include "Configs.h"
#include "SDL.h"
#include <iostream>

Game::Game()
{
	render = std::make_unique<Render>();
}

void Game::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
	last_frame_time = SDL_GetTicks();

	render->UpdateRender();

	SDL_Event windowEvent;
	if (SDL_PollEvent(&windowEvent))
	{
		if (SDL_QUIT == windowEvent.type)
		{
			Running = false;
		}
	}
}
