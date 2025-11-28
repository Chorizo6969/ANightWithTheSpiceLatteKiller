#include "StateGoStalk.h"

StateGoStalk::StateGoStalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}

void StateGoStalk::OnEnter() {
	std::cout << "Enter Stalk State" << std::endl;
}

void StateGoStalk::Do() {
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