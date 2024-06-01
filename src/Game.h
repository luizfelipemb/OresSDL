#pragma once
#include "GameRenderer.h"
#include "InputHandle.h"
#include "GameStateBase.h"
#include "SaveData.h"

#include <memory>

class InGameState;
class MenuState;
class LoseState;

class Game : public InputObserver
{
public:
	Game(RenderWrapperBase* renderer);

	bool processEvents();

	void update();

	void render();

	void switchState(std::unique_ptr<GameStateBase> newState);

	const SaveData getSaveData() const { return saveData; };

	const void setSaveData(SaveData save) { saveData = save; };

	bool isRunning() const { return running; };

	RenderWrapperBase* getRender() const { return renderer; };
private:
	void stop() override;

private:
	float lastFrameTime;
	SaveData saveData = { 0,0 };
	bool running = true;

	std::unique_ptr<GameStateBase> currentState;
	RenderWrapperBase* renderer;
	InputHandler inputHandle;
};

