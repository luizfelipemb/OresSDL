#pragma once
class GameStateBase
{
public:
	virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void OnExit() = 0;
};

