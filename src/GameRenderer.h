#pragma once
#include "RenderWrapperBase.h"
#include <memory>
#include "BoardLogic.h"

class GameRenderer
{
public:
	GameRenderer(std::shared_ptr<BoardLogic> boardLogic, std::shared_ptr<RenderWrapperBase> render);
	void UpdateRender();
	std::shared_ptr<RenderWrapperBase> render;
private:
	std::shared_ptr<BoardLogic> boardLogic;
};

