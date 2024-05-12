#include "MenuRenderer.h"
#include "Configs.h"

MenuRenderer::MenuRenderer(std::shared_ptr<RenderWrapperBase> render) : render(render)
{

}

void MenuRenderer::UpdateRender(std::vector<Button> buttons)
{
	render->RenderImage(BACKGROUND_IMAGE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);
	for (auto& button : buttons)
	{
			render->RenderImage(BUTTON_IMAGE, button.x,button.y,button.width,button.height,1);
			render->RenderText(button.text, FONT_LOCATION, button.height/2, button.x + button.width/2, button.y + button.height/2 - 8,1,1);
	}
	
}
