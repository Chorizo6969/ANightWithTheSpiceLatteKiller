#include "StateKillerAtDoor.h"
#include "KillerMain.h" 

StateKillerAtDoor::StateKillerAtDoor(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	stepsRemaining = 0;
	playerRoomWhenKnocking = 0;
}

void StateKillerAtDoor::OnEnter() {
	stepsRemaining = MAX_STEPS;
	killerMainRef->MapManagerRef->KillerColor = MAGENTA;

	playerRoomWhenKnocking = killerMainRef->MapManagerRef->PlayerCurrentRoom;

	
}

void StateKillerAtDoor::Do() {
	if (killerMainRef->PlayerStepMemory % _doorKnockFrequence == 0)
	{
		stepsRemaining--;
		killerMainRef->DialoguePrinterRef->WriteDialogue("killer", "try_open_door");
		killerMainRef->SoundRef->PlaySFX("Knock.mp3");

		if (stepsRemaining <= 0) {
			killerMainRef->KillerMovementRef->MoveKillerFix(playerRoomWhenKnocking);
			killerMainRef->GameOver();
			return;
		}
	}
	if (killerMainRef->MapManagerRef->PlayerCurrentRoom != playerRoomWhenKnocking) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->GetRandomPatrolState());
	}
}

void StateKillerAtDoor::OnExit() {
}
