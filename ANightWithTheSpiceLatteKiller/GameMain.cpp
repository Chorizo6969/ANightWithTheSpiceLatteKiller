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

	//cout << main.ConsolePrinterRef->Csbi.dwMaximumWindowSize.X << " " << main.ConsolePrinterRef->Csbi.dwMaximumWindowSize.Y;
	Sleep(100);
	bool fullscreen = false;
	//main.KillerMainRef->TestStepSystem();
	cout << R"(                           ___    _   _ _       _     _     _    _ _ _   _       _____ _           
                          / _ \  | \ | (_)     | |   | |   | |  | (_) | | |     |_   _| |          
                         / /_\ \ |  \| |_  __ _| |__ | |_  | |  | |_| |_| |__     | | | |__   ___  
                         |  _  | | . ` | |/ _` | '_ \| __| | |/\| | | __| '_ \    | | | '_ \ / _ \ 
                         | | | | | |\  | | (_| | | | | |_  \  /\  / | |_| | | |   | | | | | |  __/ 
                         \_| |_/ \_| \_/_|\__, |_| |_|\__|  \/  \/|_|\__|_| |_|   \_/ |_| |_|\___| 
                                           __/ |                                                   
                                          |___/                                                    
                          _____       _            _           _   _         _   ___ _ _           
                         /  ___|     (_)          | |         | | | |       | | / (_) | |          
                         \ `--. _ __  _  ___ ___  | |     __ _| |_| |_ ___  | |/ / _| | | ___ _ __ 
                          `--. \ '_ \| |/ __/ _ \ | |    / _` | __| __/ _ \ |    \| | | |/ _ \ '__|
                         /\__/ / |_) | | (_|  __/ | |___| (_| | |_| ||  __/ | |\  \ | | |  __/ |   
                         \____/| .__/|_|\___\___| \_____/\__,_|\__|\__\___| \_| \_/_|_|_|\___|_|   
                               | |                                                                 
                               |_|                                                                 )";

	cout << endl << endl << endl << endl << endl << "                                                Press Alt+Enter to start";
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

	Sleep(10);
	GameMain main;


	while (1) {
		main.PlayerMainRef->MainElouann();
		/*main.KillerMainRef->KillerMovementRef->MoveKiller();*/
	}

}


