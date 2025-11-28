#pragma once

#include "StateGoStalk.h"
#include "StateGoWalk.h"
#include "StateGoKill.h"

#include <vector>

//forward declaration
class KillerMain;
class StateGoWalk;
class StateGoStalk;
class StateGoKill;

class KillerStateBrain
{
public:
	KillerMain* killerMainRef;

	StateGoWalk* stateGoWalk;
	StateGoStalk* stateGoStalk;
	StateGoKill* stateGoKill;

	std::vector<StateBase*> StateList;

	StateBase* stateCurrent;

	KillerStateBrain(KillerMain* KillerMainRef);
	~KillerStateBrain();

	StateBase* GetRandomState();

	void SwitchState(StateBase* StateToSwitch);
};