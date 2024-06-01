#pragma once
#include "InputObserver.h"

class RenderWrapperBase;

class GameStateBase : public InputObserver
{
public:
	virtual void OnEnter() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(RenderWrapperBase* renderer) = 0;
	virtual void OnExit() = 0;
};

