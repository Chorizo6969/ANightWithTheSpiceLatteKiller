#include "KillerStateBrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std::literals;

StateBase* KillerStateBrain::GetRandomState(){
	srand(time(0));
	int randomIndex = rand() % 3;
	StateBase* newState = StateList[randomIndex];
	return newState;
}


void KillerStateBrain::SwitchState(StateBase* StateToSwitch){
	StateCurrent->OnExit();
	StateCurrent = StateToSwitch;
	StateCurrent->OnEnter();
}

