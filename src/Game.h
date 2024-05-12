#pragma once
#include "GameRenderer.h"
#include <memory>
#include "InputHandle.h"
#include "GameStateBase.h"
#include "InGameState.h"
#include "MenuState.h"

class InGameState;
class MenuState;
class Game : public InputObserver
{
public:
	Game();
	void Update();
	bool Running = true;
	void SwitchState(std::shared_ptr<GameStateBase> newState);
	std::shared_ptr<InGameState> inGameState;
	std::shared_ptr<MenuState> menuState;
private:
	void OnQuitWindowClick() override;
	int last_frame_time;
	std::shared_ptr<GameStateBase> currentState;
	std::shared_ptr<RenderWrapperBase> render;
	std::shared_ptr<InputHandler> inputHandle;
};

