#include "StateBase.h"

#pragma once
class StateKiller : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};

