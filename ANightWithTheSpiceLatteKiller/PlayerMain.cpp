#include <iostream>
#include "PlayerMain.h"
#include "MapManager.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define E 101
#define A 97
#define R 114

PlayerMain::PlayerMain(MapManager* map, KillerMain* killer, SoundManager* sound, DialoguePrinter* dialogue)
{
	PlayerMovementRef = new PlayerMouvement(map, killer);
	PlayerInteractionRef = new PlayerInteraction;
	SoundManagerRef = sound;
	c = 0;
	mapManager = map;
	DialoguePrinterRef = dialogue;
	mapManager->PrintMap();
}

PlayerMain::~PlayerMain() {
	delete PlayerMovementRef;
	delete PlayerInteractionRef;
}

void TestInput() {
	char ch;
	printf("Press 'q' to exit prom program\n");
	do {
		ch = _getch();
		printf("%c (%d)\n", ch, ch);
	} while (ch != 'q');
}

void PlayerMain::MainElouann()
{

	c = 0;

	switch ((c = _getch()))
	{
	case KEY_UP:
	{
		PlayerMovementRef->Move(0, -1);
		//system("cls");
		mapManager->PrintMap();
		break;
	}

	case KEY_DOWN:
	{
		PlayerMovementRef->Move(0, 1);
		mapManager->PrintMap();
		break;
	}

	case KEY_LEFT:
	{
		PlayerMovementRef->Move(-1, 0);
		mapManager->PrintMap();
		break;
	}

	case KEY_RIGHT:
	{
		PlayerMovementRef->Move(1, 0);
		mapManager->PrintMap();
		break;
	}

	case E: //Les portes
	{
		pair<float, float>& playerPos = mapManager->PlayerPosition;

		for (const auto& entry : mapManager->DoorsLinks)
		{
			const pair<float, float>& doorPos = entry.first;
			const pair<float, float>& linkedDoor = entry.second;

			if (doorPos.first == playerPos.second && doorPos.second == playerPos.first)
			{
				mapManager->PlayerPosition = { linkedDoor.second, linkedDoor.first };

				mapManager->PrintMap();
				break;
			}
		}
		break;
	}

	case A:
	{
		pair <float, float> pos = mapManager->PlayerPosition;
		int x = pos.first;
		int y = pos.second;

		if (count(mapManager->LatteComponentsPos.begin(), mapManager->LatteComponentsPos.end(), make_pair(x, y))) {
			mapManager->LatteComponentsPos.erase(find(mapManager->LatteComponentsPos.begin(), mapManager->LatteComponentsPos.end(), pos));
			DialoguePrinterRef->WriteDialogue("player", "ingredient_looted");
		}
			
		mapManager->PrintMap();
		break;
	}

	case R:
	{
		const pair<float, float>& playerPos = mapManager->PlayerPosition;

		for (const auto& entry : mapManager->DoorsLinks)
		{
			const pair<float, float>& doorPos = entry.first;

			if (doorPos.first == playerPos.second && doorPos.second == playerPos.first)
			{
				SoundManagerRef->PlaySFX("Door.mp3");
				if (true)
				{
					//SoundManagerRef->PlaySFX("Kitchen.mp3");
				}
				break;
			}
		}
		break;
	}
	}
}
