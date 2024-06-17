#include "LoseState.h"
#include "Configs.h"

#define LOSE_TITLE "You Lose"
#define AGAIN_BUTTON_WIDTH WINDOW_WIDTH/8
#define AGAIN_BUTTON_X WINDOW_WIDTH/2 - AGAIN_BUTTON_WIDTH/2

LoseState::LoseState(Game* game, std::unique_ptr<RenderWrapperBase>& render) : game(game), render(render)
{
	loseRenderer = std::make_unique<LoseRenderer>(render);
	Button againButton = {
		AGAIN_BUTTON_X,WINDOW_HEIGHT / 1.5f,AGAIN_BUTTON_WIDTH,WINDOW_HEIGHT / 10, "Again", [&]() { PlayAgain(); }
	};
	buttons.push_back(againButton);
}

void LoseState::OnEnter()
{
}

void LoseState::Update(float deltaTime)
{
	loseRenderer->UpdateRender(buttons, game->GetSaveData());
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
	game->SwitchState(game->inGameState);
}
