#include "TransitionState.h"
#include "Game.h"

#include "RenderWrapperBase.h"

TransitionState::TransitionState(Game* game, const std::shared_ptr<GameStateBase>& fromState, const std::shared_ptr<GameStateBase>& toState, float timeout)
	: game(game), fromState(fromState), toState(toState), timeout(timeout), timeElapsed(0)
{
}

void TransitionState::OnEnter()
{
}

void TransitionState::update(float deltaTime)
{
	timeElapsed += deltaTime;
	if (timeElapsed >= timeout)
	{
		game->switchState(toState);
	}
}

void TransitionState::render(RenderWrapperBase* renderer)
{
	if (timeElapsed < timeout / 2)
	{
		fromState->render(renderer);
		unsigned char alpha = 255 * timeElapsed / (timeout / 2);
		renderer->DrawRectangle(0, 0, renderer->getWidth(), renderer->getHeight(), { 0, 0, 0}, alpha);
	}
	else
	{
		toState->render(renderer);
		unsigned char alpha = 255 - 255 * (timeElapsed - timeout / 2) / (timeout / 2);
		renderer->DrawRectangle(0, 0, renderer->getWidth(), renderer->getHeight(), { 0, 0, 0}, alpha);
	}
}

void TransitionState::OnMouseLeftClick(int PosX, int PosY)
{
}

void TransitionState::OnExit()
{
}
