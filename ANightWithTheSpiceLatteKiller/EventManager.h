#include "ISubscriber.h"
#include <list>
#include <iostream>

#pragma once
class EventManager {
public:
    void Attach(IObserver* obs);
    void Detach(IObserver* obs);
    void Notify(int value);

private:
    std::list<IObserver*> observers_;
};
