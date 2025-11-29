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

//Can move everywhere, except the player current room
void StateGoStalk::Do() {
	if (killerMainRef->PlayerStepMemory % _moveFrequence == 0) {
		killerMainRef->KillerMovementRef->MoveKillerSafe(false); //Avoid playerRoom
	}
}

void StateGoStalk::OnExit() {
}