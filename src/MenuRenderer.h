#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"

class MenuRenderer
{
public:
	MenuRenderer(std::shared_ptr<RenderWrapperBase> render);
	void UpdateRender(std::vector<Button> buttons);
	std::shared_ptr<RenderWrapperBase> render;
};

