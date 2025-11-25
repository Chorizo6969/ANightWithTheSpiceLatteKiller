#include "KillerStateBrain.h"
#include "KillerSoundHandler.h"
#include "MapManager.h"

#pragma once
class KillerMain
{
public:
	KillerSoundHandler* KillerSoundHandlerRef;
	KillerStateBrain* KillerBrainRef;
	MapManager* MapManagerRef;
	KillerMain();
	~KillerMain();
	void KillerDo();
	void DebugStateMachine();
	void ClientCode();
};