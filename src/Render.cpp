#include "Render.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Configs.h"
#include <string>

Render::Render()
{
	SDL_Init(SDL_INIT_VIDEO);

	int flags = 0;
	if (WINDOW_FULLSCREEN)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	window = SDL_CreateWindow(
		WINDOW_TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		flags
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void Render::UpdateRender()
{
	Load("assets/background.jpg");
	Draw("assets/background.jpg",0,0,WINDOW_WIDTH, WINDOW_HEIGHT,1,0);
	SDL_RenderPresent(renderer);
}

bool Render::Load(std::string fileName)
{
	if (textureMap.find(fileName) != textureMap.end())
		return false;

	SDL_Surface* tempSurf = IMG_Load(fileName.c_str());

	if (tempSurf == 0)
	{
		std::cout << "could not load image named: '" << fileName.c_str() << "'!!!" << std::endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurf);

	SDL_FreeSurface(tempSurf);

	if (texture != 0)
	{
		std::cout << "Texture loaded successfully... ('" << fileName.c_str() << "')" << std::endl;
		textureMap[fileName] = texture;
		return true;
	}

	std::cout << "Could not create texture from surface!!! ('" << fileName.c_str() << "')" << std::endl;

	return false;
}

void Render::Draw(std::string filename, int x, int y, int w, int h, double scale, double r, SDL_RendererFlip flip)
{
	SDL_Rect destRect;

	destRect.x = x;
	destRect.y = y;
	destRect.w = w;
	destRect.h = h;
	destRect.w *= scale;
	destRect.h *= scale;

	if(SDL_RenderCopyEx(renderer, textureMap[filename], NULL, &destRect, 0, NULL, flip) != 0)
		std::cout << SDL_GetError() << std::endl;
}

void Render::ClearFromTextureMap(std::string filename)
{
	textureMap.erase(filename);
}

void Render::ClearAllTextures()
{
	textureMap.clear();
}