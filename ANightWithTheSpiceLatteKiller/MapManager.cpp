#include <sstream>
#include "MapManager.h"

#include <algorithm>

MapManager::MapManager(ConsolePrinter* printer) {
	Printer = printer;
	//_baseMap = "#################################################################################ddddddddddddd#kkkkkkkkkkkkkkkkkkk!/!ssssssssssssssssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#ssssssssssssssssssssssssssssssss!/!ffffffff##dddddddddddd!/!kkkkkkkkkkkkkkkkkkk################ssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#bbbbbbbbbbbbbb#ssssssssssssssssss#ffffff!ff##ddddddddddddd#kkkkkkkkkkk##########bbbbbbbbbbbbbb##########################/####ddddddddddddd#kkkkkk!kkkk#bbbbbbbbbbbbbbbbbbbbbb!/!cccccccccccccccccccccccc!cc##ddddddddddddd#######/#####bbbbbbbbbbbbbbbbbbbbbbb#cccccccccccccccccccccccccccc##dddddd!dddddd#bbbbbb!bbbbbbbbbbbbbbbbbbbbbb!bbbbb#cccccccccccccccccccccccccccc########/#######bbbbbbbbbbbbbbbbbb###########/######cccccc!ccccccccccccccccccccc##qqqqqq!qqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttt!ttttt#######/#############cccccccc##qqqqqqqqqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttttttttt#vvvvvv!vv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq####################tttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqq!qqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#ccccc!cc#####/##qqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww######/####eee!e#qqqqqqq#oooooooooooooo!/!ttttttttttttttt!tt#vvvvvvvv!/!wwwwwwww#uuuuu!uu##eeeee#########ooooooooooooooo#################/###vv!vvvvvv#wwwwwwww!/!uuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#llllllllllllllll!ll###/#######wwwwwwwww#uuuuuuuu##eeeeeeeeeeee!/!oooooooooooooo#lllllllllllllllllll#mm!mmmmmm#wwwwwwwww#uuuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#lllllllllllllllllll#mmmmmmmmm###########uuuuuuuu##eeeeeeeeeeeee#ooooooooo#######lllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu##eeeeeeeeeeeee#oooooooo!/!llllllllllllllllllllllll#mmmmmmmmmmmmmmmmmm!/!uuuuuuu##eeeeeeeeeeeee#ooooooooo#lllllllllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu#################################################################################";
	baseMap_ = "#################################################################################ddddddddddddd#kkkkkkkkkkkkkkkkkkk3/3ssssssssssssssssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#ssssssssssssssssssssssssssssssss4/4ffffffff##dddddddddddd2/2kkkkkkkkkkkkkkkkkkk################ssssssssssssssssss#fffffffff##ddddddddddddd#kkkkkkkkkkkkkkkkkkkk#bbbbbbbbbbbbbb#ssssssssssssssssss#ffffff5ff##ddddddddddddd#kkkkkkkkkkk##########bbbbbbbbbbbbbb##########################/####ddddddddddddd#kkkkkk]kkkk#bbbbbbbbbbbbbbbbbbbbbb[/[cccccccccccccccccccccccc5cc##ddddddddddddd#######/#####bbbbbbbbbbbbbbbbbbbbbbb#cccccccccccccccccccccccccccc##dddddd1dddddd#bbbbbb]bbbbbbbbbbbbbbbbbbbbbb)bbbbb#cccccccccccccccccccccccccccc########/#######bbbbbbbbbbbbbbbbbb###########/######cccccc(ccccccccccccccccccccc##qqqqqq1qqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttt)ttttt#######/#############cccccccc##qqqqqqqqqqqqq#bbbbbbbbbbbbbbbbbb#tttttttttttttttt#vvvvvv(vv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq####################tttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqqqqqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#cccccccc##qqq0qqqqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww#ccccc6cc#####/##qqqqqqq#ooooooooooooooo#ttttttttttttttttttt#vvvvvvvvv#wwwwwwwww######/####eee0e#qqqqqqq#oooooooooooooo{/{ttttttttttttttt>tt#vvvvvvvv9/9wwwwwwww#uuuuu6uu##eeeee#########ooooooooooooooo#################/###vv<vvvvvv#wwwwwwww7/7uuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#llllllllllllllll>ll###/#######wwwwwwwww#uuuuuuuu##eeeeeeeeeeee$/$oooooooooooooo#lllllllllllllllllll#mm<mmmmmm#wwwwwwwww#uuuuuuuu##eeeeeeeeeeeee#ooooooooooooooo#lllllllllllllllllll#mmmmmmmmm###########uuuuuuuu##eeeeeeeeeeeee#ooooooooo#######lllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu##eeeeeeeeeeeee#oooooooo}/}llllllllllllllllllllllll#mmmmmmmmmmmmmmmmmm8/8uuuuuuu##eeeeeeeeeeeee#ooooooooo#lllllllllllllllllllllllll#mmmmmmmmmmmmmmmmmmm#uuuuuuuu#################################################################################";
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

	// Init doors relations
	DoorsSymbols = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ']', '[', ')', '(', '$', '>', '<', '{', '}', };

	InitMap();
	InitRoomPosDict();
	InitDoorsRelations();

	//PlayerPosition = make_pair(Map.size() / 2, Map[0].size() / 2);
	//PlayerPosition = make_pair(45, 15);
	//KillerPosition = make_pair(105, 22);

	PlayerPosition = CharPosMapByRoom['d'][0];
	KillerPosition = CharPosMapByRoom['c'][0];
	KillerCurrentRoom = Map[KillerPosition.second][KillerPosition.first];
	KillerLastRoom = KillerCurrentRoom;
	latteComposantRef_ = new LatteComposant;
	latteComposantRef_->CreateLatteComposant(this);
}

