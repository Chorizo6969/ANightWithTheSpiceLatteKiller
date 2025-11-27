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

	std::vector<StateBase*> StateList;

	StateBase* stateCurrent;

	KillerStateBrain();
	~KillerStateBrain();

	StateBase* GetRandomState();

	void SwitchState(StateBase* StateToSwitch);

private: 
	int EnterTries = 0;
	void EnterThePlayerRoom();

};