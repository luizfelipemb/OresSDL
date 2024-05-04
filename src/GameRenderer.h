#pragma once
#include "RenderWrapperBase.h"
#include <memory>

class GameRenderer
{
public:
	GameRenderer();
	void UpdateRender();
	std::unique_ptr<RenderWrapperBase> render;
};

