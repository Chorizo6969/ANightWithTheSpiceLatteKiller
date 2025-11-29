#include "KillerMain.h"


KillerMain::KillerMain(MapManager* mapRef)
{
	PlayerStepMemory = 0;
	MapManagerRef = mapRef;
	KillerBrainRef = new KillerStateBrain(this);
	KillerSoundHandlerRef = new KillerSoundHandler;
	KillerMovementRef = new KillerMovement(this);
	EventManagerRef = new EventManager();
	StepCounterRef = new StepCounter(*EventManagerRef);
}

KillerMain::~KillerMain() {
	delete MapManagerRef;
	delete KillerMovementRef;
	delete KillerBrainRef;
	delete KillerSoundHandlerRef;
	delete EventManagerRef;
	delete StepCounterRef;
}

void KillerMain::KillerDo() {
	if(KillerBrainRef->stateCurrent != NULL)KillerBrainRef->stateCurrent->Do();
	
}

void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
	KillerDo();
}

void KillerMain::Update(int value)
{
	std::cout << "Le joueur est a " << value << " pas" << std::endl;
	PlayerStepMemory++;
    if (PlayerStepMemory == 30) {
		KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
		PlayerStepMemory = 0;
	}
	KillerDo();
}

void KillerMain::GameOver() {
	//Killer Visible now
	std::cout << "GAMEOVER" << std::endl;
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