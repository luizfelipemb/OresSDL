#include "SDLRenderWrapper.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_TTF.h>

SDLRenderWrapper::SDLRenderWrapper(const char* windowTitle, int windowWidth, int windowHeight, bool fullscreen)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (TTF_Init() != 0) {
		std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

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

SDLRenderWrapper::~SDLRenderWrapper()
{
	TTF_Quit();
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

void SDLRenderWrapper::RenderImage(std::string filename, int x, int y, int w, int h, double scale, std::optional<Color> color)
{
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = w * scale;
	destRect.h = h * scale;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	if (textureMap.find(filename) == textureMap.end())
		LoadTexture(filename);

	if (color.has_value()) {
		SDL_SetTextureColorMod(textureMap[filename], color->red, color->green, color->blue);
	}

	if (SDL_RenderCopyEx(renderer, textureMap[filename], NULL, &destRect, 0, NULL, flip) != 0)
		std::cout << SDL_GetError() << std::endl;

	if (color.has_value()) {
		SDL_SetTextureColorMod(textureMap[filename], 255, 255, 255);
	}
}

void SDLRenderWrapper::ClearFromTextureMap(std::string filename)
{
	textureMap.erase(filename);
}

void SDLRenderWrapper::ClearAllTextures()
{
	textureMap.clear();
}

void SDLRenderWrapper::RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale, bool centered)
{
	// Load font
	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (!font) {
		std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
		return;
	}

	// Render text
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{ 0,0,0 });
	if (!surface) {
		std::cerr << "Error rendering text: " << TTF_GetError() << std::endl;
		TTF_CloseFont(font);
		return;
	}

	// Create texture from surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		std::cerr << "Error creating texture from surface: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		return;
	}

	// Calculate text dimensions
	int textWidth = static_cast<int>(surface->w * scale);
	int textHeight = static_cast<int>(surface->h * scale);

	// Adjust position for centered text
	if (centered) {
		x -= textWidth / 2;
		y -= textHeight / 2;
	}

	// Destination rectangle
	SDL_Rect destRect = { x, y, textWidth, textHeight };

	// Render text
	if (SDL_RenderCopy(renderer, texture, NULL, &destRect) != 0) {
		std::cerr << "Error rendering text: " << SDL_GetError() << std::endl;
	}

	// Clean up
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
}

void SDLRenderWrapper::DrawRectangle(int x, int y, int width, int height, Color color) {
	// Set render color
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);

	// Define rectangle
	SDL_Rect rect = { x, y, width, height };

	// Draw rectangle
	SDL_RenderFillRect(renderer, &rect);
}