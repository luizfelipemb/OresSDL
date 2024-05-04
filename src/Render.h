#pragma once
#include "SDL.h"
#include <map>
#include <iostream>

class Render
{
public:
	Render();
	void UpdateRender();
private:
	bool Load(std::string fileName);
	void Draw(std::string filename, int x, int y, int w, int h, double scale, double r, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void ClearFromTextureMap(std::string filename);
	void ClearAllTextures();

	SDL_Renderer* renderer;
	SDL_Window* window;
	std::map<std::string, SDL_Texture*> textureMap;
};

