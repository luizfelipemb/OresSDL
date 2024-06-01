#pragma once
#include "RenderWrapperBase.h"
#include <memory>
#include "BoardLogic.h"
#include "Button.h"

class InGameRenderer
{
public:
	InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, RenderWrapperBase* renderer);
	void render(std::vector<Button> buttons, int score, int levelScore, int level, int pointsToNextLevel, float pushTimer, float maxPushTimer);
private:
	void RenderBoardTiles();

private:
	RenderWrapperBase* renderer;
	std::shared_ptr<BoardLogic> boardLogic;
};

