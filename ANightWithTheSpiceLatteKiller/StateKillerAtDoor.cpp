#include "StateKillerAtDoor.h"
#include "KillerMain.h" 

StateKillerAtDoor::StateKillerAtDoor(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	stepsRemaining = 0;
}

void StateKillerAtDoor::OnEnter() {
	std::cout << "Enter AtDoor State" << std::endl;
	stepsRemaining = MAX_STEPS;
	killerMainRef->MapManagerRef->KillerColor = MAGENTA;
}

void StateKillerAtDoor::Do() {
	stepsRemaining--;
	//Dialogue trying to enter the room
	std::cout << "Killer is trying to enter the room" << std::endl;
	if (stepsRemaining <= 0) {
		killerMainRef->GameOver();
	}

	if (killerMainRef->MapManagerRef->KillerCurrentRoom != killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerBrainRef->SwitchState(killerMainRef->KillerBrainRef->GetRandomPatrolState());
	}

}

void StateKillerAtDoor::OnExit() {
	std::cout << "Exit AtDoor State" << std::endl;
}
