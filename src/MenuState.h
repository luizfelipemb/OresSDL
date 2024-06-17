#pragma once
#include "GameStateBase.h"
#include <memory>
#include "Game.h"
#include "MenuRenderer.h"
#include "Button.h"

class Game;

class MenuState : public GameStateBase
{
public:
	MenuState(Game* game, std::unique_ptr<RenderWrapperBase>& render);

	void OnEnter() override;
	void Update(float deltaTime) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;
	void OnPlayButtonClick();

private:
	Game* game;
	std::unique_ptr<RenderWrapperBase>& render;
	std::unique_ptr<MenuRenderer> menuRenderer;
	std::vector<Button> buttons;
};
