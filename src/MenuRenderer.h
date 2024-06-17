#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"

class MenuRenderer
{
public:
	MenuRenderer(std::unique_ptr<RenderWrapperBase>& render);
	void UpdateRender(std::vector<Button> buttons) const;
	std::unique_ptr<RenderWrapperBase>& render;
};
