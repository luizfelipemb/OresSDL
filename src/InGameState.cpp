#include "InGameState.h"

InGameState::InGameState(Game* game, std::shared_ptr<RenderWrapperBase> render)
{
	this->game = game;
	boardLogic = std::make_shared<BoardLogic>();
	gameRenderer = std::make_shared<InGameRenderer>(boardLogic, render);

	Button pushButton = { WINDOW_WIDTH/1.1f, 
						WINDOW_HEIGHT - BOARD_INITIALCOLUMN_HEIGHT_POS + WINDOW_HEIGHT/40,
						WINDOW_WIDTH / 20,
						WINDOW_HEIGHT / 20,"<push", [&]() { PushButtonClicked(); } };
	buttons.push_back(pushButton);
}

void InGameState::OnEnter()
{
	boardLogic->ResetTotalBlocksBroke();
	boardLogic->ResetBoard();
	pushTimer = 0;
	currentLevel = 1;
	pointsToNextLevel = NEXT_LEVEL_SCORE;
	score = 0;
	levelScore = 0;
}

void InGameState::Update(float deltaTime)
{
	PushTimer(deltaTime);

	gameRenderer->UpdateRender(buttons,score,levelScore,currentLevel,pointsToNextLevel,pushTimer,PUSH_TIMER);
}

void InGameState::OnExit()
{

}

void InGameState::OnMouseLeftClick(int PosX, int PosY)
{
	std::cout << "OnMouseLeftClick" << std::endl;
	boardLogic->TryBreakTileAt(PosX, PosY);
	score = boardLogic->GetTotalBlocksBroke();
	levelScore = boardLogic->GetBlocksBroke();

	bool CanGoToNextLevel = levelScore >= pointsToNextLevel;
	if (CanGoToNextLevel)
	{
		levelScore = 0;
		currentLevel++;
		pointsToNextLevel = std::ceil(pointsToNextLevel * NEXT_LEVEL_SCORE_MULTIPLY);
		boardLogic->ResetBoard();
	}

	for (auto& button : buttons)
	{
		if (PosX >= button.x && PosX <= button.x + button.width &&
			PosY >= button.y && PosY <= button.y + button.height)
		{
			button.OnClick();
		}
	}
}

void InGameState::PushButtonClicked()
{
	pushTimer = 0;
	if (!boardLogic->TryAddNewColumn()) 
	{
		GameOver();
	}
}

void InGameState::PushTimer(float deltaTime)
{
	pushTimer += deltaTime;
	if (pushTimer >= PUSH_TIMER)
	{
		if (!boardLogic->TryAddNewColumn())
		{
			GameOver();
		}
		pushTimer = 0;
	}
}

void InGameState::GameOver()
{
	game->SetSaveData({ score,currentLevel });
	game->SwitchState(game->loseState);
}