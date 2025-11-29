#include "StateGoWalk.h"
#include "KillerMain.h"

StateGoWalk::StateGoWalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}


void StateGoWalk::OnEnter() {
	//std::cout << "Enter Walk State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = GREEN;
}

void StateGoWalk::Do() {
	killerMainRef->KillerMovementRef->MoveKillerSafe(true); // Avoid player room and adjacent
	//std::cout << "Killer is walking in the shop" << std::endl;
}

void StateGoWalk::OnExit() {
	//std::cout << "Exit Walk State" << std::endl;
}