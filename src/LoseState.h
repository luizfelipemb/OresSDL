#pragma once
#include "GameStateBase.h"
#include <memory>

#include "Configs.h"
#include "RenderWrapperBase.h"
#include "Game.h"
#include "LoseRenderer.h"

class Game;

class LoseState : public GameStateBase
{
public:
	LoseState(Game* game, std::unique_ptr<RenderWrapperBase>& render);
	// Inherited via GameStateBase
	void OnEnter() override;
	void Update(float deltaTime) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;

private:
	void PlayAgain();
	Game* game;
	std::unique_ptr<RenderWrapperBase>& render;
	std::unique_ptr<LoseRenderer> loseRenderer;
	std::vector<Button> buttons;

	const int AGAIN_BUTTON_WIDTH = WINDOW_WIDTH / 8;
	const int AGAIN_BUTTON_X = WINDOW_WIDTH / 2 - AGAIN_BUTTON_WIDTH / 2;
};
