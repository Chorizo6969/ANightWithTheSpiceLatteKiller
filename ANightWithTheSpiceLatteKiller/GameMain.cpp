#include "GameMain.h"

GameMain::GameMain() {
	ConsolePrinterRef = new ConsolePrinter;
	MapManagerRef = new MapManager(ConsolePrinterRef);
	KillerMainRef = new KillerMain(MapManagerRef);
	PlayerMainRef = new PlayerMain(MapManagerRef, KillerMainRef);
	SoundManagerRef = new SoundManager;
}


GameMain::~GameMain() {

}

int main() {

	bool fullscreen = false;
	//main.KillerMainRef->TestStepSystem();
	while (!fullscreen) {
		if (GetKeyState(VK_MENU) & 0x8000)
		{
			if (GetKeyState(VK_RETURN) & 0x8000)
			{
				fullscreen = !fullscreen;
				cout << "fullscreen";
			}
		}
	}

	Sleep(800);

	GameMain main;

	while (1) {
		main.PlayerMainRef->MainElouann();
		cout << "<fatal error>";
		/*main.KillerMainRef->KillerMovementRef->MoveKiller();*/
	}

}


