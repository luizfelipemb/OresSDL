#pragma once
#include "RenderWrapperBase.h"
#include <memory>
#include "BoardLogic.h"
#include "Button.h"

class InGameRenderer
{
public:
	InGameRenderer(std::unique_ptr<BoardLogic>& boardLogic, std::unique_ptr<RenderWrapperBase>& render);
	void UpdateRender(std::vector<Button> buttons, int score, int levelScore, int level, int pointsToNextLevel,
	                  float pushTimer, float maxPushTimer);
	std::unique_ptr<RenderWrapperBase>& render;

private:
	void RenderBoardTiles();
	std::unique_ptr<BoardLogic>& mBoardLogic;
};
