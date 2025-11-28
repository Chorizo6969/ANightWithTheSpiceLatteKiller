#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	MapManager* mapManager;

	PlayerMain(MapManager* map);
	~PlayerMain();
	int c;
	//int main();

	// A SUPPR
	void MainElouann();
};