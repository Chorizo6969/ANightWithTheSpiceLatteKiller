#include <sstream>
#include "MapManager.h"
#include "ConsoleColorEnum.h"

MapManager::MapManager(PlayerMain* player, ConsolePrinter* printer) {
	_player = player;
	_printer = printer;
}

void MapManager::PrintMap(int colorOverrideIndex, bool excludePlayer) {
	int mapColorOverride;
	int playerColorOverride;

	// override color
	if (colorOverrideIndex > -1) {
		mapColorOverride = colorOverrideIndex;
		playerColorOverride = (excludePlayer) ? LIGHT_YELLOW : colorOverrideIndex;
	}
	else {
		mapColorOverride = DARK_GRAY;
		playerColorOverride = LIGHT_YELLOW;
	}

	// create buffer used to print whole map in one print
	vector<CHAR_INFO> buffer(_printer->Csbi.dwMaximumWindowSize.Y * _printer->Csbi.dwMaximumWindowSize.X);
	for (int i = 1; i < _map.size(); i++) {
		for (int j = 0; j < _map[i].size(); j++) {
			if (i == PlayerPosition.second && j == PlayerPosition.first) {
				CHAR_INFO& cell = buffer[i * _printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = 'o';
				cell.Attributes = _printer->MakeColor(playerColorOverride, BLACK);
			}
			else {
				CHAR_INFO& cell = buffer[i * _printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = _map[i][j];
				cell.Attributes = _printer->MakeColor(mapColorOverride, BLACK);
			}
		}
	}

	SMALL_RECT region = { 0, 0, _printer->Csbi.dwMaximumWindowSize.X - 1, _printer->Csbi.dwMaximumWindowSize.Y - 1 };
	WriteConsoleOutput(_printer->HConsoleRef, buffer.data(), { (short)_printer->Csbi.dwMaximumWindowSize.X, (short)_printer->Csbi.dwMaximumWindowSize.Y }, { 0, 0 }, &region);
}

void MapManager::TintMap(int colorIndex, int timeMiliSec, bool excludePlayer) {
	PrintMap(colorIndex, excludePlayer);
	Sleep(timeMiliSec);
}