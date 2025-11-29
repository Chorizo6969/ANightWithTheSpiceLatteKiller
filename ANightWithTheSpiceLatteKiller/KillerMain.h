#pragma once

#include "KillerStateBrain.h"
#include "KillerMovement.h"
#include "KillerSoundHandler.h"
#include "IObserver.h"
#include "StepCounter.h"
#include "EventManager.h"
#include "MapManager.h"
#include "DialoguePrinter.h"

class KillerMain : public IObserver
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	KillerMovement* KillerMovementRef;
	StepCounter* StepCounterRef; 
	EventManager* EventManagerRef;
	MapManager* MapManagerRef;
	DialoguePrinter* DialoguePrinterRef;
	KillerMain(MapManager* mapRef, DialoguePrinter* diaRef);
	~KillerMain();

	void KillerDo();
	void Update(int value) override;

	char PlayerTrueRoom;
    int PlayerStepMemory;

	// Call, if player go in the room where killer is or if killer end trying to be in player room
	void GameOver(); 


	void DebugStateMachine();
	void TestStepSystem();

private:
	vector<char> AvoidableCharList;
	void UpdatePlayerRoom();
};