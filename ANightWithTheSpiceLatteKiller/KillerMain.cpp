#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	//MapManagerRef = new MapManager;
	KillerSoundHandlerRef = new KillerSoundHandler;
}

KillerMain::~KillerMain() {
	delete KillerBrainRef;
	delete MapManagerRef;
	delete KillerSoundHandlerRef;
}

void KillerMain::KillerDo() {
	KillerBrainRef->stateCurrent->Do();
}


void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->stateGoKill);
	KillerDo();
}

void KillerMain::Update(int value)
{
	std::cout << "Le joueur est a " << value << " pas" << std::endl;
}

void KillerMain::TestStepSystem()
{
	EventManager subject;

	subject.Attach(this);

	StepCounter stepCounter(subject);

	stepCounter.IncreaseStep();
	stepCounter.IncreaseStep();
	stepCounter.IncreaseStep();
}