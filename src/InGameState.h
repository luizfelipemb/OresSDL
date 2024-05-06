#pragma once
#include "GameStateBase.h"
#include "BoardLogic.h"
#include <iostream>
#include "GameRenderer.h"

class InGameState : public GameStateBase
{
public:
	InGameState(std::shared_ptr <RenderWrapperBase> render);
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
private:
	std::shared_ptr<BoardLogic> boardLogic;
	std::shared_ptr<GameRenderer> gameRenderer;
};

