#include <sstream>
#include "MapManager.h"
#include "ConsoleColorEnum.h"

MapManager::MapManager(ConsolePrinter* printer) {
	Printer = printer;
	_baseMap = "#################################################################################ddddddddddddd#kkkkkkkkkkkkkkkkkkk!/!ssssssssssssssssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#ssssssssssssssssssssssssssssssss!/!ffffffff##dddddddddddd!/!kkkkkkkkkkkkkkkkkkk################ssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#bbbbbbbbbbbbbb#ssssssssssssssssss#ffffff!ff##ddddddddddddd#kkkkkkkkkkk##########bbbbbbbbbbbbbb##########################/####ddddddddddddd#kkkkkk!kkkk#bbbbbbbbbbbbbbbbbbbbbb!/!cccccccccccccccccccccccc!cc##ddddddddddddd#######/#####bbbbbbbbbbbbbbbbbbbbbbb#cccccccccccccccccccccccccccc##dddddd!dddddd#bbbbbb!bbbbbbbbbbbbbbbbbbbbbb!bbbbb#cccccccccccccccccccccccccccc########/#######bbbbbbbbbbbbbbbbbb###########/######cccccc!ccccccccccccccccccccc##qqqqqq!qqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttt!ttttt#######/#############cccccccc##qqqqqqqqqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttttttttt#vvvvvv!vv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq####################tttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqq!qqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#ccccc!cc#####/##qqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww######/####eee!e#qqqqqqq#oooooooooooooo!/!ttttttttttttttt!tt#vvvvvvvv!/!wwwwwwww#uuuuu!uu##eeeee#########ooooooooooooooo#################/###vv!vvvvvv#wwwwwwww!/!uuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#llllllllllllllll!ll###/#######wwwwwwwww#uuuuuuuu##eeeeeeeeeeee!/!oooooooooooooo#lllllllllllllllllll#mm!mmmmmm#wwwwwwwww#uuuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#lllllllllllllllllll#mmmmmmmmm###########uuuuuuuu##eeeeeeeeeeeee#ooooooooo#######lllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu##eeeeeeeeeeeee#oooooooo!/!llllllllllllllllllllllll#mmmmmmmmmmmmmmmmmm!/!uuuuuuu##eeeeeeeeeeeee#ooooooooo#lllllllllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu#################################################################################";
	//_baseMap = "#################################################################################ddddddddddddd#kkkkkkkkkkkkkkkkkkkk/sssssssssssssssssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#sssssssssssssssssssssssssssssssss/fffffffff##ddddddddddddd/kkkkkkkkkkkkkkkkkkkk################ssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#bbbbbbbbbbbbbb#ssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkk##########bbbbbbbbbbbbbb##########################/####ddddddddddddd#kkkkkkkkkkk#bbbbbbbbbbbbbbbbbbbbbbb/cccccccccccccccccccccccccccc##ddddddddddddd#######/#####bbbbbbbbbbbbbbbbbbbbbbb#cccccccccccccccccccccccccccc##ddddddddddddd#bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb#cccccccccccccccccccccccccccc########/#######bbbbbbbbbbbbbbbbbb###########/######cccccccccccccccccccccccccccc##qqqqqqqqqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttttttttt#######/#############cccccccc##qqqqqqqqqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq####################tttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc#####/##qqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww######/####eeeee#qqqqqqq#ooooooooooooooo/ttttttttttttttttttt#vvvvvvvvv/wwwwwwwww#uuuuuuuu##eeeee#########ooooooooooooooo#################/###vvvvvvvvv#wwwwwwwww/uuuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#lllllllllllllllllll###/#######wwwwwwwww#uuuuuuuu##eeeeeeeeeeeee/ooooooooooooooo#lllllllllllllllllll#mmmmmmmmm#wwwwwwwww#uuuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#lllllllllllllllllll#mmmmmmmmm###########uuuuuuuu##eeeeeeeeeeeee#ooooooooo#######lllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu##eeeeeeeeeeeee#ooooooooo/lllllllllllllllllllllllll#mmmmmmmmmmmmmmmmmmm/uuuuuuuu##eeeeeeeeeeeee#ooooooooo#lllllllllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu#################################################################################";
	AdjacentRoomsRelations = {
		{ 'e', {'q', 'o'} },
		{ 'd', {'k', 'q'} },
		{ 'k', {'d', 'b', 's'}},
		{ 's', {'k', 'f'} },
		{ 'f', {'s', 'c'} },
		{ 'c', {'b', 'v', 'f', 'u'}},
		{ 'w', {'v', 'u'} },
		{ 'm', {'v', 'u'} },
		{ 'v', {'c', 'w', 'm'}},
		{ 'b', {'k', 'c', 't'}},
		{ 't', {'o', 'b', 'l'}},
		{ 'o', {'e', 't', 'l'}},
		{ 'l', {'o', 't'} },
		{ 'u', {'c', 'w', 'm'}},
		{ 'q', {'d', 'e'} }
	};
	Init();
	SetUpRoomDict();
	PlayerPosition = make_pair(Map.size() / 2, Map[0].size() / 2);
	KillerPosition = make_pair(65, 17);
	KillerCurrentRoom = Map[KillerPosition.second][KillerPosition.first];
}

