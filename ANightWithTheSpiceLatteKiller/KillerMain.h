#include "KillerStateBrain.h"
#include "KillerMovement.h"
#include "KillerSoundHandler.h"
#include "IObserver.h"
#include "StepCounter.h";
#include "EventManager.h";

#pragma once
class KillerMain : public IObserver
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	KillerMovement* KillerMovementRef;
	StepCounter* StepCounterRef; 
	EventManager* EventManagerRef;
	KillerMain(MapManager* mapRef);
	~KillerMain();

	void KillerDo();
	void DebugStateMachine();

	void Update(int value) override;
	void TestStepSystem();

	void GameOver();
};