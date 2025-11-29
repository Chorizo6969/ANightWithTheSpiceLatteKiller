#include "StateGoStalk.h"
#include "KillerMain.h"

StateGoStalk::StateGoStalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	_moveSpeed = 5;
}

void StateGoStalk::OnEnter() {
	//std::cout << "Enter Stalk State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = BLUE;
}

void StateGoStalk::Do() {
	if (killerMainRef->PlayerStepMemory % _moveSpeed == 0) { //Move each 5 steps
		killerMainRef->KillerMovementRef->MoveKillerSafe(false); //Avoid playerRoom
	}

	//std::cout << "Killer is stalking player" << std::endl;
}

void StateGoStalk::OnExit() {
	//std::cout << "Exit Stalk State" << std::endl;
}