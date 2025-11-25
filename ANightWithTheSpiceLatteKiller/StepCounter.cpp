#include "StepCounter.h"

void StepCounter::IncreaseStep() //On augmente les pas de 1
{
	StepCounter::PlayerStep++;
	//Publisher
}

/// <summary>
/// Déstructeur
/// </summary>
StepCounter::~StepCounter() 
{
    std::cout << "Goodbye, I was the StepCounter (Observer) \"" << this->number_ << "\".\n";
}

/// <summary>
/// Mets à jour le message puis l'affiche
/// </summary>
/// <param name="message_from_subject"></param>
void StepCounter::Update(const std::string& message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void StepCounter::RemoveMeFromTheList()
{
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void StepCounter::PrintInfo() 
{
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}