MapManager::~MapManager() {
	delete Printer;
}

void MapManager::PrintMap(int colorOverrideIndex, bool excludePlayer) {
	int mapColorOverride;
	int playerColorOverride;
	int killerColorOverride;

	// override color
	if (colorOverrideIndex > -1) {
		mapColorOverride = colorOverrideIndex;
		playerColorOverride = (excludePlayer) ? LIGHT_YELLOW : colorOverrideIndex;
		killerColorOverride = (excludePlayer) ? LIGHT_BLUE : colorOverrideIndex;
	}
	else {
		mapColorOverride = DARK_GRAY;
		playerColorOverride = LIGHT_YELLOW;
		killerColorOverride = BLUE;
	}

	// create buffer used to print whole map in one print
	vector<CHAR_INFO> buffer(Printer->Csbi.dwMaximumWindowSize.Y * Printer->Csbi.dwMaximumWindowSize.X);

	int blankSpaceY = (Printer->Csbi.dwMaximumWindowSize.Y - Map.size()) / 2;
	int blankSpaceX = (Printer->Csbi.dwMaximumWindowSize.X - Map[0].size()) / 2;

	CHAR_INFO blank;
	blank.Char.AsciiChar = ' ';
	blank.Attributes = Printer->MakeColor(BLACK, BLACK);

	//// Create blank space above the map
	//for (int i = 0; i < blankSpaceY; i++)
	//{
	//	for (int j = 0; j < blankSpaceX; j++)
	//	{
	//		buffer.push_back(blank);
	//	}
	//}

	for (int i = 0; i < Map.size(); i++) {
		/*for (int x = 0; x < blankSpaceX; x++) {
			buffer.push_back(blank);
		}*/
		for (int j = 0; j < Map[i].size(); j++)
		{
			//for (int j = 0; j < blankSpaceX; j++)
			//{
			//	buffer.push_back(blank);
			//}
			// Handle player pos
			if (i == PlayerPosition.second && j == PlayerPosition.first)
			{
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = '*';
				cell.Attributes = Printer->MakeColor(playerColorOverride, DARK_GRAY);
			}
			else if (i == KillerPosition.second && j == KillerPosition.first) {
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = '§';

				//cell.Attributes = Printer->MakeColor(playerColorOverride, DARK_GRAY);
				SetCharAttributes(&cell, make_pair(i, j), colorOverrideIndex);
			}
			else
			{
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = Map[i][j];
				SetCharAttributes(&cell, make_pair(i, j), colorOverrideIndex);
			}
		}
	}

	SMALL_RECT region = { 0, 0, Printer->Csbi.dwMaximumWindowSize.X - 1, Printer->Csbi.dwMaximumWindowSize.Y - 1 };
	WriteConsoleOutput(Printer->HConsoleRef, buffer.data(), { (short)Printer->Csbi.dwMaximumWindowSize.X, (short)Printer->Csbi.dwMaximumWindowSize.Y }, { 0, 0 }, &region);
}

