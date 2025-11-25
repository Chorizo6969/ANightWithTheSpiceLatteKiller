#include "StateGoStalk.h"

void StateGoStalk::OnEnter() {
	std::cout << "Enter Stalk State" << std::endl;
}

void StateGoStalk::Do() {
	//Each player step, tp
	//TP again if inPlayerRoom

	std::cout << "Killer is stalking player" << std::endl;
}

void StateGoStalk::OnExit() {
	std::cout << "Exit Stalk State" << std::endl;
}