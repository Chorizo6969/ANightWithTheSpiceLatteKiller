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
	int _doorKnockFrequence = 3;
	int stepsRemaining; //steps until the gameOver
	const int MAX_STEPS = 15; //start steps of stepsRemaining
	char playerRoomWhenKnocking;
};

