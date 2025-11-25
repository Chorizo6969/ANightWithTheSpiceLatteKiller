#include "StateBase.h"

#pragma once
class StateGoWalk : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};