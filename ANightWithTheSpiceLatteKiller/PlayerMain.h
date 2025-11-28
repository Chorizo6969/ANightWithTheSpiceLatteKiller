#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef = nullptr;
	PlayerInteraction* PlayerInteractionRef = nullptr;

	PlayerMain(MapManager* map);
	~PlayerMain();
	//int main();

	// A SUPPR
	void MainElouann();
};