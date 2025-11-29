#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"
#include "KillerMain.h"
#include "SoundManager.h"
#include "DialoguePrinter.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	MapManager* mapManager;
	SoundManager* SoundManagerRef;
	DialoguePrinter* DialoguePrinterRef;
	

	PlayerMain(MapManager* map, KillerMain* killer, SoundManager* sound, DialoguePrinter* dialogue);
	~PlayerMain();
	int c;
	//int main();

	// A SUPPR
	void MainElouann();
};