#include "InGameState.h"

InGameState::InGameState(std::shared_ptr<RenderWrapperBase> render)
{
	boardLogic = std::make_shared<BoardLogic>();
	gameRenderer = std::make_shared<GameRenderer>(boardLogic, render);
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
