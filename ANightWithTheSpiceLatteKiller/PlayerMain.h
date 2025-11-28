#include "PlayerInteraction.h"
#include "PlayerMouvement.h"

#pragma once
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