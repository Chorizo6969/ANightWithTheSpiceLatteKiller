#pragma once
#include "MapManager.h"
#include "StepCounter.h"
#include "KillerMain.h"
#include "EventManager.h"

class PlayerMouvement
{
private:
	EventManager subject_;       
	StepCounter stepCounter_;     

public:
	PlayerMouvement(MapManager* map, KillerMain* killer);

	MapManager* MapRef;

	void Move(int addOnX, int addOnY);
};