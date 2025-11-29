#include "StateBase.h"

StateBase::StateBase(KillerMain* killerMainRef)
    : killerMainRef(killerMainRef)
{
    _moveFrequence = 5;
}

void StateBase::OnEnter() {
}

void StateBase::Do() {
}

void StateBase::OnExit() {
}

