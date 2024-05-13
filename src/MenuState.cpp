#include "MenuState.h"

MenuState::MenuState(Game* game, std::shared_ptr<RenderWrapperBase> render) : game(game), render(render)
{
	menuRenderer = std::make_shared<MenuRenderer>(render);

	Button playButton = { PLAY_BUTTON_X,WINDOW_HEIGHT / 2,PLAY_BUTTON_WIDTH,WINDOW_HEIGHT/10,"Play", [&]() { OnPlayButtonClick(); } };
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
			if (button.text == "Play")
			{
				button.OnClick();
			}
		}
	}
}

void MenuState::OnPlayButtonClick()
{
	game->SwitchState(game->inGameState);
}
