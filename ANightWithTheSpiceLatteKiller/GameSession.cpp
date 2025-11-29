#include "GameSession.h"

GameSession::GameSession(DialoguePrinter* dialogue) {
	DialoguePrinterRef = dialogue;
}

GameSession::~GameSession() {
}


void GameSession::SessionStart() {
	DialoguePrinterRef->WriteDialogue("utility", "game_start");
	CanPlay = true;
}


void GameSession::SessionEnd() {
	DialoguePrinterRef->WriteDialogue("utility", "game_end");
	CanPlay = false;
}
