#include "KillerMain.h"

void KillerMain::KillerDo() {
	KillerBrainRef->stateCurrent->Do();
}


void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->GetRandomState());
	KillerDo();

}

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	MapManagerRef = new MapManager;
	KillerSoundHandlerRef = new KillerSoundHandler;
}
