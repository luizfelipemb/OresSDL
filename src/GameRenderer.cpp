#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

InGameRenderer::InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, std::shared_ptr<RenderWrapperBase> render)
{
	this->boardLogic = boardLogic;
	this->render = render;
}

void InGameRenderer::UpdateRender(int score,int levelScore, int level, int pointsToNextLevel, float pushTimer, float maxPushTimer)
{
	render->DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
	render->RenderImage(SIGN_IMAGE, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE - 6, WINDOW_HEIGHT/5, 6, 790, 1);
	render->RenderText("End Zone", FONT_LOCATION, 30, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE, 100, 1, false, { {255,255,255} });
	RenderBoardTiles();

	render->RenderText("Score:" + std::to_string(score), FONT_LOCATION, 30, WINDOW_WIDTH*0.04f, 0, 1, false, { TEXT_COLOR });
	render->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_GREEN_COLOR);
	render->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH *(float)levelScore / pointsToNextLevel, UI_BARS_HEIGHT, GREEN_COLOR);
	
	render->RenderText("Level:" + std::to_string(level), FONT_LOCATION, 30, SCORE_UI_POS_X - 140, 0, 1,false, { TEXT_COLOR });

	render->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_RED_COLOR);
	render->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * (float)pushTimer/maxPushTimer, UI_BARS_HEIGHT, RED_COLOR);
	render->RenderText("Push:", FONT_LOCATION, 30, PUSH_UI_POS_X - UI_BARS_WIDTH, 0, 1, false, { TEXT_COLOR });

	render->UpdateRender();
}

void InGameRenderer::RenderBoardTiles()
{
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
			render->RenderImage(TILE_GREY_IMAGE, tile.GetX(), tile.GetY(), TILE_SIDE, TILE_SIDE, 1, color);
			render->RenderText(std::to_string(column_index) + "," + std::to_string(tile_index),
				FONT_LOCATION, 15, tile.GetX(), tile.GetY(), 1, false, { {255,255,255} });
		}
	}
}
