#pragma once
#include "SDL.h"
#include <map>
#include <iostream>
#include "RenderWrapperBase.h"

class SDLRenderWrapper : public RenderWrapperBase
{
public:
	SDLRenderWrapper(const char* windowTitle, int windowWidth, int windowHeight, bool fullscreen = false);
	~SDLRenderWrapper();
	void UpdateRender() override;
	bool LoadTexture(std::string fileName) override;
	void RenderImage(std::string filename, int x, int y, int w, int h, double scale) override;
	void ClearFromTextureMap(std::string filename) override;
	void ClearAllTextures() override;
	void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale) override;
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	std::map<std::string, SDL_Texture*> textureMap;
};

