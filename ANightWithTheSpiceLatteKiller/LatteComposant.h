#pragma once
#include "Interactable.h"

class LatteComposant : public Interactable {
public:
	bool IsActive;
	void InteractionStart() override;
};

