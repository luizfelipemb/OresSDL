#include "Game.h"

#include "Configs.h"
#include "RenderWrapperBase.h"

#include "SDL.h"
#include <iostream>

Game::Game(RenderWrapperBase* renderer)
	: renderer(renderer)
{
	lastFrameTime = 0;

	inputHandle.RegisterObserver(this);
}

bool Game::processEvents()
{
	inputHandle.HandleEvents();
	return running;
}

void Game::update()
{
	// Calculate delta time
	Uint32 currentTicks = SDL_GetTicks();
	float deltaTime = (currentTicks - lastFrameTime) / 1000.0f; // Convert milliseconds to seconds
	lastFrameTime = currentTicks;

	currentState->update(deltaTime);
	
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + FRAME_TARGET_TIME));
}

void Game::render()
{
	renderer->clear();
	currentState->render(renderer);
	renderer->present();
}

void Game::stop()
{
	running = false;
}

void Game::switchState(std::shared_ptr<GameStateBase> newState)
{
	inputHandle.RemoveObserver(currentState.get());
	if(currentState)
		currentState->OnExit();
	inputHandle.RegisterObserver(newState.get());
	currentState = std::move(newState);
	currentState->OnEnter();
}
