#include "PlayerMouvement.h"

using namespace std;

PlayerMouvement::PlayerMouvement(MapManager* map) {
	MapRef = map;
}

void PlayerMouvement::Move(int addOnX, int addOnY) {
	
	MapRef->PlayerPosition.first = max(0, min(MapRef->PlayerPosition.first + addOnX, MapRef->Printer->Csbi.dwMaximumWindowSize.X - 1));
	MapRef->PlayerPosition.second = max(1, min(MapRef->PlayerPosition.second + addOnY, MapRef->Printer->Csbi.dwMaximumWindowSize.Y - 1));
}
