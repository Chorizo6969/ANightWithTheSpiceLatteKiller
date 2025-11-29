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

	//return a random different state of the PatrolStateList
	StateBase* GetRandomPatrolState(); 

	//Switch the state of the killer
	void SwitchState(StateBase* StateToSwitch); 
};