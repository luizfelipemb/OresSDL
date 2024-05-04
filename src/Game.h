#pragma once
class Game
{
public:
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void Update();
	bool Running = true;
private:
	int last_frame_time;
};

