#include "StateGoKill.h"
#include "KillerMain.h" 

StateGoKill::StateGoKill(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	_moveFrequence = 3;
}

void StateGoKill::OnEnter() {
	killerMainRef->MapManagerRef->KillerColor = RED;
}

void StateGoKill::Do() {
	if (killerMainRef->PlayerStepMemory % _moveFrequence == 0) 
	{
		killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom); 
		killerMainRef->MapManagerRef->KillerLastRoom = killerMainRef->MapManagerRef->KillerCurrentRoom;
	}

	if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->stateKillerAtDoor);
	}
}

void StateGoKill::OnExit() {
}