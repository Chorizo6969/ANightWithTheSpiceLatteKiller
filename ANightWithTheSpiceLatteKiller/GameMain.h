#pragma once
#include "KillerMain.h"
#include "MapManager.h"
#include "ConsolePrinter.h"
#include "PlayerMain.h"

class GameMain
{
public:
	PlayerMain* PlayerMainRef;
	KillerMain* KillerMainRef;
	MapManager* MapManagerRef;
	ConsolePrinter* ConsolePrinterRef;

	GameMain();
	~GameMain();
};

