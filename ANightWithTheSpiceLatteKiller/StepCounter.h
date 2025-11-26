#include "DialogueDataBase.h"
#include "IObserver.h"
#include "EventManager.h"

#pragma once
class StepCounter : public IObserver {
public:
	int PlayerStep;
	DialogueDataBase DialogueManagerRef;

	StepCounter(EventManager& subject, int index) : subject_(subject)
	{
		this->subject_.Attach(this);
		std::cout << "Creation of Observer" << "\n";
		this->number_ = index;
	}

	virtual ~StepCounter();

	void Update(const std::string& message_from_subject) override;

	void RemoveMeFromTheList();

	void PrintInfo();

	void IncreaseStep();

private:
	std::string message_from_subject_;
	EventManager& subject_;
	int number_;
};