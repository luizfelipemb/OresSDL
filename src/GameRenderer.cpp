#include "GameRenderer.h"
#include "SDLRenderWrapper.h"
#include "Configs.h"

GameRenderer::GameRenderer()
{
	render = std::make_unique<SDLRenderWrapper>();
}

void GameRenderer::UpdateRender()
{
	render->Draw("assets/background.jpg", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);
	render->UpdateRender();
}