void MapManager::TintMap(int colorIndex, int timeMiliSec, bool excludePlayer) {
	PrintMap(colorIndex, excludePlayer);
	Sleep(timeMiliSec);
}

void MapManager::Init()
{
	// TODO : prendre en compte la taille de la boîte de dialogue
	int mapSizeY = 25;
	int mapSizeX = 80;

	int blankY = (Printer->Csbi.dwMaximumWindowSize.Y - mapSizeY) / 2;
	int blankX = (Printer->Csbi.dwMaximumWindowSize.X - mapSizeX) / 2;

	// TEMP add blank space above the map
	for (int i = 0; i < blankY; i++)
	{
		vector<char> newBlankLine(blankX, ' ');
		Map.push_back(newBlankLine);
	}

	for (int y = 0; y < mapSizeY; y++)
	{
		vector<char> newLine;

		for (int x = 0; x < mapSizeX; x++)
		{
			newLine.push_back(_baseMap[y * mapSizeX + x]);
		}

		Map.push_back(newLine);
	}

	//// TEMP add blank space below the map
	//for (int i = 0; i < blankY; i++)
	//{
	//	vector<char> newBlankLine(blankX, ' ');
	//	Map.push_back(newBlankLine);
	//}

}

/// <summary>
/// Set the CHAR_INFO input depending on
/// </summary>
/// <param name="c"></param>
void MapManager::SetCharAttributes(CHAR_INFO* c, pair<float, float> charPos, int colorOverrideIndex )
{
	switch (c->Char.AsciiChar) {
		c->Attributes = Printer->MakeColor(RED, RED);
		break;
	case '#':
		c->Attributes = Printer->MakeColor(LIGHT_RED, LIGHT_RED);
		break;
	case '/':
		c->Attributes = Printer->MakeColor(RED, RED);
		break;
	case '§':
		c->Attributes = (/*PlayerCurrentRoom == KillerCurrentRoom*/ true) ? Printer->MakeColor(RED, DARK_GRAY) : Printer->MakeColor(BLACK, BLACK);
		break;
	default:
			// si le char est le même que celui du joueur (donc même pièce) OU qu'il en a un similaire autour de lui (donc porte de même pièce)
		if (PlayerCurrentRoom == c->Char.AsciiChar && c->Char.AsciiChar != '!') {
			c->Attributes = Printer->MakeColor(DARK_GRAY, DARK_GRAY);
		}
		//// if the char is an adjacent room
		//else if (IsAdjacentOfPlayer(c->Char.AsciiChar)){
		//	c->Attributes = Printer->MakeColor(WHITE, WHITE);
		//}
		else {
			c->Attributes = Printer->MakeColor(BLACK, BLACK);
		}
		break;
	}
	if (colorOverrideIndex > -1) c->Attributes = Printer->MakeColor(colorOverrideIndex, colorOverrideIndex);
}

bool MapManager::IsAdjacentToPlayer(char c) {

	// return true if c is found in current room's adjacent rooms list
	for (char test : AdjacentRoomsRelations[Map[PlayerPosition.second][PlayerPosition.first]]) {
		if (test == c) return true;
	}
	return false;
}

//vector<pair<float, float>> GetRoomFromChar(char c) {
//
//}

void MapManager::SetUpRoomDict() {

	for (int y = 0; y < Map.size(); y++) {
		for (int x = 0; x < Map[y].size(); x++) {

			// if the character isn't present yet in the dict, add a list with its char as key
			if (!CharPosMapByRoom.count(Map[y][x])) {
				// create value
				vector<pair<float, float>> newCharPos;
				pair<float, float> newPos(x, y);
				newCharPos.push_back(newPos);

				// add the value with the char as key to dict
				CharPosMapByRoom.insert(pair<char, vector<pair<float, float>>>(Map[y][x], newCharPos));
			}
			else {
				// add only the value
				CharPosMapByRoom[Map[y][x]].push_back(pair<float, float>(x, y));
			}
		}
	}
}