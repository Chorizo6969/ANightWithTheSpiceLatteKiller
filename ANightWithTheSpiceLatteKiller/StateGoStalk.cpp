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

	// If killer same room as player, tp again
	if (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom) {
		// Try until it's valide
		do {
			killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom);
		} while (killerMainRef->MapManagerRef->KillerCurrentRoom == killerMainRef->MapManagerRef->PlayerCurrentRoom);
	}

	// Update last room
	killerMainRef->MapManagerRef->KillerLastRoom = killerMainRef->MapManagerRef->KillerCurrentRoom;

	std::cout << "Killer is stalking player" << std::endl;
}

void StateGoStalk::OnExit() {
	std::cout << "Exit Stalk State" << std::endl;
}