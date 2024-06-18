#include "InputHandle.h"
#include <SDL_events.h>

void InputHandler::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		for (InputObserver* observer : observers)
		{
			std::cout << "Quit Input" << std::endl;
			observer->OnQuitWindowClick();
		}
		break;
	case SDL_MOUSEBUTTONDOWN:

		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			int mouseX = event.button.x;
			int mouseY = event.button.y;
			std::cout << "Mouse Button Down with x:" << mouseX << " y:" << mouseY << std::endl;

			for (InputObserver* observer : observers)
			{
				observer->OnMouseLeftClick(mouseX, mouseY);
			}
		}
		break;
	case SDL_MOUSEMOTION:
		break;
	case SDL_KEYDOWN:
		break;
	default:
		break;
	}
}

void InputHandler::RegisterObserver(InputObserver* observer)
{
	observers.push_back(observer);
}

void InputHandler::RemoveObserver(const InputObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	if (it != observers.end())
	{
		observers.erase(it);
	}
}
