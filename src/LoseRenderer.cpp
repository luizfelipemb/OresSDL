#include "LoseRenderer.h"
#include "Configs.h"

LoseRenderer::LoseRenderer(std::shared_ptr<RenderWrapperBase> render) : render(render)
{
}

void LoseRenderer::UpdateRender(std::vector<Button> buttons, SaveData saveData)
{
	render->DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
	render->RenderText(LOSE_TITLE, FONT_LOCATION, 100, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 10, 1, true, { TEXT_COLOR });
	render->RenderText("Level:" + std::to_string(saveData.level) , FONT_LOCATION, 30, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3, 1, true, { TEXT_COLOR });
	render->RenderText("Score:" + std::to_string(saveData.score), FONT_LOCATION, 30, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2.3, 1, true, { TEXT_COLOR });
	

	for (auto& button : buttons)
	{
		render->RenderImage(BUTTON_IMAGE, button.x, button.y, button.width, button.height, 1);
		render->RenderText(button.text, FONT_LOCATION, button.height / 2, button.x + button.width / 2, button.y + button.height / 2 - 8, 1, true);
	}
}
