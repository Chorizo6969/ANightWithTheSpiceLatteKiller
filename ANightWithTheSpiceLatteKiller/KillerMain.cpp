#include "KillerMain.h"

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	MapManagerRef = new MapManager;
	KillerSoundHandlerRef = new KillerSoundHandler;
}


void KillerMain::KillerDo() {
	KillerBrainRef->stateCurrent->Do();
}


void KillerMain::DebugStateMachine() {
	KillerBrainRef->SwitchState(KillerBrainRef->stateGoKill);
	KillerDo();


}


