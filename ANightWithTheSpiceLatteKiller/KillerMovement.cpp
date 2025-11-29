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

char KillerMovement::GetRandomAdjacentExcluding(char currentRoom, const std::vector<char>& excludedRooms) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	auto it = KillerMainRef->MapManagerRef->AdjacentRoomsRelations.find(currentRoom);
	if (it == KillerMainRef->MapManagerRef->AdjacentRoomsRelations.end()) return '\0';

	const auto& adjacents = it->second;
	std::vector<char> validRooms;

	for (char room : adjacents) {
		bool isExcluded = false;
		for (char excluded : excludedRooms) {
			if (room == excluded) {
				isExcluded = true;
				break;
			}
		}
		if (!isExcluded) validRooms.push_back(room);
	}

	if (validRooms.empty()) return adjacents[0];

	std::uniform_int_distribution<> dis(0, validRooms.size() - 1);
	return validRooms[dis(gen)];
}

//Can move everywhere
void KillerMovement::MoveKiller(char killerRoom) {
	KillerMainRef->MapManagerRef->KillerPosition = GetRandomPosInRoom(GetRandomAdjacent(killerRoom));
	KillerMainRef->MapManagerRef->KillerCurrentRoom = KillerMainRef->MapManagerRef->Map[KillerMainRef->MapManagerRef->KillerPosition.second][KillerMainRef->MapManagerRef->KillerPosition.first];
}

//Move but with restriction
void KillerMovement::MoveKillerSafe(bool avoidAdjacent) {
	char playerRoom = KillerMainRef->MapManagerRef->PlayerCurrentRoom;
	std::vector<char> excludedRooms = { playerRoom };

	// if adjacent room
	if (avoidAdjacent) {
		auto it = KillerMainRef->MapManagerRef->AdjacentRoomsRelations.find(playerRoom);
		if (it != KillerMainRef->MapManagerRef->AdjacentRoomsRelations.end()) {
			for (char adj : it->second) {
				excludedRooms.push_back(adj);
			}
		}
	}

	char targetRoom = GetRandomAdjacentExcluding(KillerMainRef->MapManagerRef->KillerCurrentRoom, excludedRooms);

	KillerMainRef->MapManagerRef->KillerPosition = GetRandomPosInRoom(targetRoom);
	KillerMainRef->MapManagerRef->KillerLastRoom = KillerMainRef->MapManagerRef->KillerCurrentRoom;
	KillerMainRef->MapManagerRef->KillerCurrentRoom = targetRoom;
}