#pragma once
#include "SDL.h"
#include "RenderWrapperBase.h"

#include <iostream>
#include <unordered_map>

class SDLRenderWrapper : public RenderWrapperBase
{
public:
	SDLRenderWrapper(const char* windowTitle, int windowWidth, int windowHeight, bool fullscreen = false);
	~SDLRenderWrapper();

	void present() override;
	void RenderImage(const std::string& filename, int x, int y, int w, int h, double scale, std::optional<Color> color = std::nullopt) override;
	void ClearFromTextureMap(const std::string& filename) override;
	void ClearAllTextures() override;
	void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale = 1, bool centered = 0, std::optional<Color> color = std::nullopt) override;
	void DrawRectangle(int x, int y, float width, float height, const Color& color, unsigned char alpha = 255) override;
	void setBackGroundColor(const Color& color) override;
	void clear() const override;

	int getWidth() const override;
	int getHeight() const override;

private:
	SDL_Texture* getTexture(std::string filename);
	SDL_Texture* LoadTexture(const std::string& fileName);

private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	Color backgroundColor;
	std::unordered_map<std::string, SDL_Texture*> textureMap;
};

