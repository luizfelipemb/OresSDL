#include "InGameState.h"

InGameState::InGameState(std::shared_ptr<RenderWrapperBase> render)
{
	boardLogic = std::make_shared<BoardLogic>();
	gameRenderer = std::make_shared<InGameRenderer>(boardLogic, render);
}

void InGameState::OnEnter()
{
	
}

void InGameState::Update()
{
	boardLogic->Update();
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
