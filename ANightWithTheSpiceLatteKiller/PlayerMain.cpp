#define MINIAUDIO_IMPLEMENTATION
#include <iostream>
#include "ConsolePrinter.h"
#include "PlayerMain.h"
#include "MapManager.h"
#include "ConsoleColorEnum.h"
#include "KillerMain.h"
#include "miniaudio.h"

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
			system("cls");
			mapManager->PrintMap();
			cout << "TEEEEEEEEEEEEESTTTTTTTTTT";
			break;

		case KEY_DOWN:
			playerMain->PlayerMovementRef->Move(0, 1);
			system("cls");
			mapManager->PrintMap();
			
			cout << "TEEEEEEEEEEEEESTTTTTTTTTT";
			break;

		case KEY_LEFT:
			playerMain->PlayerMovementRef->Move(-1, 0);
			system("cls");
			mapManager->PrintMap();
			/*system("cls");*/
			//cout << "TEEEEEEEEEEEEESTTTTTTTTTT";
			break;

		case KEY_RIGHT:
			playerMain->PlayerMovementRef->Move(1, 0);
			system("cls");
			mapManager->PrintMap();
			cout << "TEEEEEEEEEEEEESTTTTTTTTTT";
			break;

		case T:
			cout << "test";
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

	//ma_engine engine;

	//if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
	//	std::cout << "Erreur init audio\n";
	//	return -1;
	//}

	//// Joue 3 sons en même temps
	//ma_engine_play_sound(&engine, "Audio/SFX/Freddy.mp3", NULL);
	//ma_engine_play_sound(&engine, "Audio/Musique/George.mp3", NULL);

	//std::cout << "Sons en cours... presse ENTER pour quitter.\n";
	//std::cin.get();

	//ma_engine_uninit(&engine);

	//killerMain->ClientCode();
	//MainElouann();

	//KillerMain* killerMain = new KillerMain;
	//killerMain->ClientCode();
	//MainMateo();
	
	//TestInput();
	MainElouann();
}


