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

PlayerMain::PlayerMain(MapManager* mapRef, KillerMain* killer) 
{
	PlayerMovementRef = new PlayerMouvement(mapRef, killer);
	PlayerInteractionRef = new PlayerInteraction;
	c = 0;
	mapManager = mapRef;
	mapManager->PrintMap();
}

PlayerMain::~PlayerMain() {
	delete PlayerMovementRef;
	delete PlayerInteractionRef;
}

void PlayerMain::MainElouann() {
		c = 0;
		// get player input as int
		switch ((c = _getch())) {
		case KEY_UP:
			PlayerMovementRef->Move(0, -1);
			//system("cls");
			mapManager->PrintMap();
			break;

		case KEY_DOWN:
			PlayerMovementRef->Move(0, 1);
			//system("cls");
			mapManager->PrintMap();
			//cout << mapManager->PlayerCurrentRoom << " " << mapManager->KillerCurrentRoom << "|";

			break;

		case KEY_LEFT:
			PlayerMovementRef->Move(-1, 0);
			//system("cls");
			mapManager->PrintMap();
			/*system("cls");*/
			break;

		case KEY_RIGHT:
			PlayerMovementRef->Move(1, 0);
			//system("cls");
			mapManager->PrintMap();
			break;

		case T:
			//if (PlayerCharacter != '!')
			//	break;
			//Apppeller PlayerInteraction (Interact)
			break;
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