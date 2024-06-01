#include "Button.h"

Button::Button(int x, int y, int width, int height, const std::string& text, const std::string& image, const std::string& font)
	: x(x), y(y), width(width), height(height), text(text), image(image), font(font)
{
}

void Button::setOnClik(std::function<void()> OnClick)
{
	this->OnClick = OnClick;
}

void Button::draw(RenderWrapperBase* renderer)
{
	renderer->RenderImage(image, x, y, width, height, 1);
	renderer->RenderText(text, font, width / 4, x + width / 2, y + height / 2.5f, 1, true);
}

void Button::checkCick(int PosX, int PosY)
{
	if (PosX >= x && PosX <= x + width &&
		PosY >= y && PosY <= y + height)
	{
		OnClick();
	}
}
