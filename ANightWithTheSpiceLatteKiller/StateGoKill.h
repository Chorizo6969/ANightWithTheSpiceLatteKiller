#include "StateBase.h"

#pragma once
class StateGoKill : public StateBase
{
public:
	StateGoKill(KillerMain* killerMainRef);

	void OnEnter() override;
	void Do() override;
	void OnExit() override;

	bool IsTryingToEnterPlayerRoom = false;

private:
	int EnterTries = 0;
	void TryEnterPlayerRoom();
};

