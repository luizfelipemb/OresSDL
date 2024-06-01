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
	void present() override;
	bool LoadTexture(std::string fileName) override;
	void RenderImage(std::string filename, int x, int y, int w, int h, double scale, std::optional<Color> color = std::nullopt) override;
	void ClearFromTextureMap(std::string filename) override;
	void ClearAllTextures() override;
	void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale = 1, bool centered = 0, std::optional<Color> color = std::nullopt) override;
	void DrawRectangle(int x, int y, float width, float height, Color color) override;

	int getWidth() const override;
	int getHeight() const override;
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	std::map<std::string, SDL_Texture*> textureMap;
};

