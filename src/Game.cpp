#include "Game.h"
#include "Configs.h"
#include "SDL.h"
#include <iostream>
#include "SDLRenderWrapper.h"

Game::Game()
	:	inGameState(std::make_unique<InGameState>(this, mRender)),
		menuState(std::make_unique<MenuState>(this, mRender)),
		loseState(std::make_unique<LoseState>(this, mRender))
		
{
	mLastFrameTime = 0;
	mRender = std::make_unique<SDLRenderWrapper>(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN);
	mInputHandle = std::make_unique<InputHandler>();
	mInputHandle->RegisterObserver(this);
	SwitchState(inGameState);
}

void Game::Update()
{
	// Calculate delta time
	Uint32 currentTicks = SDL_GetTicks();
	float deltaTime = (currentTicks - mLastFrameTime) / 1000.0f; // Convert milliseconds to seconds
	mLastFrameTime = currentTicks;

	mInputHandle->HandleEvents();
	mCurrentState->Update(deltaTime);
	mRender->UpdateRender();

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mLastFrameTime + FRAME_TARGET_TIME));
}

void Game::OnQuitWindowClick()
{
	running = false;
}

void Game::SwitchState(std::unique_ptr<GameStateBase>& newState)
{
	mInputHandle->RemoveObserver(mCurrentState.get());
	if (mCurrentState)
		mCurrentState->OnExit();
	mInputHandle->RegisterObserver(newState.get());
	mCurrentState = std::move(newState);
	mCurrentState->OnEnter();
}
