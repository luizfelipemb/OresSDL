#pragma once
#include "RenderWrapperBase.h"
#include <memory>
#include "BoardLogic.h"

class InGameRenderer
{
public:
	InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, std::shared_ptr<RenderWrapperBase> render);
	void UpdateRender(int score, int levelScore, int level, int pointsToNextLevel,float pushTimer,float maxPushTimer);
	std::shared_ptr<RenderWrapperBase> render;
private:
	void RenderBoardTiles();
	std::shared_ptr<BoardLogic> boardLogic;
};

