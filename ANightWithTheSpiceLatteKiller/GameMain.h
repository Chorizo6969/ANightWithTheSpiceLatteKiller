#pragma once
#include "KillerMain.h"
#include "MapManager.h"
#include "ConsolePrinter.h"
#include "PlayerMain.h"
#include "SoundManager.h"
#include "DialoguePrinter.h"

class GameMain
{
public:
	PlayerMain* PlayerMainRef;
	KillerMain* KillerMainRef;
	MapManager* MapManagerRef;
	ConsolePrinter* ConsolePrinterRef;
	SoundManager* SoundManagerRef;
	DialoguePrinter* DialoguePrinterRef;

	GameMain();
	~GameMain();
};

