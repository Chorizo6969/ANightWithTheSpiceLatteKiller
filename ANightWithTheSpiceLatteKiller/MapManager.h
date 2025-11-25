#pragma once
#include <vector>
#include "PlayerMain.h"
#include "ConsolePrinter.h"

using namespace std;

class MapManager
{
public:
	MapManager(PlayerMain* player, ConsolePrinter* printer);
	pair<float, float> PlayerPosition;
	void PrintMap(int colorOverrideIndex = -1, bool excludePlayer = false);
	void TintMap(int colorIndex, int timeMiliSec, bool excludePlayer = false);

private:
	void Init();
	char GetChar();

	string _baseMap;
	PlayerMain* _player;
	ConsolePrinter* _printer; 
	vector<vector<char>> _map;
	vector<CHAR_INFO> _buffer;

public:

	MapManager() = default;
};

