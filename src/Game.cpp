#include "Game.h"
#include "Configs.h"
#include "SDL.h"
#include <iostream>
#include "SDLRenderWrapper.h"

Game::Game()
{
	last_frame_time = 0;
	render = std::make_shared<SDLRenderWrapper>(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN);
	inputHandle = std::make_shared<InputHandler>();

	inGameState = std::make_shared<InGameState>(render);
	currentState = inGameState;
}

void Game::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
	last_frame_time = SDL_GetTicks();

	inputHandle->HandleEvents();
	currentState->Update();
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

void Game::SwitchState(std::shared_ptr<GameStateBase> newState)
{
	currentState->OnExit();
	currentState = newState;
	currentState->OnEnter();
}
