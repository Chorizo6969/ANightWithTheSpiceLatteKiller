#include "KillerStateBrain.h"
#include "KillerSoundHandler.h"
#include "MapManager.h"
#include "IObserver.h"
#include "StepCounter.h";
#include "EventManager.h";

#pragma once
class KillerMain : public IObserver
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	MapManager* MapManagerRef = nullptr;
	StepCounter* StepCounterRef; 
	EventManager* EventManagerRef;

	KillerMain();
	~KillerMain();

	void KillerDo();
	void DebugStateMachine();

	void Update(int value) override;
	void TestStepSystem();
	void GameOver();
};