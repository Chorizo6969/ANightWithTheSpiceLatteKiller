#define MINIAUDIO_IMPLEMENTATION
#include <iostream>
#include "ConsolePrinter.h"
#include "PlayerMain.h"
#include "MapManager.h"
#include "ConsoleColorEnum.h"
#include "KillerMain.h"
#include "SoundManager.h"

#include <conio.h>
//#pragma comment(lib, "winmm.lib")

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

PlayerMain::PlayerMain(MapManager* mapRef) 
{
	PlayerMovementRef = new PlayerMouvement(mapRef);
	PlayerInteractionRef = new PlayerInteraction;
}

void MainElouann() {
	int i;
	i = -1;

	ConsolePrinter* consolePrinter = new ConsolePrinter;
	MapManager* mapManager = new MapManager(consolePrinter);
	PlayerMain* playerMain = new PlayerMain(mapManager);

	/*while (!(cin >> i) || i != 1) {
		cout << "Press Alt+Enter before playing, then enter 1";
	}*/

	int c;

	mapManager->PrintMap();

	while (1)
	{
		c = 0;

		// get player input as int
		switch ((c = _getch())) {
		case KEY_UP:
			playerMain->PlayerMovementRef->Move(0, -1);
			mapManager->PrintMap();
			break;

		case KEY_DOWN:
			playerMain->PlayerMovementRef->Move(0, 1);
			mapManager->PrintMap();
			break;

		case KEY_LEFT:
			playerMain->PlayerMovementRef->Move(-1, 0);
			mapManager->PrintMap();
			break;

		case KEY_RIGHT:
			playerMain->PlayerMovementRef->Move(1, 0);
			mapManager->PrintMap();
			break;
		}
	}
}

int main()
{
	SoundManager* sound = new SoundManager;
	sound->PlayMusic("George.mp3", true);
	sound->PlaySFX("Freddy.mp3");


	//ma_engine engine;

	//killerMain->ClientCode();
	//MainElouann();

	//KillerMain* killerMain = new KillerMain;
	//killerMain->ClientCode();
	//MainMateo();
	//MainElouann();
}


