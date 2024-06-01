#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

InGameRenderer::InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, RenderWrapperBase* renderer)
{
	this->boardLogic = boardLogic;
	this->renderer = renderer;
}

void InGameRenderer::render(std::vector<Button> buttons, int score, int levelScore, int level, int pointsToNextLevel, float pushTimer, float maxPushTimer)
{
	int WINDOW_WIDTH = renderer->getWidth();
	int WINDOW_HEIGHT = renderer->getHeight();
	int TILE_SIDE = boardLogic->getTileSide();

	int ABOVE_UI_POS_Y = WINDOW_HEIGHT / 100;
	int UI_BARS_WIDTH = WINDOW_WIDTH / 10;
	int UI_BARS_HEIGHT = WINDOW_HEIGHT / 40;
	int PUSH_UI_POS_X = WINDOW_WIDTH / 1.2f;
	int SCORE_UI_POS_X = WINDOW_WIDTH / 2;

	renderer->DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
	renderer->RenderImage(ENDLINE_IMAGE, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE - WINDOW_WIDTH / 150, WINDOW_HEIGHT / 5, WINDOW_WIDTH / 150, WINDOW_HEIGHT, 1);
	renderer->RenderText("End Zone", FONT_LOCATION, WINDOW_WIDTH / 40, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE, WINDOW_HEIGHT / 8, 1, false, { {255,255,255} });

	RenderBoardTiles();

	renderer->RenderText("Score:" + std::to_string(score), FONT_LOCATION, WINDOW_HEIGHT / 30, UI_BARS_HEIGHT * 1.4f, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });

	renderer->RenderText("Level:" + std::to_string(level), FONT_LOCATION, WINDOW_HEIGHT / 30, SCORE_UI_POS_X - WINDOW_WIDTH / 10, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });
	renderer->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_GREEN_COLOR);
	renderer->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * (float)levelScore / pointsToNextLevel, UI_BARS_HEIGHT, GREEN_COLOR);

	renderer->RenderText("Push:", FONT_LOCATION, WINDOW_HEIGHT / 30, PUSH_UI_POS_X - WINDOW_WIDTH / 15, UI_BARS_HEIGHT * .2f, 1, false, { TEXT_COLOR });
	renderer->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_RED_COLOR);
	renderer->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * (float)pushTimer / maxPushTimer, UI_BARS_HEIGHT, RED_COLOR);


	for (auto& button : buttons)
	{
		button.draw(renderer);
	}
}

void InGameRenderer::RenderBoardTiles()
{
	int TILE_SIDE = boardLogic->getTileSide();

	for (size_t column_index = 0; column_index < boardLogic->GetTiles().size(); ++column_index) {
		auto& column = boardLogic->GetTiles()[column_index];
		for (size_t tile_index = 0; tile_index < column.size(); ++tile_index) {
			auto& tile = column[tile_index];
			if (tile.GetColor() == Colors::Empty)
				continue;

			Color color = { 255,255,255 };
			switch (tile.GetColor()) {
			case Colors::Blue:
				color = BLUE_COLOR;
				break;
			case Colors::Green:
				color = GREEN_COLOR;
				break;
			case Colors::Red:
				color = RED_COLOR;
				break;
			case Colors::Yellow:
				color = YELLOW_COLOR;
				break;
			default:
				break;
			}
			renderer->RenderImage(TILE_GREY_IMAGE, tile.GetX(), tile.GetY(), TILE_SIDE, TILE_SIDE, 1, color);
			//render->RenderText(std::to_string(column_index) + "," + std::to_string(tile_index),
			//FONT_LOCATION, 15, tile.GetX(), tile.GetY(), 1, false, { {255,255,255} });
		}
	}
}
