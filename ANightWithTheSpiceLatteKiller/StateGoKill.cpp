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

//Can move everywhere, if in the room of player, switch to stateKillerAtDoor
void StateGoKill::Do() {
	if (killerMainRef->PlayerStepMemory % _moveFrequence == 0)
	{
		char killerRoomBeforeMove = killerMainRef->MapManagerRef->KillerCurrentRoom;
		pair<float, float> killerPosBeforeMove = killerMainRef->MapManagerRef->KillerPosition;

		killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom);

		if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom)
		{
			killerMainRef->MapManagerRef->KillerCurrentRoom = killerRoomBeforeMove;
			killerMainRef->MapManagerRef->KillerPosition = killerPosBeforeMove;

			killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->stateKillerAtDoor);
		}
		else
		{
			killerMainRef->MapManagerRef->KillerLastRoom = killerRoomBeforeMove;
		}
	}
}

void StateGoKill::OnExit() {
}