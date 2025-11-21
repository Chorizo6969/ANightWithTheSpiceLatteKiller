#pragma once
class StateBase 
{
public:
	virtual void OnEnter();
	virtual void Do();
	virtual void OnExit();
};

