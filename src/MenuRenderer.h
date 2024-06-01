#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"

class MenuRenderer
{
public:
	MenuRenderer(RenderWrapperBase* renderer);
	void render(std::vector<Button> buttons);

private:
	RenderWrapperBase* renderer;
};

