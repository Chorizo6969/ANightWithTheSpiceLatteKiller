#include "EventManager.h"

void EventManager::Attach(IObserver* observer)
{
    observers_.push_back(observer);
}

void EventManager::Detach(IObserver* observer)
{
    observers_.remove(observer);
}

void EventManager::Notify(int value)
{
    for (IObserver* obs : observers_)
        obs->Update(value);
}
