#include "MenuState.h"

#define PLAY_BUTTON_WIDTH WINDOW_WIDTH/8
#define PLAY_BUTTON_X WINDOW_WIDTH/2 - PLAY_BUTTON_WIDTH/2

MenuState::MenuState(Game* game, std::unique_ptr<RenderWrapperBase>& render) : game(game), render(render)
{
	menuRenderer = std::make_unique<MenuRenderer>(render);

	Button playButton = {
		PLAY_BUTTON_X,WINDOW_HEIGHT / 2,PLAY_BUTTON_WIDTH,WINDOW_HEIGHT / 10, "Play", [&]() { OnPlayButtonClick(); }
	};
	buttons.push_back(playButton);
}

void MenuState::OnEnter()
{
}

void MenuState::Update(float deltaTime)
{
	menuRenderer->UpdateRender(buttons);
}

void MenuState::OnExit()
{
}

void MenuState::OnMouseLeftClick(int PosX, int PosY)
{
	for (auto& button : buttons)
	{
		if (PosX >= button.x && PosX <= button.x + button.width &&
			PosY >= button.y && PosY <= button.y + button.height)
		{
			button.OnClick();
		}
	}
}

void MenuState::OnPlayButtonClick()
{
	game->SwitchState(game->inGameState);
}
