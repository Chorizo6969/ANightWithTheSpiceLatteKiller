#pragma once
#include "MapManager.h"
#include "StepCounter.h"
#include "KillerMain.h"
#include "EventManager.h"


class PlayerMain;

class PlayerMouvement
{
private:
	EventManager subject_;       
	StepCounter stepCounter_;     

public:
	PlayerMouvement(MapManager* map, KillerMain* killer, PlayerMain* player);
	PlayerMain* PlayerMainRef;
	MapManager* MapRef;

	void Move(int addOnX, int addOnY);
};