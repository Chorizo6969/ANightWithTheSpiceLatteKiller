#include "PlayerMouvement.h"

PlayerMouvement::PlayerMouvement(MapManager* map, KillerMain* killer)
	: MapRef(map), stepCounter_(subject_) 
{
	subject_.Attach(killer);
}

void PlayerMouvement::Move(int addOnX, int addOnY)
{
	// check if player pos + X isn't a wall or a door
	if (MapRef->Map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first + addOnX] != '#'
		&& MapRef->Map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first + addOnX] != '/')

		// add on X
		MapRef->PlayerPosition.first += addOnX;

	// check if player pos + Y isn't a wall or a door
	if (MapRef->Map[MapRef->PlayerPosition.second + addOnY][MapRef->PlayerPosition.first] != '#'
		&& MapRef->Map[MapRef->PlayerPosition.second + addOnY][MapRef->PlayerPosition.first] != '/')

		// add on Y
		MapRef->PlayerPosition.second += addOnY;

	// update PlayerCurrentRoom and step counter
	MapRef->PlayerCurrentRoom = MapRef->Map[MapRef->PlayerPosition.second][MapRef->PlayerPosition.first];
	stepCounter_.IncreaseStep();

	//if (MapRef->PlayerCurrentRoom == '@') {
	//	// do the latte thing
	//	cout << "latte" << endl;
	//}
	//else if(count(MapRef->DoorsSymbols.begin(), MapRef->DoorsSymbols.end(), MapRef->PlayerCurrentRoom)){
	//	cout << "door" << endl;
	//}
}