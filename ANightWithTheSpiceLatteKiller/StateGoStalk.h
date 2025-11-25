#include "StateBase.h"

#pragma once
class StateGoStalk : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};