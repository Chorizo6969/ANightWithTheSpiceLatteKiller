#include "StateBase.h"

#pragma once
class StateStalker : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};

