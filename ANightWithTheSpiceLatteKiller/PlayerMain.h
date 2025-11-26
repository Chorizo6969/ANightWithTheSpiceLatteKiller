#include "PlayerInteraction.h"
#include "PlayerMouvement.h"

#pragma once
class PlayerMain {

public:
	PlayerMain(MapManager* map);
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	//int main();
};