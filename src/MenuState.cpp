#include "MenuState.h"

#include "InGameState.h"

MenuState::MenuState(Game* game, RenderWrapperBase* renderer) : game(game), renderer(renderer)
{
	menuRenderer = std::make_shared<MenuRenderer>(renderer);

	int PLAY_BUTTON_WIDTH = renderer->getWidth() / 8;
	int PLAY_BUTTON_X = renderer->getWidth() / 2 - PLAY_BUTTON_WIDTH / 2;

	Button playButton(
		PLAY_BUTTON_X,
		renderer->getHeight() / 2,
		PLAY_BUTTON_WIDTH,
		renderer->getHeight() / 10,
		"Play", BUTTON_IMAGE, FONT_LOCATION);
	playButton.setOnClik([&]() { OnPlayButtonClick(); } );
	buttons.push_back(playButton);
}

void MenuState::OnEnter()
{
}

void MenuState::update(float deltaTime)
{
	menuRenderer->render(buttons);
}

void MenuState::OnExit()
{
}

void MenuState::OnMouseLeftClick(int PosX, int PosY)
{
	for (auto& button : buttons)
	{
		button.checkCick(PosX, PosY);
	}
}

void MenuState::OnPlayButtonClick()
{
	game->switchState(std::make_unique<InGameState>(game, game->getRender()));
}
