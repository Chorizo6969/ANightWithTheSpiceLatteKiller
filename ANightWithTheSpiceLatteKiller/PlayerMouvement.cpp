#include "PlayerMouvement.h"

using namespace std;

PlayerMouvement::PlayerMouvement(MapManager* map) {
	MapRef = map;
}

void PlayerMouvement::Move(int addOnX, int addOnY) {
	if (MapRef->_map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first + addOnX] != '0') MapRef->PlayerPosition.first = max(0, min(MapRef->PlayerPosition.first + addOnX, MapRef->Printer->Csbi.dwMaximumWindowSize.X - 1));
	if (MapRef->_map[MapRef->PlayerPosition.second + addOnY][MapRef->PlayerPosition.first] != '0') MapRef->PlayerPosition.second = max(1, min(MapRef->PlayerPosition.second + addOnY, MapRef->Printer->Csbi.dwMaximumWindowSize.Y - 1));
}
