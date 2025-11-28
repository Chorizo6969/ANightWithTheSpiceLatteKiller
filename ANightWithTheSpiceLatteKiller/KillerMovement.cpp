#include "KillerMovement.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

KillerMovement::KillerMovement(MapManager* map) : MapManagerRef(map) {

}

KillerMovement::~KillerMovement() {

}

char KillerMovement::GetRandomAdjacent(char key) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	auto it = MapManagerRef->AdjacentRoomsRelations.find(key);
	if (it != MapManagerRef->AdjacentRoomsRelations.end()) {
		const auto& adjacents = it->second;
		std::uniform_int_distribution<> dis(0, adjacents.size() - 1);
		return adjacents[dis(gen)];
	}
	return '\0';

}

void KillerMovement::MoveKiller() {
	GetRandomAdjacent('e');
	/*MapManagerRef->CharPosMapByRoom;*/
}
