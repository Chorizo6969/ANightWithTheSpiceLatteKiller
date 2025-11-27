#pragma once
#include <vector>
#include "ConsolePrinter.h"

using namespace std;

class MapManager
{
public:
	MapManager(ConsolePrinter* printer);
	pair<float, float> PlayerPosition;
	ConsolePrinter* Printer; 
	vector<vector<char>> Map;
	int PlayerCurrentRoom = 0;
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);

private:
	void Init();
	void SetCharAttributes(CHAR_INFO* c);

	string _baseMap;
	vector<CHAR_INFO> _buffer;
};

