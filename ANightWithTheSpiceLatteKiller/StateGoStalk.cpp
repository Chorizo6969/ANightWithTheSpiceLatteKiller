#include "StateGoStalk.h"
#include "KillerMain.h"

StateGoStalk::StateGoStalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}

void StateGoStalk::OnEnter() {
	std::cout << "Enter Stalk State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = BLUE;
}

void StateGoStalk::Do() {
	killerMainRef->KillerMovementRef->MoveKiller();
	//Each player step, tp
	//if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom) {
	//	killerMainRef->KillerMovementRef->MoveKiller();
	//}
	//else {

	//}

	std::cout << "Killer is stalking player" << std::endl;
}

void StateGoStalk::OnExit() {
	std::cout << "Exit Stalk State" << std::endl;
}