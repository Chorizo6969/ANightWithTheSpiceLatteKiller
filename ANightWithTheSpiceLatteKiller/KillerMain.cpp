#include "KillerMain.h"
#include "EventManager.h"
#include "StepCounter.h"

//void KillerMain::KillerDo() {
//	KillerBrainRef->StateCurrent.Do();
//}

int StepCounter::static_number_ = 0;


void ClientCode() {
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

