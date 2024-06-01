#include "LoseState.h"

#include "InGameState.h"

#define LOSE_TITLE "You Lose"

LoseState::LoseState(Game* game, RenderWrapperBase* renderer) : game(game), renderer(renderer)
{
	int AGAIN_BUTTON_WIDTH = renderer->getWidth() / 8;
	int AGAIN_BUTTON_X = renderer->getWidth() / 2 - AGAIN_BUTTON_WIDTH / 2;

	Button againButton(
		AGAIN_BUTTON_X,
		renderer->getHeight() / 1.5f,
		AGAIN_BUTTON_WIDTH,
		renderer->getHeight() / 10,
		"Again", BUTTON_IMAGE, FONT_LOCATION);
	againButton.setOnClik([&]() { PlayAgain(); } );
	buttons.push_back(againButton);

	renderer->setBackGroundColor(BACKGROUND_COLOR);
}

void LoseState::OnEnter()
{
}

void LoseState::update(float deltaTime)
{

}

void LoseState::render(RenderWrapperBase* renderer)
{
	int WINDOW_WIDTH = renderer->getWidth();
	int WINDOW_HEIGHT = renderer->getHeight();

	auto saveData = game->getSaveData();
	renderer->RenderText(LOSE_TITLE, FONT_LOCATION, WINDOW_WIDTH / 10, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 10, 1, true, { TEXT_COLOR });
	renderer->RenderText("Level:" + std::to_string(saveData.level), FONT_LOCATION, WINDOW_WIDTH / 25, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3, 1, true, { TEXT_COLOR });
	renderer->RenderText("Score:" + std::to_string(saveData.score), FONT_LOCATION, WINDOW_WIDTH / 25, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2.3, 1, true, { TEXT_COLOR });


	for (auto& button : buttons)
	{
		button.draw(renderer);
	}
}

void LoseState::OnMouseLeftClick(int PosX, int PosY)
{
	for (auto& button : buttons)
	{
		button.checkCick(PosX, PosY);
	}
}

void LoseState::OnExit()
{
}

void LoseState::PlayAgain()
{
	std::cout << "Play Again" << std::endl;
	game->switchState(std::make_shared<InGameState>(game, game->getRender()));
}
