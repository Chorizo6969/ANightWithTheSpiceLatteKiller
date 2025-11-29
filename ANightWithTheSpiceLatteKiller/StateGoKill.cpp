#include "StateGoKill.h"
#include "KillerMain.h" 

StateGoKill::StateGoKill(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	_moveSpeed = 3;
}

void StateGoKill::OnEnter() {
	//std::cout << "Enter Kill State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = RED;
}

void StateGoKill::Do() {
	if (killerMainRef->PlayerStepMemory % _moveSpeed == 0) { //move each 3 steps
		killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom); // No restriction
		killerMainRef->MapManagerRef->KillerLastRoom = killerMainRef->MapManagerRef->KillerCurrentRoom;
	}
	//std::cout << "Killer is trying to kill player" << std::endl;

	if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->stateKillerAtDoor);
	}
}

void StateGoKill::OnExit() {
	//std::cout << "Exit Kill State" << std::endl;
}

void StateGoKill::TryEnterPlayerRoom() {
	IsTryingToEnterPlayerRoom = true;
	//Play Line
	EnterTries++;
	if (EnterTries == 10) {
		EnterTries = 0;
		killerMainRef->GameOver();
	};
}