#include "Interactable.h"
#include "PlayerMain.h"

#pragma once
class PlayerInteraction{
public:
	Interactable CurrentObjectInteract;
	PlayerMain PlayerMainRef;

	void Interact();
};

