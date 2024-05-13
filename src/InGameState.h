#pragma once
#include "GameStateBase.h"
#include "BoardLogic.h"
#include <iostream>
#include "GameRenderer.h"
#include "Configs.h"
#include "Game.h"
class Game;
class InGameState : public GameStateBase
{
public:
	InGameState(Game* game, std::shared_ptr<RenderWrapperBase> render);
	void OnEnter() override;
	void Update(float deltaTime) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;
private:
	Game* game;
	std::shared_ptr<BoardLogic> boardLogic;
	std::shared_ptr<InGameRenderer> gameRenderer;
	float pushTimer = 0;
	int currentLevel = 1;
	int pointsToNextLevel = NEXT_LEVEL_SCORE;
	int levelScore = 0;
	int score = 0;
};

