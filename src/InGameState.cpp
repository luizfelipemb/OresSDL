#include "InGameState.h"

InGameState::InGameState(std::shared_ptr<RenderWrapperBase> render)
{
	boardLogic = std::make_shared<BoardLogic>();
	gameRenderer = std::make_shared<InGameRenderer>(boardLogic, render);
}

void InGameState::OnEnter()
{
	
}

void InGameState::Update(float deltaTime)
{
	//push timer
	pushTimer += deltaTime;
	if (pushTimer >= PUSH_TIMER)
	{
		boardLogic->AddNewColumn();
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
