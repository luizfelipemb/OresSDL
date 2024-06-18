#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

InGameRenderer::InGameRenderer(std::unique_ptr<BoardLogic>& boardLogic, std::unique_ptr<RenderWrapperBase>& render)
	:render(render), mBoardLogic(boardLogic)
{
}

void InGameRenderer::UpdateRender(std::vector<Button> buttons, int score, int levelScore, int level,
                                  int pointsToNextLevel, float pushTimer, float maxPushTimer)
{
	render->DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
	render->RenderImage(ENDLINE_IMAGE, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE - WINDOW_WIDTH / 150,
	                    WINDOW_HEIGHT / 5, WINDOW_WIDTH / 150, WINDOW_HEIGHT, 1);
	render->RenderText("End Zone", FONT_LOCATION, WINDOW_WIDTH / 40, WINDOW_WIDTH - TILE_SIDE * BOARD_MAX_COLUMN_SIZE,
	                   WINDOW_HEIGHT / 8, 1, false, {{255, 255, 255}});

	RenderBoardTiles();

	render->RenderText("Score:" + std::to_string(score), FONT_LOCATION, WINDOW_HEIGHT / 30, UI_BARS_HEIGHT * 1.4f,
	                   UI_BARS_HEIGHT * .2f, 1, false, {TEXT_COLOR});

	render->RenderText("Level:" + std::to_string(level), FONT_LOCATION, WINDOW_HEIGHT / 30,
	                   SCORE_UI_POS_X - WINDOW_WIDTH / 10, UI_BARS_HEIGHT * .2f, 1, false, {TEXT_COLOR});
	render->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_GREEN_COLOR);
	render->DrawRectangle(SCORE_UI_POS_X, ABOVE_UI_POS_Y,
	                      UI_BARS_WIDTH * static_cast<float>(levelScore) / pointsToNextLevel, UI_BARS_HEIGHT,
	                      GREEN_COLOR);

	render->RenderText("Push:", FONT_LOCATION, WINDOW_HEIGHT / 30, PUSH_UI_POS_X - WINDOW_WIDTH / 15,
	                   UI_BARS_HEIGHT * .2f, 1, false, {TEXT_COLOR});
	render->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH, UI_BARS_HEIGHT, DARK_RED_COLOR);
	render->DrawRectangle(PUSH_UI_POS_X, ABOVE_UI_POS_Y, UI_BARS_WIDTH * pushTimer / maxPushTimer, UI_BARS_HEIGHT,
	                      RED_COLOR);


	for (auto& button : buttons)
	{
		render->RenderImage(BUTTON_IMAGE, button.x, button.y, button.width, button.height, 1);
		render->RenderText(button.text, FONT_LOCATION, button.width / 4, button.x + button.width / 2,
		                   button.y + button.height / 2.5f, 1, true);
	}

	render->UpdateRender();
}

void InGameRenderer::RenderBoardTiles()
{
	for (size_t column_index = 0; column_index < mBoardLogic->GetTiles().size(); ++column_index)
	{
		auto& column = mBoardLogic->GetTiles()[column_index];
		for (size_t tile_index = 0; tile_index < column.size(); ++tile_index)
		{
			auto& tile = column[tile_index];
			if (tile.GetColor() == Colors::Empty)
				continue;

			Color color = {255, 255, 255};
			switch (tile.GetColor())
			{
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
			//render->RenderText(std::to_string(column_index) + "," + std::to_string(tile_index),
			//FONT_LOCATION, 15, tile.GetX(), tile.GetY(), 1, false, { {255,255,255} });
		}
	}
}
