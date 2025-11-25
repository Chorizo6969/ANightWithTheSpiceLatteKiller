#include "DialogueDataBase.h"
#include "IObserver.h"
#include "EventManager.h"

#pragma once
class StepCounter : public IObserver {
public:
	int PlayerStep;
	DialogueDataBase DialogueManagerRef;

	StepCounter(EventManager& subject) : subject_(subject)
	{
		this->subject_.Attach(this);
		std::cout << "Creation of Observer" << "\n";
		this->number_ = StepCounter::static_number_;
	}

	virtual ~StepCounter();

	void Update(const std::string& message_from_subject) override;

	void RemoveMeFromTheList();

	void PrintInfo();

	void IncreaseStep();

	int static_number_; //Chiffre pour debug quel observer est relou
	std::string message_from_subject_;
	EventManager& subject_;
	int number_;
};