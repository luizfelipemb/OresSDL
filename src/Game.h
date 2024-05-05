#pragma once
#include "GameRenderer.h"
#include "BoardLogic.h"
#include <memory>

class Game
{
public:
	Game();
	void Update();
	bool Running = true;
private:
	int last_frame_time;
	std::shared_ptr<BoardLogic> boardLogic;
	std::unique_ptr<GameRenderer> render;
};

