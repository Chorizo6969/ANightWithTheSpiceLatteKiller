#pragma once
#include "Interactable.h"

class Door : public Interactable{
public:
	bool IsActive;
	void InteractionStart() override;
};

