#include "EventManager.h"

/// <summary>
/// Déstructeur de l'observeur
/// </summary>
EventManager::~EventManager()
{
    std::cout << "Goodbye, I was the Subject.\n";
}

/// <summary>
/// Abonnement de l'observer
/// </summary>
/// <param name="observer">Pointeur vers l'observeur</param>
void EventManager::Attach(IObserver* observer)
{
    list_observer_.push_back(observer);
}

/// <summary>
/// Désabonnement de l'observer
/// </summary>
/// <param name="observer">Pointeur vers l'observeur</param>
void EventManager::Detach(IObserver* observer) 
{
    list_observer_.remove(observer);
}

/// <summary>
/// Avertit tout les listeners que une info à changé !
/// </summary>
void EventManager::Notify()
{
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

/// <summary>
/// 
/// </summary>
/// <param name="message"></param>
void EventManager::CreateMessage(std::string message = "Empty") 
{
    this->message_ = message;
    Notify();
}

/// <summary>
/// Affiche dans la console le nombre d'abonnée
/// </summary>
void EventManager::HowManyObserver() 
{
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

void EventManager::ChangeMessage()
{
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
}