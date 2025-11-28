#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"
#include "KillerMain.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	MapManager* mapManager;

	PlayerMain(MapManager* map, KillerMain* killer);
	~PlayerMain();
	int c;
	//int main();

	// A SUPPR
	void MainElouann();
};