#pragma once
#include "StateBase.h"


class StateGoWalk : public StateBase
{
public:
	StateGoWalk(KillerMain* killerMainRef);

	void OnEnter() override;
	void Do() override;
	void OnExit() override;
};