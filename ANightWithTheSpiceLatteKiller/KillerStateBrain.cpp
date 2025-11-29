#include "KillerStateBrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std::literals;

#pragma region Constructor&Destructor
KillerStateBrain::KillerStateBrain(KillerMain* main) : killerMainRef(main) {
	stateGoWalk = new StateGoWalk(killerMainRef);
	stateGoStalk = new StateGoStalk(killerMainRef);
	stateGoKill = new StateGoKill(killerMainRef);
	stateKillerAtDoor = new StateKillerAtDoor(killerMainRef);

	stateCurrent = nullptr;

	PatrolStateList = { stateGoWalk, stateGoStalk, stateGoKill };
}

KillerStateBrain::~KillerStateBrain() {
	delete stateGoWalk;
	delete stateGoStalk;
	delete stateGoKill;
	delete stateKillerAtDoor;
}
#pragma endregion

StateBase* KillerStateBrain::GetRandomPatrolState() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, PatrolStateList.size() - 1);

	int randomIndex = dis(gen);
	if (PatrolStateList[randomIndex] == stateCurrent) return GetRandomPatrolState();
	else return PatrolStateList[randomIndex];
}

void KillerStateBrain::SwitchState(StateBase* StateToSwitch){
	if (stateCurrent != nullptr)stateCurrent->OnExit();
	stateCurrent = StateToSwitch;
	if (stateCurrent != nullptr)stateCurrent->OnEnter();
}

