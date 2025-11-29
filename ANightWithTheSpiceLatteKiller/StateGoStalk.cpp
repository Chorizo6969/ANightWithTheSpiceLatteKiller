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
	killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom);
	//Each player step, tp
	if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerLastRoom);
	}
	else {
		killerMainRef->MapManagerRef->KillerLastRoom = killerMainRef->MapManagerRef->KillerCurrentRoom;
	}

	std::cout << "Killer is stalking player" << std::endl;
}

void StateGoStalk::OnExit() {
	std::cout << "Exit Stalk State" << std::endl;
}