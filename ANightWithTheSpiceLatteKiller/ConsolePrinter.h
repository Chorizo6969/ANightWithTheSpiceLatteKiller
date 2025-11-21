#pragma once
#include <iostream>
#include <windows.h>

class ConsolePrinter
{
public:
	ConsolePrinter();
	void ColoredPrint(std::string message, int colorIndex);
	void ColoredPrint(char message, int colorIndex);
	WORD MakeColor(int foreGround, int backGround);

	HANDLE HConsoleRef;
	CONSOLE_SCREEN_BUFFER_INFO Csbi;
};