MapManager::~MapManager() {
	delete Printer;
	delete latteComposantRef_;
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

	//int blankSpaceY = (Printer->Csbi.dwMaximumWindowSize.Y - Map.size()) / 2 - 10;
	//int blankSpaceX = (Printer->Csbi.dwMaximumWindowSize.X - Map[0].size()) / 2;

	CHAR_INFO blank;
	blank.Char.AsciiChar = 'x';
	blank.Attributes = Printer->MakeColor(CYAN, BLACK);

	//// Create blank space above the map
	//for (int i = 0; i < blankSpaceY; i++)
	//{
	//	for (int j = 0; j < blankSpaceX; j++)
	//	{
	//		buffer.push_back(blank);
	//	}
	//}

	for (int i = 0; i < Map.size(); i++) {

		for (int j = 0; j < Map[i].size(); j++)
		{
			//for (int x = 0; x < blankSpaceX; x++) {
			//	buffer[i * Printer->Csbi.dwMaximumWindowSize.X+ j] = blank;
			//}
			// Handle player pos
			if (i == PlayerPosition.second && j == PlayerPosition.first)
			{
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = '*';
				//cell.Attributes = Printer->MakeColor(playerColorOverride, DARK_GRAY);
				SetCharAttributes(&cell, make_pair(i, j), colorOverrideIndex);
			}
			// Handle killer pos
			else if (i == KillerPosition.second && j == KillerPosition.first) {
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = '§';
				SetCharAttributes(&cell, make_pair(i, j), colorOverrideIndex);
			}
			else if (count(LatteComponentsPos.begin(), LatteComponentsPos.end(), make_pair(j, i))) {
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = '@';
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

void MapManager::InitMap()
{
	// TODO : prendre en compte la taille de la boîte de dialogue
	int mapSizeY = 25;
	int mapSizeX = 80;

	int blankY = (Printer->Csbi.dwMaximumWindowSize.Y - mapSizeY) / 2 - 5;
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

		for (int x = 0; x < blankX; x++) {
			newLine.push_back(' ');
		}

		for (int x = 0; x < mapSizeX; x++)
		{
			newLine.push_back(baseMap_[y * mapSizeX + x]);
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
/// Set the CHAR_INFO input depending on its type and utility
/// </summary>
/// <param name="c"></param>
void MapManager::SetCharAttributes(CHAR_INFO* c, pair<float, float> charPos, int colorOverrideIndex)
{
	switch (c->Char.AsciiChar) {
	case '*':
		c->Attributes = Printer->MakeColor(LIGHT_YELLOW, DARK_GRAY);
		break;
	case '#':
		c->Attributes = Printer->MakeColor(LIGHT_RED, LIGHT_RED);
		break;
	case '/':
		c->Attributes = Printer->MakeColor(RED, RED);
		break;
	case '@':
		c->Attributes = (Map[charPos.first][charPos.second] == PlayerCurrentRoom) ? Printer->MakeColor(YELLOW, DARK_GRAY) : Printer->MakeColor(BLACK, BLACK);
		break;
	case '§':
		c->Attributes = (/*PlayerCurrentRoom == KillerCurrentRoom*/ true) ? Printer->MakeColor(KillerColor, DARK_GRAY) : Printer->MakeColor(BLACK, BLACK);
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

void MapManager::InitRoomPosDict() {

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

void MapManager::InitDoorsRelations() {
	pair<float, float> currentPos;
	// used
	map<char, pair<float, float>> firstOccurencies;

	// iterate over the map
	for (int y = 0; y < Map.size(); y++) {
		for (int x = 0; x < Map[y].size(); x++) {
			// if char is a door
			if (count(DoorsSymbols.begin(), DoorsSymbols.end(), Map[y][x])) {

				currentPos = make_pair(y, x);

				// if firstOcc already contains char pos as key (means that its value is already present in the dict as key)
				if (firstOccurencies.count(Map[y][x])) {
					// change temp value in dict for currentPos
					DoorsLinks[firstOccurencies[Map[y][x]]] = currentPos;
					// add in dict the reverse relation
					DoorsLinks.insert(make_pair(currentPos, firstOccurencies[Map[y][x]]));
				}
				// else 
				else {
					// add currentPos to firstOccurencies, whith its char as key
					firstOccurencies.insert(make_pair(Map[y][x], currentPos));
					// add currentPos to dict as key and with a fake temporary value
					DoorsLinks.insert(make_pair(currentPos, make_pair(-1, -1)));
				}
			}
		}
	}
}