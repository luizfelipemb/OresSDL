#pragma once
#include "RenderWrapperBase.h"
#include <memory>
#include "BoardLogic.h"
#include "Button.h"
#include "Configs.h"

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

	const float ABOVE_UI_POS_Y = WINDOW_HEIGHT / 100;
	const float UI_BARS_WIDTH = WINDOW_WIDTH / 10;
	const float UI_BARS_HEIGHT = WINDOW_HEIGHT / 40;
	const float PUSH_UI_POS_X = WINDOW_WIDTH / 1.2f;
	const float SCORE_UI_POS_X = WINDOW_WIDTH / 2;
};
