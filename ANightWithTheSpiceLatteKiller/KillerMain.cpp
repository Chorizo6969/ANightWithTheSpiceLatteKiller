#include "KillerMain.h"

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	MapManagerRef = new MapManager;
	KillerSoundHandlerRef = new KillerSoundHandler;
}

KillerMain::~KillerMain() {
	delete KillerBrainRef;
	delete MapManagerRef;
	delete KillerSoundHandlerRef;
}

void KillerMain::KillerDo() {
	KillerBrainRef->stateCurrent->Do();
}


void KillerMain::DebugStateMachine() {
	for (size_t i = 0; i < 5; i++)
	{
		KillerBrainRef->SwitchState(KillerBrainRef->GetRandomState());
		KillerDo();
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
	}
}


