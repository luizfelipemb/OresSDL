#pragma once
#include <vector>
#include <iostream>
#include "GameStateBase.h"
class InputHandler
{
public:
	void HandleEvents();
	std::vector<std::shared_ptr<InputObserver>> observers;
	void RegisterObserver(std::shared_ptr<InputObserver> observer) {
		observers.push_back(observer);
	}

	void RemoveObserver(std::shared_ptr<InputObserver> observer) {
		// You can implement the removal logic if needed.
	}
};