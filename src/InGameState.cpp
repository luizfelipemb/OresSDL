#include "InGameState.h"

#include "LoseState.h"

InGameState::InGameState(Game* game, RenderWrapperBase* renderer)
	: boardLogic(renderer->getWidth(), renderer->getHeight())
	, game(game)
{
	Button pushButton(renderer->getWidth()/1.1f,
					renderer->getHeight() - boardLogic.getBoardInitialColumnHeightPos() + renderer->getHeight() /40,
					renderer->getWidth() / 20,
					renderer->getHeight() / 20,
		"<push", BUTTON_IMAGE, FONT_LOCATION);
	pushButton.setOnClik([&]() { PushButtonClicked(); });
	buttons.push_back(pushButton);

	renderer->setBackGroundColor(BACKGROUND_COLOR);
}

void InGameState::OnEnter()
{
	boardLogic = BoardLogic(game->getRender()->getWidth(), game->getRender()->getHeight());
	pushTimer = 0;
	currentLevel = 1;
	pointsToNextLevel = NEXT_LEVEL_SCORE;
	score = 0;
	levelScore = 0;
}

void InGameState::update(float deltaTime)
{
	pushTimer += deltaTime;

	score = boardLogic.GetTotalBlocksBroke();
	levelScore = boardLogic.GetBlocksBroke();

	bool CanGoToNextLevel = levelScore >= pointsToNextLevel;
	if (CanGoToNextLevel)
	{
		levelScore = 0;
		currentLevel++;
		pointsToNextLevel = std::ceil(pointsToNextLevel * NEXT_LEVEL_SCORE_MULTIPLY);
		boardLogic.ResetBoard();
	}

	if (pushTimer >= PUSH_TIMER)
	{
		if (!boardLogic.TryAddNewColumn())
		{
			GameOver();
		}
		pushTimer = 0;
	}
}

void InGameState::render(RenderWrapperBase* renderer)
{
	int WINDOW_WIDTH = renderer->getWidth();
	int WINDOW_HEIGHT = renderer->getHeight();
	int TILE_SIDE = boardLogic.getTileSide();

	int ABOVE_UI_POS_Y = WINDOW_HEIGHT / 100;
	int UI_BARS_WIDTH = WINDOW_WIDTH / 10;
	int UI_BARS_HEIGHT = WINDOW_HEIGHT / 40;
	int PUSH_UI_POS_X = WINDOW_WIDTH / 1.2f;
	int SCORE_UI_POS_X = WINDOW_WIDTH / 2;

	renderer->RenderImage(ENDLINE_IMAGE, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE - WINDOW_WIDTH / 150, WINDOW_HEIGHT / 5, WINDOW_WIDTH / 150, WINDOW_HEIGHT, 1);
	renderer->RenderText("End Zone", FONT_LOCATION, WINDOW_WIDTH / 40, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE, WINDOW_HEIGHT / 8, 1, false, { {255,255,255} });

	boardLogic.draw(renderer);

	renderer->RenderText("Score:" + std::to_string(score), FONT_LOCATION, WINDOW_HEIGHT / 30, UI_BARS_HEIGHT * 1.4f, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });

	renderer->RenderText("Level:" + std::to_string(currentLevel), FONT_LOCATION, WINDOW_HEIGHT / 30, SCORE_UI_POS_X - WINDOW_WIDTH / 10, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });
	renderer->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, GREEN_COLOR, 10);
	renderer->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * (float)levelScore / pointsToNextLevel, UI_BARS_HEIGHT, GREEN_COLOR);

	renderer->RenderText("Push:", FONT_LOCATION, WINDOW_HEIGHT / 30, PUSH_UI_POS_X - WINDOW_WIDTH / 15, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });
	renderer->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, RED_COLOR, 10);
	renderer->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * (float)pushTimer / PUSH_TIMER, UI_BARS_HEIGHT, RED_COLOR);


	for (auto& button : buttons)
	{
		button.draw(renderer);
	}
}

void InGameState::OnExit()
{

}

void InGameState::OnMouseLeftClick(int PosX, int PosY)
{
	std::cout << "OnMouseLeftClick" << std::endl;
	boardLogic.TryBreakTileAt(PosX, PosY);

	for (auto& button : buttons)
	{
		button.checkCick(PosX, PosY);
	}
}

void InGameState::PushButtonClicked()
{
	pushTimer = PUSH_TIMER;
}

void InGameState::GameOver()
{
	game->setSaveData({ score,currentLevel });
	game->switchState(std::make_shared<LoseState>(game, game->getRender()));
}