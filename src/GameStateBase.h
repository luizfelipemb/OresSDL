#pragma once
#include "InputObserver.h"

class GameStateBase : public InputObserver
{
public:
	virtual void OnEnter() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void OnExit() = 0;
};

