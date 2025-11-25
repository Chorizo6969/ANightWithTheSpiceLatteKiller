#include <iostream>
#include "ConsolePrinter.h"
#include "PlayerMain.h"
#include "MapManager.h"
#include "ConsoleColorEnum.h"
#include "KillerMain.h"

//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77

int main()
{


	KillerMain* killerMain = new KillerMain;
	killerMain->ClientCode();

	//killerMain->DebugStateMachine();
}


