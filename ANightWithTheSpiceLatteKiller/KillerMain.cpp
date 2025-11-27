#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	//MapManagerRef = new MapManager;
	KillerSoundHandlerRef = new KillerSoundHandler;
	EventManagerRef = new EventManager();
	StepCounterRef = new StepCounter(*EventManagerRef);
}

KillerMain::~KillerMain() {
	delete KillerBrainRef;
	delete MapManagerRef;
	delete KillerSoundHandlerRef;
	delete EventManagerRef;
	delete StepCounterRef;
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
	{
		if (value == 20)
			StepCounterRef->playerStep_ = 0;

	}
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