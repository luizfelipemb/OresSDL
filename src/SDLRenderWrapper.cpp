#include "SDLRenderWrapper.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

SDLRenderWrapper::SDLRenderWrapper(const char* windowTitle, int windowWidth, int windowHeight, bool fullscreen)
{
	SDL_Init(SDL_INIT_VIDEO);

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	window = SDL_CreateWindow(
		windowTitle,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		flags
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void SDLRenderWrapper::UpdateRender()
{
	SDL_RenderPresent(renderer);
}

bool SDLRenderWrapper::LoadTexture(std::string fileName)
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

void SDLRenderWrapper::Draw(std::string filename, int x, int y, int w, int h, double scale)
{
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = w;
	destRect.h = h;
	destRect.w *= scale;
	destRect.h *= scale;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	if (textureMap.find(filename) == textureMap.end())
		LoadTexture(filename);

	if(SDL_RenderCopyEx(renderer, textureMap[filename], NULL, &destRect, 0, NULL, flip) != 0)
		std::cout << SDL_GetError() << std::endl;
}

void SDLRenderWrapper::ClearFromTextureMap(std::string filename)
{
	textureMap.erase(filename);
}

void SDLRenderWrapper::ClearAllTextures()
{
	textureMap.clear();
}