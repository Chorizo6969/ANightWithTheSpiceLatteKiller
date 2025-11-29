#pragma once

#include "KillerStateBrain.h"
#include "KillerMovement.h"
#include "KillerSoundHandler.h"
#include "IObserver.h"
#include "StepCounter.h"
#include "EventManager.h"
#include "MapManager.h"


class KillerMain : public IObserver
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	KillerMovement* KillerMovementRef;
	StepCounter* StepCounterRef; 
	EventManager* EventManagerRef;
	MapManager* MapManagerRef;
	KillerMain(MapManager* mapRef);
	~KillerMain();

	void KillerDo();
	void DebugStateMachine();

	void Update(int value) override;
	void TestStepSystem();

	void GameOver();
private:
	int PlayerStepMemory;
};