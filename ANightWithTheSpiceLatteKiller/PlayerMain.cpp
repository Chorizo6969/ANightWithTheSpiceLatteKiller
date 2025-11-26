#include <iostream>
#include "ConsolePrinter.h"
#include "PlayerMain.h"
#include "MapManager.h"
#include "ConsoleColorEnum.h"
#include "KillerMain.h"

#include <conio.h>
//#pragma comment(lib, "winmm.lib")

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void MainElouann() {
	int i;
	i = -1;

	ConsolePrinter* consolePrinter = new ConsolePrinter;
	PlayerMain* playerMain = new PlayerMain;
	MapManager* mapManager = new MapManager(playerMain, consolePrinter);

	while (!(cin >> i) || i != 1) {
		cout << "Press Alt+Enter before playing, then enter 1";
	}

	int c;

	mapManager->PrintMap();

	while (1)
	{
		c = 0;

		// get player input as int
		switch ((c = _getch())) {
		case KEY_UP:
			mapManager->PrintMap();
			break;

		case KEY_DOWN:
			mapManager->PrintMap();
			break;

		case KEY_LEFT:
			mapManager->PrintMap();
			break;

		case KEY_RIGHT:
			mapManager->PrintMap();
			break;
		}
	}
}

int main()
{
	KillerMain* killerMain = new KillerMain;
	//killerMain->ClientCode();
	MainElouann();
}

