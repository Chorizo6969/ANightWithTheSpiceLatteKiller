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
#define T 116

PlayerMain::PlayerMain(MapManager* mapRef) 
{
	PlayerMovementRef = new PlayerMouvement(mapRef);
	PlayerInteractionRef = new PlayerInteraction;
}

PlayerMain::~PlayerMain() {
	delete PlayerMovementRef;
	delete PlayerInteractionRef;
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
			//system("cls");
			mapManager->PrintMap();
			break;

		case KEY_DOWN:
			playerMain->PlayerMovementRef->Move(0, 1);
			//system("cls");
			mapManager->PrintMap();
			
			break;

		case KEY_LEFT:
			playerMain->PlayerMovementRef->Move(-1, 0);
			//system("cls");
			mapManager->PrintMap();
			/*system("cls");*/
			break;

		case KEY_RIGHT:
			playerMain->PlayerMovementRef->Move(1, 0);
			//system("cls");
			mapManager->PrintMap();
			break;

		case T:
			//for (pair<float, float> pos : mapManager->CharPosMapByRoom[mapManager->PlayerCurrentRoom]) {
			//	mapManager->Map[pos.second][pos.first] = 'X';
			//}
			break;
		}
	}
}

void TestInput() {
	char ch;
	printf("Press 'q' to exit prom program\n");
	do {
		ch = _getch();
		printf("%c (%d)\n", ch, ch);
	} while (ch != 'q');
}

int main()
{
	KillerMain* killerMain = new KillerMain;
	killerMain->TestStepSystem();

	Sleep(1000);

	MainElouann();

	//SON
	SoundManager* sound = new SoundManager;
	sound->PlayMusic("Ambiance.mp3", true);
	//sound->PlaySFX("Freddy.mp3");

	std::cout << "Joue le son, appuyez sur Entrée pour quitter...\n";
	std::cin.get();
}


