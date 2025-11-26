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
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);

private:
	void Init();
	char GetChar();

	string _baseMap;
	vector<vector<char>> _map;
	vector<CHAR_INFO> _buffer;
};

