#include "StateBase.h"

#pragma once
class StateGoKill : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};

