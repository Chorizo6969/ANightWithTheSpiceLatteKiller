#include "StateGoKill.h"





void StateGoKill::OnEnter() {
	std::cout << "Enter Kill State" << std::endl;
}

void StateGoKill::Do() {
	//Each player step, tp
	std::cout << "Killer is trying to kill player" << std::endl;
}

void StateGoKill::OnExit() {
	std::cout << "Exit Kill State" << std::endl;
}