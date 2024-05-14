#pragma once
#include "GameStateBase.h"
#include <memory>
#include "RenderWrapperBase.h"
#include "Game.h"
#include "LoseRenderer.h"

class Game;

class LoseState : public GameStateBase
{
public:
	LoseState(Game* game, std::shared_ptr<RenderWrapperBase> render);
	// Inherited via GameStateBase
	void OnEnter() override;
	void Update(float deltaTime) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;
	
private:
	void PlayAgain();
	Game* game;
	std::shared_ptr<RenderWrapperBase> render;
	std::unique_ptr<LoseRenderer> loseRenderer;
	std::vector<Button> buttons;
};

