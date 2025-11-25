#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

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

void KillerMain::ClientCode() {
	EventManager* subject = new EventManager;
	StepCounter* observer1 = new StepCounter(*subject);
	StepCounter* observer2 = new StepCounter(*subject);
	StepCounter* observer3 = new StepCounter(*subject);
	StepCounter* observer4;
	StepCounter* observer5;

	subject->CreateMessage("Hello World! :D");
	observer3->RemoveMeFromTheList();

	subject->CreateMessage("The weather is hot today! :p");
	observer4 = new StepCounter(*subject);

	observer2->RemoveMeFromTheList();
	observer5 = new StepCounter(*subject);

	subject->CreateMessage("My new car is great! ;)");
	observer5->RemoveMeFromTheList();

	observer4->RemoveMeFromTheList();
	observer1->RemoveMeFromTheList();

	delete observer5;
	delete observer4;
	delete observer3;
	delete observer2;
	delete observer1;
	delete subject;
}