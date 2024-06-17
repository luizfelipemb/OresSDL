#pragma once
#include <vector>
#include <iostream>
#include "GameStateBase.h"

class InputHandler
{
public:
	void HandleEvents();
	std::vector<InputObserver*> observers;

	void RegisterObserver(InputObserver* observer)
	{
		observers.push_back(observer);
	}

	void RemoveObserver(const InputObserver* observer)
	{
		auto it = std::find(observers.begin(), observers.end(), observer);
		if (it != observers.end())
		{
			observers.erase(it);
		}
	}
};
