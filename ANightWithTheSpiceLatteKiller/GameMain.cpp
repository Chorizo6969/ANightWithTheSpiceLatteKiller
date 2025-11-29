#include "GameMain.h"

GameMain::GameMain() {
	ConsolePrinterRef = new ConsolePrinter;
	SoundManagerRef = new SoundManager;
	DialoguePrinterRef = new DialoguePrinter(ConsolePrinterRef);
	MapManagerRef = new MapManager(ConsolePrinterRef);
	KillerMainRef = new KillerMain(MapManagerRef, DialoguePrinterRef);
	PlayerMainRef = new PlayerMain(MapManagerRef, KillerMainRef, SoundManagerRef, DialoguePrinterRef);
	SoundManagerRef = new SoundManager;
	DialoguePrinterRef = new DialoguePrinter(ConsolePrinterRef);
}


GameMain::~GameMain() {

}

int main() {
#pragma region ScreenMenu


	bool fullscreen = false;
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

	cout << endl << endl << endl;
	//main.KillerMainRef->TestStepSystem();
	for (int i = 0; i < 94; i++) {
		char c = (i % 2 == 0) ? ' ' : '-';
		cout << c;
		if (i == 47) cout << " Press Alt+Enter to start";
	}
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
#pragma endregion

	Sleep(30);
	


	//cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl /*<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl*/;
	GameMain main;

	for (int i = 0; i < main.ConsolePrinterRef->Csbi.dwMaximumWindowSize.Y; i++) {
		cout << endl;
	}

	main.MapManagerRef->PrintMap();
	main.DialoguePrinterRef->WriteDialogue("utility", "game_start");

	while (1) {
		main.PlayerMainRef->MainElouann();
		//main.DialoguePrinterRef->WriteDialogue("killer", "try_open_door");
	}

}


