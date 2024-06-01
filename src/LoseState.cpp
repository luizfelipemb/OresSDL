#include "LoseState.h"

#include "InGameState.h"

#define LOSE_TITLE "You Lose"


LoseState::LoseState(Game* game, RenderWrapperBase* renderer) : game(game), renderer(renderer)
{
	int AGAIN_BUTTON_WIDTH = renderer->getWidth() / 8;
	int AGAIN_BUTTON_X = renderer->getWidth() / 2 - AGAIN_BUTTON_WIDTH / 2;

	loseRenderer = std::make_unique<LoseRenderer>(renderer);
	Button againButton = { AGAIN_BUTTON_X,renderer->getHeight() / 1.5f,AGAIN_BUTTON_WIDTH,renderer->getHeight() / 10,"Again", [&]() { PlayAgain(); } };
	buttons.push_back(againButton);
}

void LoseState::OnEnter()
{
}

void LoseState::update(float deltaTime)
{
	loseRenderer->render(buttons, game->getSaveData());
}
void LoseState::OnMouseLeftClick(int PosX, int PosY)
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

void LoseState::OnExit()
{
}

void LoseState::PlayAgain()
{
	std::cout << "Play Again" << std::endl;
	game->switchState(std::make_unique<InGameState>(game, game->getRender()));
}
