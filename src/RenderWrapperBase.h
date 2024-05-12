#pragma once
#include <string>
class RenderWrapperBase
{
public:
	virtual void UpdateRender() = 0;
	virtual bool LoadTexture(std::string fileName) = 0;
	virtual void RenderImage(std::string filename, int x, int y, int w, int h, double scale) = 0;
	virtual void ClearFromTextureMap(std::string filename) = 0;
	virtual void ClearAllTextures() = 0;
	virtual void RenderText(const std::string& text, const std::string& fontFile, int fontSize, int x, int y, double scale = 1, bool centered = 0) = 0;
};

