#pragma once

#include <iostream>

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
	int _moveFrequence; //How many steps of the player until killer move, the lower, the faster

};

