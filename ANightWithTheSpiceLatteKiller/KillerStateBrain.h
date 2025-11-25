#include "StateGoStalk.h"
#include "StateGoWalk.h"
#include "StateGoKill.h"

#include <vector>

#pragma once
class KillerStateBrain
{
public:
	StateGoWalk* StateWalker;
	StateGoStalk* StateStalker;
	StateGoKill* StateKiller;

	std::vector<StateBase*> StateList = { StateWalker, StateStalker, StateKiller };

	StateBase* StateCurrent;

	StateBase* GetRandomState();

	void SwitchState(StateBase* StateToSwitch);
};

