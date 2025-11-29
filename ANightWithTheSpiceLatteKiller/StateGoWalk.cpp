#include "StateGoWalk.h"
#include "KillerMain.h"

StateGoWalk::StateGoWalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}


void StateGoWalk::OnEnter() {
	std::cout << "Enter Walk State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = GREEN;
}

void StateGoWalk::Do() {
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

	std::cout << "Killer is walking in the shop" << std::endl;

}

void StateGoWalk::OnExit() {
	std::cout << "Exit Walk State" << std::endl;
}