#pragma once
#include "GameStateBase.h"
#include <memory>
#include "Game.h"
#include "MenuRenderer.h"
#include "Button.h"
#include <functional>

class Game;
class MenuState : public GameStateBase
{
public:
	MenuState(Game* game, std::shared_ptr<RenderWrapperBase> render);

	void OnEnter() override;
	void Update(float deltaTime) override;
	void OnExit() override;
	void OnMouseLeftClick(int PosX, int PosY) override;
	void OnPlayButtonClick();
private:
	Game* game;
	std::shared_ptr<RenderWrapperBase> render;
	std::shared_ptr<MenuRenderer> menuRenderer;
	std::vector<Button> buttons;
};

