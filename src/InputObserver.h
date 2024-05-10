#pragma once
class InputObserver
{
public:
	virtual void OnMouseLeftClick(int PosX, int PosY) {};
	virtual void OnQuitWindowClick() {};
};
