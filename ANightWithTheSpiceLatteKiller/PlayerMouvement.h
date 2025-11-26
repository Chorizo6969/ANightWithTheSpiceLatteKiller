#include "MapManager.h"

#pragma once
class PlayerMouvement
{
public:
	PlayerMouvement(MapManager* map);
	//Interactable currentObjectInteract;
	//StepCounter* StepCounterRef;
	MapManager* MapRef;

	void Move(int addOnX, int addOnY);
};

