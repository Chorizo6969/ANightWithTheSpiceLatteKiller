#include "Interactable.h"
#include "PlayerMain.h"

#pragma once
class PlayerInteraction{
public:
	Interactable currentObjectInteract;
	PlayerMain PlayerMainRef;

	void Interact();
};

