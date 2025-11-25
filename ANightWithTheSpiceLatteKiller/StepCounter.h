#include "DialogueManager.h"

#pragma once
class StepCounter
{
public:
	int PlayerStep;
	DialogueManager DialogueManagerRef;

	void IncreaseStep();
};

