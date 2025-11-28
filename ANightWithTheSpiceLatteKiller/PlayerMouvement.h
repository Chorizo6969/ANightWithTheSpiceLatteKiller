#pragma once

#include "MapManager.h"
#include "StepCounter.h"
#include "KillerMain.h"

class PlayerMouvement
{
public:
	PlayerMouvement(MapManager* map, KillerMain* killer);
	//Interactable currentObjectInteract;
	StepCounter* StepCounterRef;
	MapManager* MapRef;

	void Move(int addOnX, int addOnY);
};

