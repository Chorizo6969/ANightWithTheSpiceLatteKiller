#pragma once

#include "StateBase.h"
class StateKillerAtDoor : public StateBase
{
public:

	StateKillerAtDoor(KillerMain* killerMainRef);

	void OnEnter() override;
	void Do() override;
	void OnExit() override;

private:
	int stepsRemaining;
	const int MAX_STEPS = 20;
};

