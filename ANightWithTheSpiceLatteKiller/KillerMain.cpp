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

	PlayerTrueRoom = MapManagerRef->PlayerCurrentRoom;

	AvoidableCharList = MapManagerRef->DoorsSymbols;
	AvoidableCharList.push_back('@');
	AvoidableCharList.push_back('§');
}

KillerMain::~KillerMain() {
	delete MapManagerRef;
	delete KillerMovementRef;
	delete KillerBrainRef;
	delete KillerSoundHandlerRef;
	delete EventManagerRef;
	delete StepCounterRef;
}

void KillerMain::UpdatePlayerRoom() {
	if (std::find(AvoidableCharList.begin(), AvoidableCharList.end(), MapManagerRef->PlayerCurrentRoom) != AvoidableCharList.end()) {
		return;
	}
	PlayerTrueRoom = MapManagerRef->PlayerCurrentRoom;
}


void KillerMain::KillerDo() {
	UpdatePlayerRoom();
	if(KillerBrainRef->stateCurrent != NULL)KillerBrainRef->stateCurrent->Do();
	//std::cout << "LA ROOM DU JOUEUR : " + MapManagerRef->PlayerCurrentRoom << std::endl;
	//std::cout << "LA ROOM DU KILLER : " + MapManagerRef->KillerCurrentRoom << std::endl;
}

void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
	KillerDo();
}

void KillerMain::Update(int value)
{
	
	PlayerStepMemory++;
    if (PlayerStepMemory >= 30 && KillerBrainRef->stateCurrent != KillerBrainRef->stateKillerAtDoor) //Avoid killer to switch state when AtTheDoor
	{
		KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
		PlayerStepMemory = 0;
	}
	KillerDo();

	/*std::cout << "Le joueur est a " << value << " pas" << std::endl;*/
}

void KillerMain::GameOver() {
	//Killer Visible now
	//std::cout << "GAMEOVER" << std::endl;
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