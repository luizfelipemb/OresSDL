#pragma once
#include <memory>
#include "RenderWrapperBase.h"
#include <vector>
#include "Button.h"
#include "SaveData.h"

class LoseRenderer
{
public:
	LoseRenderer(std::unique_ptr<RenderWrapperBase>& render);
	void UpdateRender(std::vector<Button> buttons, SaveData saveData);

private:
	std::unique_ptr<RenderWrapperBase>& render;
};
