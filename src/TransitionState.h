#pragma once
#include "GameStateBase.h"

#include <memory>

class Game;

class TransitionState : public GameStateBase
{
public:
	TransitionState(Game* game, const std::shared_ptr<GameStateBase>& fromState, const std::shared_ptr<GameStateBase>& toState, float timeout = 5.0f);
	void OnEnter() override;
	void update(float deltaTime) override;
	void render(RenderWrapperBase* renderer) override;
	void OnMouseLeftClick(int PosX, int PosY) override;
	void OnExit() override;

private:
	Game* game;
	std::shared_ptr<GameStateBase> fromState;
	std::shared_ptr<GameStateBase> toState;
	float timeout;
	float timeElapsed;
};