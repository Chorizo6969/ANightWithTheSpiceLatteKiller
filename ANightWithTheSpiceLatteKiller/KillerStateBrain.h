#include "StateStalker.h"
#include "StateWalker.h"
#include "StateKiller.h"

#pragma once
class KillerStateBrain
{
public:
	KillerMain* KillerMainRef;
	StateWalker* StateWalker;
	StateStalker* StateStalker;
	StateKiller* StateKiller;

	StateBase StateCurrent;

	StateBase* RandomState();

	void SwitchState(StateBase StateToSwitch);
};

