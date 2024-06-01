#pragma once
#include <string>
#include <functional>

#include "RenderWrapperBase.h"

class Button
{
public:
	Button(int x, int y, int width, int height, const std::string& text, const std::string& image, const std::string& font);

	void setOnClik(std::function<void()> OnClick);

	void draw(RenderWrapperBase* renderer);

	void checkCick(int PosX, int PosY);
private:
	int x;
	int y;
	int width;
	int height;
	std::string text;
	std::string image;
	std::string font;
	std::function<void()> OnClick;
};

