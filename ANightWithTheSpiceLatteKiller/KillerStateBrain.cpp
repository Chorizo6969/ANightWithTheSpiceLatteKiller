#include "KillerStateBrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std::literals;

KillerStateBrain::KillerStateBrain() {
	stateGoWalk = new StateGoWalk;
	stateGoStalk = new StateGoStalk;
	stateGoKill = new StateGoKill;

	stateCurrent = stateGoWalk;
}

StateBase* KillerStateBrain::GetRandomState(){
	srand(time(0));
	int randomIndex = rand() % 3;
	StateBase* newState = StateList[randomIndex];
	return newState;
}

void KillerStateBrain::SwitchState(StateBase* StateToSwitch){
	stateCurrent->OnExit();
	stateCurrent = StateToSwitch;
	stateCurrent->OnEnter();
}



