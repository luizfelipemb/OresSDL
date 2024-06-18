#pragma once
#include <vector>
#include <iostream>
#include "GameStateBase.h"

class InputHandler
{
public:
	void HandleEvents();
	void RegisterObserver(InputObserver* observer);
	void RemoveObserver(const InputObserver* observer);

	std::vector<InputObserver*> observers;
};
