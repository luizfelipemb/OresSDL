#pragma once
#include "Render.h"
#include <memory>

class Game
{
public:
	Game();
	void Update();
	bool Running = true;
private:
	int last_frame_time;
	std::unique_ptr<Render> render;
};

