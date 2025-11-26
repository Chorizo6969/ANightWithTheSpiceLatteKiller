#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

KillerMain::KillerMain()
{
	KillerBrainRef = new KillerStateBrain;
	//MapManagerRef = new MapManager;
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
	KillerBrainRef->SwitchState(KillerBrainRef->stateGoKill);
	KillerDo();
}

void KillerMain::ClientCode() //Exemple d'un évent
{
	EventManager* subject = new EventManager;
	StepCounter* observer1 = new StepCounter(*subject, 0);
	//StepCounter* observer2 = new StepCounter(*subject);

	subject->CreateMessage(to_string(observer1->PlayerStep)); //Print et change le message

	subject->CreateMessage("The weather is hot today! :p");

	//observer2->RemoveMeFromTheList();

	observer1->RemoveMeFromTheList();

	//delete observer2;
	delete observer1;
	delete subject;
}