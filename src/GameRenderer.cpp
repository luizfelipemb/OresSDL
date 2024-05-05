#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

GameRenderer::GameRenderer(std::shared_ptr<BoardLogic> boardLogic)
{
	this->boardLogic = boardLogic;
	render = std::make_unique<SDLRenderWrapper>(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN);
}

void GameRenderer::UpdateRender()
{
	render->Draw(BACKGROUND_IMAGE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);

	for (auto& tile : boardLogic->GetTiles()) {
		for (auto& tile2 : tile) {
			render->Draw(TILE_IMAGE, tile2.GetX(), tile2.GetY(), TILE_SIDE, TILE_SIDE, 1);
		}
	}

	render->UpdateRender();
}
