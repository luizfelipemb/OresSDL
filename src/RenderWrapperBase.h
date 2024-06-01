#pragma once
#include <string>
#include <optional>
#include <cstdint>

struct Color {
	std::uint8_t red;
	std::uint8_t green;
	std::uint8_t blue;
};

class RenderWrapperBase
{
public:
	virtual void present() = 0;
	virtual void RenderImage(const std::string& filename, int x, int y, int w, int h, double scale, std::optional<Color> color = std::nullopt) = 0;
	virtual void ClearFromTextureMap(const std::string& filename) = 0;
	virtual void ClearAllTextures() = 0;
	virtual void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale = 1, bool centered = 0, std::optional<Color> color = std::nullopt) = 0;
	virtual void DrawRectangle(int x, int y, float width, float height, const Color& color, unsigned char alpha = 255) = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual void setBackGroundColor(const Color& color) = 0;
	virtual void clear() const = 0;
};

