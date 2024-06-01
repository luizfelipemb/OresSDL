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
	clear();
}

SDLRenderWrapper::~SDLRenderWrapper()
{
	ClearAllTextures();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
}

void SDLRenderWrapper::present()
{
	SDL_RenderPresent(renderer);
}

SDL_Texture* SDLRenderWrapper::LoadTexture(const std::string& fileName)
{
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
	}
	else {
		std::cout << "Could not create texture from surface!!! ('" << fileName.c_str() << "')" << std::endl;
	}


	return texture;
}

void SDLRenderWrapper::RenderImage(const std::string& filename, int x, int y, int w, int h, double scale, std::optional<Color> color)
{
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = w * scale;
	destRect.h = h * scale;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	auto texture = getTexture(filename);

	if (color.has_value()) {
		SDL_SetTextureColorMod(texture, color->red, color->green, color->blue);
	}

	if (SDL_RenderCopyEx(renderer, texture, NULL, &destRect, 0, NULL, flip) != 0)
		std::cout << SDL_GetError() << std::endl;

	if (color.has_value()) {
		SDL_SetTextureColorMod(texture, 255, 255, 255);
	}
}

void SDLRenderWrapper::ClearFromTextureMap(const std::string& filename)
{
	SDL_DestroyTexture(textureMap[filename]);
	textureMap.erase(filename);
}

void SDLRenderWrapper::ClearAllTextures()
{
	for (auto& [name, tex] : textureMap)
	{
		SDL_DestroyTexture(tex);
	}
	textureMap.clear();
}

void SDLRenderWrapper::RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale, bool centered, std::optional<Color> color)
{
	// Load font
	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (!font) {
		std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
		return;
	}

	// Render text
	SDL_Color textColor = { 0, 0, 0 }; // Default color (black)
	if (color.has_value()) {
		textColor = SDL_Color{ color->red, color->green, color->blue };
	}
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
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


void SDLRenderWrapper::DrawRectangle(int x, int y, float width, float height, const Color& color) {
	// Set render color
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);

	// Define rectangle
	SDL_Rect rect = { x, y, width, height };

	// Draw rectangle
	SDL_RenderFillRect(renderer, &rect);
}

void SDLRenderWrapper::setBackGroundColor(const Color& color)
{
	backgroundColor = color;
}

void SDLRenderWrapper::clear() const
{
	SDL_SetRenderDrawColor(renderer, backgroundColor.red, backgroundColor.green, backgroundColor.blue, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

int SDLRenderWrapper::getWidth() const
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	return w;
}

int SDLRenderWrapper::getHeight() const
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	return h;
}

SDL_Texture* SDLRenderWrapper::getTexture(std::string filename)
{
	auto result = textureMap.find(filename);
	if (result == textureMap.end())
	{
		auto texutre = LoadTexture(filename);
		textureMap[filename] = texutre;
		return texutre;
	}
	return result->second;
}
