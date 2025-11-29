#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"
#include "KillerMain.h"
#include "SoundManager.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	MapManager* mapManager;
	SoundManager* SoundManagerRef;

	PlayerMain(MapManager* map, KillerMain* killer, SoundManager* sound);
	~PlayerMain();
	int c;
	//int main();

	// A SUPPR
	void MainElouann();
};