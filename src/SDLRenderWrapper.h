#pragma once
#include "SDL.h"
#include <map>
#include <iostream>
#include "RenderWrapperBase.h"

class SDLRenderWrapper : public RenderWrapperBase
{
public:
	SDLRenderWrapper();
	void UpdateRender() override;
	bool LoadTexture(std::string fileName) override;
	void Draw(std::string filename, int x, int y, int w, int h, double scale) override;
	void ClearFromTextureMap(std::string filename) override;
	void ClearAllTextures() override;
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	std::map<std::string, SDL_Texture*> textureMap;
};

