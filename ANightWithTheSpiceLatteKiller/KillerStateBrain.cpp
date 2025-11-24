#include "KillerStateBrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


StateBase* KillerStateBrain::RandomState(){
	int random = std::srand(std::time(0));
}


void KillerStateBrain::SwitchState(StateBase StateToSwitch){
	StateCurrent = StateToSwitch;
}
