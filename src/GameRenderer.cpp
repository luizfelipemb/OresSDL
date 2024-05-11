#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

InGameRenderer::InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, std::shared_ptr<RenderWrapperBase> render)
{
	this->boardLogic = boardLogic;
	this->render = render;
}

void InGameRenderer::UpdateRender(int score, int level, int pointsToNextLevel)
{
	render->RenderImage(BACKGROUND_IMAGE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);
	//Update Board Tiles
	for (size_t column_index = 0; column_index < boardLogic->GetTiles().size(); ++column_index) {
		auto& column = boardLogic->GetTiles()[column_index];
		for (size_t tile_index = 0; tile_index < column.size(); ++tile_index) {
			auto& tile = column[tile_index];
			if (tile.GetColor() == Colors::Empty)
				continue;
			std::string image;
			switch (tile.GetColor()) {
			case Colors::Grey:
				image = TILE_GREY_IMAGE;
				break;
			case Colors::Blue:
				image = TILE_BLUE_IMAGE;
				break;
			case Colors::Green:
				image = TILE_GREEN_IMAGE;
				break;
			case Colors::Red:
				image = TILE_RED_IMAGE;
				break;
			case Colors::Yellow:
				image = TILE_YELLOW_IMAGE;
				break;
			default:
				break;
			}
			render->RenderImage(image, tile.GetX(), tile.GetY(), TILE_SIDE, TILE_SIDE, 1);
			render->RenderText(std::to_string(column_index) + "," + std::to_string(tile_index),
				FONT_LOCATION, 15, tile.GetX(), tile.GetY(), 1);
		}
	}
	render->RenderText("Score:" + std::to_string(score)+"/"+ std::to_string(pointsToNextLevel), FONT_LOCATION, 30, 0, 0, 1);
	render->RenderText("Level:" + std::to_string(level), FONT_LOCATION, 30, WINDOW_WIDTH / 2, 0, 1);

	render->UpdateRender();
}
