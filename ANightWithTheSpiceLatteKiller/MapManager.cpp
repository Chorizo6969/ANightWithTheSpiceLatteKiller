#include <sstream>
#include "MapManager.h"
#include "ConsoleColorEnum.h"

MapManager::MapManager(ConsolePrinter* printer) {
	Printer = printer;

	//_baseMap = "000000000000000000000000000000000000000000000000000000000000000";
	_baseMap = "0000000000000000000000000000000000000000000000000000000000000000000000000000000009999999999999999990777777777777777777777777777777777700333333333333333333333330099999999999999999907777777777777777777777777777777777003333333333333333333333300999999999999999999077777777777777777777777777777777770033333333333333333333333009999999999999999990000000000000700000000000000000000000000000300000000000003330099999999999999999901111111111111111111111111111111111111111111111111111111033300999999999999999999011111111111111111111111111111111111111111111111111111110333009999999999999999990111111111111111111111111111111111111111111111111111111103330099999999999999999901111111111111111111111111111111111111111111111111111111033300999999999999999999011111111111111111111111111111111111111111111111111111110333009999999999999999990111110000000000000001111100000000000000000000000001111103330099900000000000000001111105555555555555011111022222222222222222222222011111033300999011111111111111111111055555555555555111110222222222222222222222220111110333009999111111111111111111115555555555555501111102222222222222222222222201111103330099901111111111111111111105555555555555011111022222222222220000000000011111033300000000200000000000000000055555555555550111110222222222222201111111111111110333002222222222222222222222200555555555555501111102222222222222011111111111111103330022222222222222222222222005555555555555011111222222222222222111111111111111033300222222222222222222222220055555555555550111110222222222222201111111111111110333002222222222222222222222200555555555555501111102222222222222011111111111111103330022222222222222222222222005555555555555011111022222222222220111111111111111033300222222222222222222222220055555555555550111110222222222222200000000400000000000002222222222222222222222200555555555555501111102222222222222004444444444444444440022222222222222222222222005555555555555011111022222222222220044444444444444444400222222222222222222222220055555555555550111110222222222222200444444444444444444000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	Init();
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
	vector<CHAR_INFO> buffer(Printer->Csbi.dwMaximumWindowSize.Y * Printer->Csbi.dwMaximumWindowSize.X);

	int blankSpaceY = (Printer->Csbi.dwMaximumWindowSize.Y - _map.size()) / 2;
	int blankSpaceX = (Printer->Csbi.dwMaximumWindowSize.X - _map[0].size()) / 2;

	CHAR_INFO blank;
	blank.Char.AsciiChar = ' ';
	blank.Attributes = Printer->MakeColor(BLACK, BLACK);

	// Create blank space above the map
	for (int i = 0; i < blankSpaceY; i++)
	{
		for (int j = 0; j < blankSpaceX; j++) 
		{
			buffer.push_back(blank);
		}
	}

	for (int i = 0; i < _map.size(); i++) {
		for (int j = 0; j < _map[i].size(); j++) 
		{
			// Handle player pos
			if (i == PlayerPosition.second && j == PlayerPosition.first) 
			{
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = 'o';
				cell.Attributes = Printer->MakeColor(playerColorOverride, BLACK);
			}
			else 
			{
				// OOR arg ERROR NEXT LINE
				CHAR_INFO& cell = buffer[i * Printer->Csbi.dwMaximumWindowSize.X + j];
				cell.Char.AsciiChar = _map[i][j];
				cell.Attributes = Printer->MakeColor(mapColorOverride, BLACK);
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
	int mapSizeY = 26;
	int mapSizeX = 80;

	int blankY = (Printer->Csbi.dwMaximumWindowSize.Y - mapSizeY) / 2;
	int blankX = (Printer->Csbi.dwMaximumWindowSize.X - mapSizeX) / 2;

	// TEMP add blank space above the map
	for (int i = 0; i < blankY; i++) 
	{
		vector<char> newBlankLine(blankX, ' ');
		_map.push_back(newBlankLine);
	}

	for (int y = 0; y < mapSizeY; y++) 
	{
		vector<char> newLine;

		for (int x = 0; x < mapSizeX; x++) 
		{
			newLine.push_back(_baseMap[y * mapSizeX + x]);
		}

		_map.push_back(newLine);
	}

	// TEMP add blank space below the map
	for (int i = 0; i < blankY; i++)
	{
		vector<char> newBlankLine(blankX, ' ');
		_map.push_back(newBlankLine);
	}

}

char MapManager::GetChar() 
{
	return '.';
}