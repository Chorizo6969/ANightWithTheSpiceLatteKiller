#pragma once

#include "StateBase.h"

class StateGoStalk : public StateBase
{
public:

	StateGoStalk(KillerMain* killerMainRef);

	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};