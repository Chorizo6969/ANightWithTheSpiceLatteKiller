#pragma once
#include "DialogueManager.h"
#include "SoundManager.h"

class Interactable
{
public:
	bool IsActive;
	DialogueManager DialogueManagerRef;
	SoundManager SoundManagerRef;

	virtual void InteractionStart();
};