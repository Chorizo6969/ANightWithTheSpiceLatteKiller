#include "KillerStateBrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std::literals;

	KillerStateBrain::KillerStateBrain(KillerMain* main) : killerMainRef(main) {
		stateGoWalk = new StateGoWalk(killerMainRef);
		stateGoStalk = new StateGoStalk(killerMainRef);
		stateGoKill = new StateGoKill(killerMainRef);

		stateCurrent = NULL;

		StateList = { stateGoWalk, stateGoStalk, stateGoKill };
	}

KillerStateBrain::~KillerStateBrain() {
	delete stateGoWalk;
	delete stateGoStalk;
	delete stateGoKill;
}

StateBase* KillerStateBrain::GetRandomState() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, StateList.size() - 1);

	int randomIndex = dis(gen);
	if (StateList[randomIndex] == stateCurrent) GetRandomState();
	else return StateList[randomIndex];
}

void KillerStateBrain::SwitchState(StateBase* StateToSwitch){
	if (stateCurrent != NULL)stateCurrent->OnExit();
	stateCurrent = StateToSwitch;
	if (stateCurrent != NULL)stateCurrent->OnEnter();
}

