#pragma once
class StateBase abstract
{
public:
	void OnEnterState();
	void Do();
	void OnExit();
};

