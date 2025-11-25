#include <iostream>
#include "ConsolePrinter.h"
using namespace std;

// constructor
ConsolePrinter::ConsolePrinter() {
	HConsoleRef = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(HConsoleRef, &Csbi);
}

// string version
void ConsolePrinter::ColoredPrint(string message, int colorIndex) {
	SetConsoleTextAttribute(HConsoleRef, colorIndex);
	cout << message;
	SetConsoleTextAttribute(HConsoleRef, 7);
}

// char version
void ConsolePrinter::ColoredPrint(char message, int colorIndex) {
	SetConsoleTextAttribute(HConsoleRef, colorIndex);
	cout << message;
	SetConsoleTextAttribute(HConsoleRef, 7);
}


// opération abstraite de bits trouvée sur internet
WORD ConsolePrinter::MakeColor(int foreGround, int backGround) {
	return (backGround << 4) | (foreGround & 0x0F);
}

