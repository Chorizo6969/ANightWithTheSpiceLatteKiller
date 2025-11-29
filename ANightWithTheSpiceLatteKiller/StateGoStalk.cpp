#include "StateGoStalk.h"
#include "KillerMain.h"

StateGoStalk::StateGoStalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	_moveFrequence = 5;
}

void StateGoStalk::OnEnter() {
	killerMainRef->MapManagerRef->KillerColor = BLUE;
}

void StateGoStalk::Do() {
	if (killerMainRef->PlayerStepMemory % _moveFrequence == 0) { //Move each 5 steps
		killerMainRef->KillerMovementRef->MoveKillerSafe(false); //Avoid playerRoom
	}
}

void StateGoStalk::OnExit() {
}