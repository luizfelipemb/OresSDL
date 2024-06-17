#include "Game.h"
#include "Configs.h"
#include "InGameState.h"
#include "MenuState.h"
#include "SDL.h"
#include "SDLRenderWrapper.h"

Game::Game()
	:	inGameState(std::make_shared<InGameState>(this, mRender)),
		menuState(std::make_shared<MenuState>(this, mRender)),
		loseState(std::make_shared<LoseState>(this, mRender)),
		mCurrentState(menuState),
		mRender(std::make_unique<SDLRenderWrapper>(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN)),
		mInputHandle(std::make_unique<InputHandler>())
{
	mInputHandle->RegisterObserver(this);
	SwitchState(menuState);
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

void Game::SwitchState(std::shared_ptr<GameStateBase>& newState)
{
	mInputHandle->RemoveObserver(mCurrentState.get());
	if (mCurrentState)
		mCurrentState->OnExit();
	mCurrentState = newState;
	mInputHandle->RegisterObserver(mCurrentState.get());
	mCurrentState->OnEnter();
}
