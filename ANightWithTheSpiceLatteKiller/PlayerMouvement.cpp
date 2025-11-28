#include "PlayerMouvement.h"

using namespace std;

PlayerMouvement::PlayerMouvement(MapManager* map, KillerMain* killer)
{
	MapRef = map;

	EventManager subject;
	subject.Attach(killer);
	StepCounter stepCounter(subject);
	StepCounterRef = &stepCounter;
}

void PlayerMouvement::Move(int addOnX, int addOnY) {
	if (MapRef->Map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first + addOnX] != '#') MapRef->PlayerPosition.first = max(0, min(MapRef->PlayerPosition.first + addOnX, MapRef->Printer->Csbi.dwMaximumWindowSize.X - 1));
	if (MapRef->Map[MapRef->PlayerPosition.second + addOnY][MapRef->PlayerPosition.first] != '#') MapRef->PlayerPosition.second = max(1, min(MapRef->PlayerPosition.second + addOnY, MapRef->Printer->Csbi.dwMaximumWindowSize.Y - 1));
	MapRef->PlayerCurrentRoom = MapRef->Map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first];
	StepCounterRef->IncreaseStep();
}
