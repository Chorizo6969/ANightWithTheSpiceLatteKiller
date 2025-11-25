#include "ISubscriber.h"
#include <list>
#include <iostream>

#pragma once
class EventManager : public ISubscriber {
public:

    virtual ~EventManager();

    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;

    void CreateMessage(std::string message = "Empty");


    void HowManyObserver();

    void ChangeMessage();

private:
    std::list<IObserver*> list_observer_;
    std::string message_;
};