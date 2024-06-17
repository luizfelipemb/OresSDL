#pragma once
#include <string>
#include <functional>

class Button
{
public:
	int x;
	int y;
	int width;
	int height;
	std::string text;
	std::function<void()> OnClick;
};
