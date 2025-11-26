#include "KillerStateBrain.h"
#include "KillerSoundHandler.h"
#include "MapManager.h"
#include "IObserver.h"

#pragma once
class KillerMain : public IObserver
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	MapManager* MapManagerRef = nullptr;

	KillerMain();
	~KillerMain();

	void KillerDo();
	void DebugStateMachine();

	void Update(int value) override;
	void TestStepSystem();
};