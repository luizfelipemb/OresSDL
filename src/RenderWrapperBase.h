#pragma once
#include <string>
class RenderWrapperBase
{
public:
	virtual void UpdateRender() = 0;
	virtual bool LoadTexture(std::string fileName) = 0;
	virtual void Draw(std::string filename, int x, int y, int w, int h, double scale) = 0;
	virtual void ClearFromTextureMap(std::string filename) = 0;
	virtual void ClearAllTextures() = 0;
};

