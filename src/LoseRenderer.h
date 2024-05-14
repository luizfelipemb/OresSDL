#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"

class LoseRenderer
{
public:
	LoseRenderer(std::shared_ptr<RenderWrapperBase> render);
	void UpdateRender(std::vector<Button> buttons);
private:
	std::shared_ptr<RenderWrapperBase> render;
};

