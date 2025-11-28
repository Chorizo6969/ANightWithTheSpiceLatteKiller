#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

KillerMain::KillerMain(MapManager* mapRef)
{
	KillerBrainRef = new KillerStateBrain(this);
	KillerSoundHandlerRef = new KillerSoundHandler;
	KillerMovementRef = new KillerMovement(mapRef);
	EventManagerRef = new EventManager();
	StepCounterRef = new StepCounter(*EventManagerRef);
}

KillerMain::~KillerMain() {
	delete KillerMovementRef;
	delete KillerBrainRef;
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
		if (value == 20) {
			KillerBrainRef->SwitchState(KillerBrainRef->stateGoKill);
			StepCounterRef->playerStep_ = 0;
		}
		KillerDo();
	}
}

void KillerMain::GameOver() {
	//if killer in same room as player
	//Killer Visible now
	//HERE GAME OVER, KILLER KILL PLAYER
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