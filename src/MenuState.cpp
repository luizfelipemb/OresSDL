#include "MenuState.h"

#include "InGameState.h"
#include "TransitionState.h"

#define MENU_TITLE "Ores Game"
#define MENU_SUBTITLE "by Luiz Felipe Bustamante"

MenuState::MenuState(Game* game, RenderWrapperBase* renderer) : game(game), renderer(renderer)
{
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
	renderer->setBackGroundColor(BACKGROUND_COLOR);
}

void MenuState::OnEnter()
{	
}

void MenuState::update(float deltaTime)
{

}

void MenuState::render(RenderWrapperBase* renderer)
{
	int WINDOW_WIDTH = renderer->getWidth();
	int WINDOW_HEIGHT = renderer->getHeight();

	renderer->RenderText(MENU_TITLE, FONT_LOCATION, WINDOW_WIDTH / 10, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 10, 1, true, { TEXT_COLOR });
	renderer->RenderText(MENU_SUBTITLE, FONT_LOCATION, WINDOW_WIDTH / 25, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5, 1, true, { TEXT_COLOR });
	for (auto& button : buttons)
	{
		button.draw(renderer);
	}
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
	game->switchState(std::make_shared<TransitionState>(game, game->getCurrentState(), std::make_shared<InGameState>(game, game->getRender()), 0.5f));
}
