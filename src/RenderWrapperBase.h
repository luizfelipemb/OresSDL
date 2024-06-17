#pragma once
#include <string>
#include <optional>
#include <cstdint>

struct Color
{
	std::uint8_t red;
	std::uint8_t green;
	std::uint8_t blue;
};

class RenderWrapperBase
{
public:
	virtual ~RenderWrapperBase() = default;
	virtual void UpdateRender() = 0;
	virtual bool LoadTexture(std::string fileName) = 0;
	virtual void RenderImage(std::string filename, int x, int y, int w, int h, double scale,
	                         std::optional<Color> color = std::nullopt) = 0;
	virtual void ClearFromTextureMap(std::string filename) = 0;
	virtual void ClearAllTextures() = 0;
	virtual void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y,
	                        double scale = 1, bool centered = false, std::optional<Color> color = std::nullopt) = 0;
	virtual void DrawRectangle(int x, int y, float width, float height, Color color) = 0;
};
