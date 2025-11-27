#include "StepCounter.h"

void StepCounter::IncreaseStep()
{
    playerStep_++;
    subject_.Notify(playerStep_);
}
