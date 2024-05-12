#include "InGameState.h"

InGameState::InGameState(Game* game, std::shared_ptr<RenderWrapperBase> render)
{
	this->game = game;
	boardLogic = std::make_shared<BoardLogic>();
	gameRenderer = std::make_shared<InGameRenderer>(boardLogic, render);
}

void InGameState::OnEnter()
{
	boardLogic->ResetBoard();
	pushTimer = 0;
	currentLevel = 1;
	pointsToNextLevel = NEXT_LEVEL_SCORE;
	score = 0;
}

void InGameState::Update(float deltaTime)
{
	//push timer
	pushTimer += deltaTime;
	if (pushTimer >= PUSH_TIMER)
	{
		if (!boardLogic->TryAddNewColumn()) {
			std::cout << "Game Over" << std::endl;
			game->SwitchState(game->menuState);
		}
		pushTimer = 0;
	}

	gameRenderer->UpdateRender(score,currentLevel,pointsToNextLevel);
}

void InGameState::OnExit()
{

}

void InGameState::OnMouseLeftClick(int PosX, int PosY)
{
	std::cout << "OnMouseLeftClick" << std::endl;
	boardLogic->TryBreakTileAt(PosX, PosY);
	score = boardLogic->GetBlocksBroke();
	//check next level
	if (score >= pointsToNextLevel)
	{
		score = 0;
		currentLevel++;
		pointsToNextLevel = std::ceil(pointsToNextLevel * NEXT_LEVEL_SCORE_MULTIPLY);
		boardLogic->ResetBoard();
	}
}
