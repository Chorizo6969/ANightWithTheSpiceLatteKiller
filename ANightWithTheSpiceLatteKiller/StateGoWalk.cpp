#include "StateGoWalk.h"

StateGoWalk::StateGoWalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
}


void StateGoWalk::OnEnter() {
	std::cout << "Enter Walk State" << std::endl;
}

void StateGoWalk::Do() {
	//Each player step, tp
	//TP again if inPlayerRoom OR inNextRoomToPlayer

	std::cout << "Killer is walking in the shop" << std::endl;

}

void StateGoWalk::OnExit() {
	std::cout << "Exit Walk State" << std::endl;
}