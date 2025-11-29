#pragma once

#include "PlayerInteraction.h"
#include "PlayerMouvement.h"
#include "KillerMain.h"
#include "SoundManager.h"
#include "DialoguePrinter.h"
#include "GameSession.h"


class PlayerMain {

public:
	PlayerMouvement* PlayerMovementRef;
	PlayerInteraction* PlayerInteractionRef;
	MapManager* mapManager;
	SoundManager* SoundManagerRef;
	DialoguePrinter* DialoguePrinterRef;
	GameSession* GameSessionRef;
	KillerMain* KillerMainRef;

	

	PlayerMain(MapManager* map, KillerMain* killer, SoundManager* sound, DialoguePrinter* dialogue, GameSession* session);
	~PlayerMain();
	int c;
	//int main();

	// A SUPPR
	void MainElouann();

	void AddIngredient();

	void GameWin();
	int maxIngredient = 15;
	int CurrentIngredient = 0;


private:
	void CheckTotalIngredient();
};