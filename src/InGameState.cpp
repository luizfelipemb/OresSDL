#include "InGameState.h"
#include "Configs.h"

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
	pushTimer += deltaTime;
	if (pushTimer >= PUSH_TIMER)
	{
		boardLogic->AddNewColumn();
		pushTimer = 0;
	}
	gameRenderer->UpdateRender();
}

void InGameState::OnExit()
{

}

void InGameState::OnMouseLeftClick(int PosX, int PosY)
{
	std::cout << "OnMouseLeftClick" << std::endl;
	boardLogic->TryBreakTileAt(PosX, PosY);
}
