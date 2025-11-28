#pragma once

#include "ISubscriber.h"
#include <list>
#include <iostream>

class EventManager {
public:
    void Attach(IObserver* obs);
    void Detach(IObserver* obs);
    void Notify(int value);

private:
    std::list<IObserver*> observers_;
};
