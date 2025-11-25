#include "StepCounter.h"
#include "PlayerMain.h"

#pragma once
class PlayerMouvement
{
public:
	Interactable currentObjectInteract;
	StepCounter StepCounterRef;

	void Walk();
};

