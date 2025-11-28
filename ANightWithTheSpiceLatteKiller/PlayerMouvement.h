#pragma once

#include "MapManager.h"


class PlayerMouvement
{
public:
	PlayerMouvement(MapManager* map);
	//Interactable currentObjectInteract;
	//StepCounter* StepCounterRef;
	MapManager* MapRef;

	void Move(int addOnX, int addOnY);
};

