#pragma once
#include <vector>
#include "ConsolePrinter.h"
#include <map>

using namespace std;

class MapManager
{
public:
	MapManager(ConsolePrinter* printer);
	map<char, vector<char>> Rooms;
	pair<float, float> PlayerPosition;
	pair<float, float> KillerPosition;
	int PlayerCurrentRoom = 0;
	int KillerCurrentRoom = 0;

	vector<vector<char>> Map;
	ConsolePrinter* Printer; 
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);
	bool IsAdjacentOfPlayer(char c);

private:
	void Init();
	void SetCharAttributes(CHAR_INFO* c, int colorOverrideIndex = -1);

	string _baseMap;
	vector<CHAR_INFO> _buffer;
};

