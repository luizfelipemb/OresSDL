#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

InGameRenderer::InGameRenderer(std::shared_ptr<BoardLogic> boardLogic, std::shared_ptr<RenderWrapperBase> render)
{
	this->boardLogic = boardLogic;
	this->render = render;
}

void InGameRenderer::UpdateRender()
{
	render->RenderImage(BACKGROUND_IMAGE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);
	//Update Board Tiles
	for (auto& tile : boardLogic->GetTiles()) {
		for (auto& tile2 : tile)
		{
			if (tile2.GetColor() == Colors::Empty)
				continue;
			std::string image;
			switch (tile2.GetColor())
			{
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
			render->RenderImage(image, tile2.GetX(), tile2.GetY(), TILE_SIDE, TILE_SIDE, 1);
			render->RenderText(std::to_string(tile2.GetX())+";"+ std::to_string(tile2.GetY()), "assets/pixel.ttf", 10, tile2.GetX(), tile2.GetY(), 1);
		}
	}

	render->UpdateRender();
}
