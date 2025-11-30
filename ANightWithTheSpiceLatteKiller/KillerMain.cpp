#include "KillerMain.h"

#pragma region Constructor&Destructor
KillerMain::KillerMain(MapManager* mapRef, DialoguePrinter* diaRef, GameSession* gameSession, SoundManager* sound)
{
	PlayerStepMemory = 0;
	MapManagerRef = mapRef;
	KillerBrainRef = new KillerStateBrain(this);
	KillerSoundHandlerRef = new KillerSoundHandler;
	KillerMovementRef = new KillerMovement(this);
	EventManagerRef = new EventManager();
	StepCounterRef = new StepCounter(*EventManagerRef);
	DialoguePrinterRef = diaRef;
	GameSessionRef = gameSession;
	soundRef_ = sound;

	PlayerTrueRoom = MapManagerRef->PlayerCurrentRoom;

	AvoidableCharList = MapManagerRef->DoorsSymbols;
	AvoidableCharList.push_back('@');
	AvoidableCharList.push_back('§');

	//MapManagerRef->ShowKiller = true;

}
KillerMain::~KillerMain() {
	delete KillerMovementRef;
	delete KillerBrainRef;
	delete KillerSoundHandlerRef;
	delete EventManagerRef;
	delete StepCounterRef;
}

#pragma endregion

//Real update to check the room of the player each time he move (avoid the special character (doors, ingredients, killer)
void KillerMain::UpdatePlayerRoom() {
	if (std::find(AvoidableCharList.begin(), AvoidableCharList.end(), MapManagerRef->PlayerCurrentRoom) != AvoidableCharList.end()) {
		return;
	}
	PlayerTrueRoom = MapManagerRef->PlayerCurrentRoom;
}
//Update the player true room & currentState.Do()
void KillerMain::KillerDo() {
	UpdatePlayerRoom();
	if(KillerBrainRef->stateCurrent != NULL)KillerBrainRef->stateCurrent->Do();
}


//Called each time the player move, Observer
void KillerMain::Update(int value)
{
	PlayerStepMemory++;
    if (PlayerStepMemory >= 30 && KillerBrainRef->stateCurrent != KillerBrainRef->stateKillerAtDoor) //Avoid killer to switch state when AtTheDoor
	{
		KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
		PlayerStepMemory = 0;
	}
	KillerDo();
}

void KillerMain::GameOver() {
	MapManagerRef->ShowKiller = true;
	soundRef_->PlaySFX("Kill.mp3");
	DialoguePrinterRef->WriteDialogue("killer", "game_over");
	MapManagerRef->PrintMap();
	GameSessionRef->SessionEnd();
}

#pragma region DEBUG

void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->GetRandomPatrolState());
	KillerDo();
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
#pragma endregion