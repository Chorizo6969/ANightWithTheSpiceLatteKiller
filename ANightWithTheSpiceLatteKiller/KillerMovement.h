#pragma once
#include "MapManager.h"

class MapManager;

class KillerMovement
{
public:
	MapManager* MapManagerRef;

	KillerMovement(MapManager* MapManager);
	~KillerMovement();

	void MoveKiller();

	char GetRandomAdjacent(char key);

};

