#include "StateKillerAtDoor.h"
#include "KillerMain.h" 

StateKillerAtDoor::StateKillerAtDoor(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	stepsRemaining = 0;
}

void StateKillerAtDoor::OnEnter() {
	stepsRemaining = MAX_STEPS;
	killerMainRef->MapManagerRef->KillerColor = MAGENTA;
}

void StateKillerAtDoor::Do() {
	stepsRemaining--;
	killerMainRef->DialoguePrinterRef->WriteDialogue("killer", "try_open_door");
	if (stepsRemaining <= 0) {
		killerMainRef->GameOver();
	}

	if (killerMainRef->MapManagerRef->KillerCurrentRoom != killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->GetRandomPatrolState());
	}
}

void StateKillerAtDoor::OnExit() {
}
