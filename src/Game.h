#pragma once
#include "GameRenderer.h"
#include <memory>
#include "InputHandle.h"
#include "GameStateBase.h"
#include "InGameState.h"
#include "MenuState.h"
#include "LoseState.h"
#include "SaveData.h"

class InGameState;
class MenuState;
class LoseState;

class Game : public InputObserver
{
public:
	Game();
	void Update();
	void SwitchState(std::shared_ptr<GameStateBase> newState);
	const SaveData GetSaveData() const { return saveData; };
	const void SetSaveData(SaveData save) { saveData = save; };

	bool Running = true;
	std::shared_ptr<InGameState> inGameState;
	std::shared_ptr<MenuState> menuState;
	std::shared_ptr<LoseState> loseState;

private:
	void OnQuitWindowClick() override;
	int last_frame_time;
	SaveData saveData = { 0,0 };
	std::shared_ptr<GameStateBase> currentState;
	std::shared_ptr<RenderWrapperBase> render;
	std::shared_ptr<InputHandler> inputHandle;
};

