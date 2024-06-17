#pragma once
#include <memory>
#include "InputHandle.h"
#include "GameStateBase.h"
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
	void SwitchState(std::unique_ptr<GameStateBase>& newState);
	SaveData GetSaveData() const { return mSaveData; }
	void SetSaveData(const SaveData save) { mSaveData = save; }
private:
	void OnQuitWindowClick() override;

public:
	bool running = true;
	std::unique_ptr<GameStateBase> inGameState;
	std::unique_ptr<GameStateBase> menuState;
	std::unique_ptr<GameStateBase> loseState;

private:
	int mLastFrameTime;
	SaveData mSaveData = {0, 0};
	std::unique_ptr<GameStateBase> mCurrentState;
	std::unique_ptr<RenderWrapperBase> mRender;
	std::unique_ptr<InputHandler> mInputHandle;
};
