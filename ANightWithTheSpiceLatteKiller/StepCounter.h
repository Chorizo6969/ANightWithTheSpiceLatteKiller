#include "DialogueDataBase.h"
#include "IObserver.h"
#include "EventManager.h"

#pragma once
class StepCounter {
public:
    StepCounter(EventManager& subject) : subject_(subject){}

    void IncreaseStep();
    int playerStep_ = 0;

private:
    EventManager& subject_;
};