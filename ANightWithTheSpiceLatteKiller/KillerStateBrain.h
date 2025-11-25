#include "StateStalker.h"
#include "StateWalker.h"
#include "StateKiller.h"

#include <vector>

#pragma once
class KillerStateBrain
{
public:
	//KillerMain* KillerMainRef;
	StateWalker* StateWalker;
	StateStalker* StateStalker;
	StateKiller* StateKiller;

	std::vector<StateBase*> StateList = { StateWalker, StateStalker, StateKiller };

	StateBase* StateCurrent;

	StateBase* GetRandomState();

	void SwitchState(StateBase* StateToSwitch);
};

