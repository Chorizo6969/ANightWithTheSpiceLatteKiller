#pragma once

#include "StateGoStalk.h"
#include "StateGoWalk.h"
#include "StateGoKill.h"
#include "StateKillerAtDoor.h"

#include <vector>

//forward declaration
class KillerMain;
class StateGoWalk;
class StateGoStalk;
class StateGoKill;
class StateKillerAtDoor;

class KillerStateBrain
{
public:
	KillerMain* killerMainRef;

	StateGoWalk* stateGoWalk;
	StateGoStalk* stateGoStalk;
	StateGoKill* stateGoKill;
	StateKillerAtDoor* stateKillerAtDoor;

	std::vector<StateBase*> PatrolStateList;

	StateBase* stateCurrent;

	KillerStateBrain(KillerMain* KillerMainRef);
	~KillerStateBrain();

	StateBase* GetRandomPatrolState();

	void SwitchState(StateBase* StateToSwitch);
};