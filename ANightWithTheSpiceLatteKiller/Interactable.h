#pragma once
#include "DialogueDataBase.h"
#include "SoundManager.h"

class Interactable
{
public:
	bool IsActive;
	DialogueDataBase* DialogueManagerRef;
	SoundManager* SoundManagerRef;

	virtual void InteractionStart();
};