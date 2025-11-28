#include "GameMain.h"

GameMain::GameMain() {
	ConsolePrinterRef = new ConsolePrinter;
	MapManagerRef = new MapManager(ConsolePrinterRef);
	PlayerMainRef = new PlayerMain(MapManagerRef);
	KillerMainRef = new KillerMain(MapManagerRef);

}


GameMain::~GameMain() {

}

int main() {
	GameMain main;

	while (1) {
		main.PlayerMainRef->MainElouann();
		/*main.KillerMainRef->KillerMovementRef->MoveKiller();*/
	}

}


