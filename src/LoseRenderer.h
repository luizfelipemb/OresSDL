#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"
#include "SaveData.h"

class LoseRenderer
{
public:
	LoseRenderer(RenderWrapperBase* renderer);
	void render(std::vector<Button> buttons, SaveData saveData);
private:
	RenderWrapperBase* renderer;
};

