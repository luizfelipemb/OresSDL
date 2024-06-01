#pragma once
#include "InputHandle.h"
#include "GameStateBase.h"
#include "SaveData.h"

#include <memory>

class InGameState;
class MenuState;
class LoseState;
class RenderWrapperBase;

class Game : public InputObserver
{
public:
	Game(RenderWrapperBase* renderer);

	bool processEvents();

	void update();

	void render();

	void switchState(std::shared_ptr<GameStateBase> newState);

	const SaveData getSaveData() const { return saveData; };

	const void setSaveData(SaveData save) { saveData = save; };

	bool isRunning() const { return running; };

	RenderWrapperBase* getRender() const { return renderer; };

	std::shared_ptr<GameStateBase> getCurrentState() const { return currentState; };
private:
	void stop() override;

private:
	float lastFrameTime;
	SaveData saveData = { 0,0 };
	bool running = true;

	std::shared_ptr<GameStateBase> currentState;
	RenderWrapperBase* renderer;
	InputHandler inputHandle;
};

