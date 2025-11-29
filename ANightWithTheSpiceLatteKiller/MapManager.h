#pragma once
#include <vector>
#include "ConsolePrinter.h"
#include "ConsoleColorEnum.h"
#include "LatteComposant.h"
#include <map>

using namespace std;

class MapManager
{
public:
	MapManager(ConsolePrinter* printer);
	~MapManager();

	map<char, vector<char>> AdjacentRoomsRelations; // used to get adjacent rooms char
	map<char, vector<pair<float, float>>> CharPosMapByRoom; // used to get every pos occupied by each room
	
	vector<char> DoorsSymbols;
	map<pair<float, float>, pair<float, float>> DoorsLinks;

	pair<float, float> PlayerPosition;
	pair<float, float> KillerPosition;
	pair<float, float> KillerLastPosition;

	vector<pair<float, float>> LatteComponentsPos;

	char PlayerCurrentRoom = 0;
	char KillerCurrentRoom = 0;
	char KillerLastRoom = 0;

	// TEMP POUR EMRYS
	int KillerColor = RED;

	vector<vector<char>> Map;
	ConsolePrinter* Printer; 
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);
	bool IsAdjacentToPlayer(char c);

	vector<pair<float, float>> GetRoomFromChar(char c);

private:
	void InitMap();
	void InitRoomPosDict();
	void InitDoorsRelations();
	void SetCharAttributes(CHAR_INFO* c, pair<float, float> charPos, int colorOverrideIndex = -1);

	LatteComposant* latteComposantRef_;
	string baseMap_;
	vector<CHAR_INFO> buffer_;
};

