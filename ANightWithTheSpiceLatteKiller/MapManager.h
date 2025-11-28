#pragma once
#include <vector>
#include "ConsolePrinter.h"
#include <map>

using namespace std;

class MapManager
{
public:
	MapManager(ConsolePrinter* printer);
	~MapManager();

	map<char, vector<char>> AdjacentRoomsRelations; // used to get adjacent rooms char
	map<char, vector<pair<float, float>>> CharPosMapByRoom; // used to get every pos occupied by each room

	pair<float, float> PlayerPosition;
	pair<float, float> KillerPosition;
	pair<float, float> KillerLastPosition;
	int PlayerCurrentRoom = 0;
	int KillerCurrentRoom = 0;

	vector<vector<char>> Map;
	ConsolePrinter* Printer; 
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);
	bool IsAdjacentToPlayer(char c);
	vector<pair<float, float>> GetRoomFromChar(char c);

private:
	void Init();
	void SetUpRoomDict();
	void SetCharAttributes(CHAR_INFO* c, pair<float, float> charPos, int colorOverrideIndex = -1);

	string _baseMap;
	vector<CHAR_INFO> _buffer;
};

