#include "KillerMovement.h"

#include "KillerMain.h"    
#include "MapManager.h"

KillerMovement::KillerMovement(KillerMain* mainRef) : KillerMainRef(mainRef) {
	KillerMainRef->MapManagerRef->KillerCurrentRoom = KillerMainRef->MapManagerRef->Map[KillerMainRef->MapManagerRef->KillerPosition.second][KillerMainRef->MapManagerRef->KillerPosition.first];
}

KillerMovement::~KillerMovement() {

}

char KillerMovement::GetRandomAdjacent(char key) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	auto it = KillerMainRef->MapManagerRef->AdjacentRoomsRelations.find(key);
	if (it != KillerMainRef->MapManagerRef->AdjacentRoomsRelations.end()) {
		const auto& adjacents = it->second;
		std::uniform_int_distribution<> dis(0, adjacents.size() - 1);
		return adjacents[dis(gen)];
	}
	return '\0';
}

pair<float, float> KillerMovement::GetRandomPosInRoom(char key) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	auto it = KillerMainRef->MapManagerRef->CharPosMapByRoom.find(key);
	if (it != KillerMainRef->MapManagerRef->CharPosMapByRoom.end()) {
		const auto& adjacents = it->second;
		std::uniform_int_distribution<> dis(0, adjacents.size() - 1);
		return adjacents[dis(gen)];
	}
	return KillerMainRef->MapManagerRef->KillerPosition;
}

void KillerMovement::MoveKiller(char killerRoom) {
	KillerMainRef->MapManagerRef->KillerPosition = GetRandomPosInRoom(GetRandomAdjacent(killerRoom));
	KillerMainRef->MapManagerRef->KillerCurrentRoom = KillerMainRef->MapManagerRef->Map[KillerMainRef->MapManagerRef->KillerPosition.second][KillerMainRef->MapManagerRef->KillerPosition.first];
	//std::cout << KillerMainRef->MapManagerRef->KillerPosition.second << std::endl;
	//std::cout << KillerMainRef->MapManagerRef->KillerPosition.first << std::endl;
}
