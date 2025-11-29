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

//Each steps, cooldown until gameOver. When player leave the room, switchState
void StateKillerAtDoor::Do() {
	stepsRemaining--;
	killerMainRef->DialoguePrinterRef->WriteDialogue("killer", "try_open_door");
	//killerMainRef->MapManagerRef->TintMap(RED, 50, false);
	if (stepsRemaining <= 0) 
	{
		killerMainRef->GameOver();
	}

	if (killerMainRef->MapManagerRef->KillerCurrentRoom != killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->GetRandomPatrolState());
	}
}

void StateKillerAtDoor::OnExit() {
}
