#pragma once
#include "GameStateBase.h"
#include <memory>
#include "Game.h"
#include "Button.h"
#include <functional>

class Game;

class MenuState : public GameStateBase
{
public:
	MenuState(Game* game, RenderWrapperBase* renderer);

	void OnEnter() override;
	void update(float deltaTime) override;
	void render(RenderWrapperBase* renderer) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;
	void OnPlayButtonClick();
private:
	Game* game;
	RenderWrapperBase* renderer;
	std::vector<Button> buttons;
};

