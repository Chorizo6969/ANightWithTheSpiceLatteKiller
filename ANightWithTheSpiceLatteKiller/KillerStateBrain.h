#include "StateGoStalk.h"
#include "StateGoWalk.h"
#include "StateGoKill.h"

#include <vector>

#pragma once
class KillerStateBrain
{
public:
	StateGoWalk* stateGoWalk;
	StateGoStalk* stateGoStalk;
	StateGoKill* stateGoKill;

	std::vector<StateBase*> StateList = { stateGoWalk, stateGoStalk, stateGoKill };

	StateBase* stateCurrent;

	KillerStateBrain();

	StateBase* GetRandomState();

	void SwitchState(StateBase* StateToSwitch);

};

