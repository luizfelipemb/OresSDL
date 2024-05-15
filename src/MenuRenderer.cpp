#include "MenuRenderer.h"
#include "Configs.h"

MenuRenderer::MenuRenderer(std::shared_ptr<RenderWrapperBase> render) : render(render)
{

}

void MenuRenderer::UpdateRender(std::vector<Button> buttons)
{
	render->DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
	render->RenderText(MENU_TITLE, FONT_LOCATION, 100, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 10, 1, true, { TEXT_COLOR });
	render->RenderText(MENU_SUBTITLE, FONT_LOCATION, 40, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5, 1, true, { TEXT_COLOR });
	for (auto& button : buttons)
	{
			render->RenderImage(BUTTON_IMAGE, button.x,button.y,button.width,button.height,1);
			render->RenderText(button.text, FONT_LOCATION, button.height/2, button.x + button.width/2, button.y + button.height/2 - 8,1,true);
	}
	
}