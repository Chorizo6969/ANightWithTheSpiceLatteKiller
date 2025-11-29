#include "StateGoKill.h"
#include "KillerMain.h" 

StateGoKill::StateGoKill(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}

void StateGoKill::OnEnter() {
	std::cout << "Enter Kill State" << std::endl;
	killerMainRef->MapManagerRef->KillerColor = RED;
}

void StateGoKill::Do() {
	killerMainRef->KillerMovementRef->MoveKiller(killerMainRef->MapManagerRef->KillerCurrentRoom);
	//IF ma room = playerRoom, je lance le compteur avant mort du joueur
	std::cout << "Killer is trying to kill player" << std::endl;
}

void StateGoKill::OnExit() {
	std::cout << "Exit Kill State" << std::endl;
}

void StateGoKill::TryEnterPlayerRoom() {
	IsTryingToEnterPlayerRoom = true;
	//Play Line
	EnterTries++;
	if (EnterTries == 10) {
		EnterTries = 0;
		killerMainRef->GameOver();
	};
}