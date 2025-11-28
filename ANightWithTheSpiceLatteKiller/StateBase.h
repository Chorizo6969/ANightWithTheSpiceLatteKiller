#include <iostream>
#pragma once

class KillerMain;

class StateBase 
{
public:
	StateBase(KillerMain* killerMainRef);
	virtual ~StateBase() = default;

	virtual void OnEnter();
	virtual void Do();
	virtual void OnExit();

protected:
	KillerMain* killerMainRef;

};

