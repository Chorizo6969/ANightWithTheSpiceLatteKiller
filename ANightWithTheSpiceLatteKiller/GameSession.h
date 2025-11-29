#pragma once
#include "DialoguePrinter.h"
class GameSession
{
public:
	bool CanPlay = true;
	DialoguePrinter* DialoguePrinterRef;

	GameSession(DialoguePrinter* dialogue);
	~GameSession();

	//Call when game is started
	void SessionStart();

	//Call when game is ended
	void SessionEnd();
};

