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
	inputHandle->RegisterObserver(this);
	SwitchState(inGameState);
}

void Game::Update()
{
	// Calculate delta time
	Uint32 currentTicks = SDL_GetTicks();
	float deltaTime = (currentTicks - last_frame_time) / 1000.0f; // Convert milliseconds to seconds
	last_frame_time = currentTicks;

	inputHandle->HandleEvents();
	currentState->Update(deltaTime);
	render->UpdateRender();
	
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
}

void Game::OnQuitWindowClick()
{
	Running = false;
	std::cout << "Trying to quit" << std::endl;
}

void Game::SwitchState(std::shared_ptr<GameStateBase> newState)
{
	if(currentState)
		currentState->OnExit();
	inputHandle->RegisterObserver(newState.get());
	currentState = newState;
	currentState->OnEnter();
}
