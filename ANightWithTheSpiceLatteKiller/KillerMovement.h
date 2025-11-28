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
private:
	char GetRandomAdjacent(char key);
	pair<float, float> GetRandomPosInRoom(char key);

};

