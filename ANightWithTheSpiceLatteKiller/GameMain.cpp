#include "GameMain.h"

GameMain::GameMain() {
	ConsolePrinterRef = new ConsolePrinter;
	MapManagerRef = new MapManager(ConsolePrinterRef);
	KillerMainRef = new KillerMain(MapManagerRef);
	PlayerMainRef = new PlayerMain(MapManagerRef, KillerMainRef);

}


GameMain::~GameMain() {

}

int main() {
	GameMain main;

	//main.KillerMainRef->TestStepSystem();

	while (1) {
		main.PlayerMainRef->MainElouann();
		/*main.KillerMainRef->KillerMovementRef->MoveKiller();*/
	}

}


