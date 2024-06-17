#pragma once
class InputObserver
{
public:
	virtual ~InputObserver() = default;

	virtual void OnMouseLeftClick(int PosX, int PosY)
	{
	};

	virtual void OnQuitWindowClick()
	{
	};
};
