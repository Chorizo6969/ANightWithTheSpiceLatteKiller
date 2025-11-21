#include "StateBase.h"

#pragma once
class StateWalker : public StateBase
{
public:
	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};

