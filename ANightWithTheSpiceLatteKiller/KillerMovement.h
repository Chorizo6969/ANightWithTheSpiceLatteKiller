#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
using namespace std;

class KillerMain;

class KillerMovement
{
public:
	KillerMain* KillerMainRef;

	KillerMovement(KillerMain* mainRef);
	~KillerMovement();
	//Move killer normally, no restrictions
	void MoveKiller(char killerRoom);
	//Move killer with restrictions. By default, avoid playerRoom, if bool true, avoid adjacent rooms too
	void MoveKillerSafe(bool avoidAdjacent);

private:
	//return a random adjacentRoom of the killer current room
	char GetRandomAdjacent(char key); 
	//return a pos in the room
	pair<float, float> GetRandomPosInRoom(char key);
	//return a random adjacentRoom of the killer current room, with restrictions
	char GetRandomAdjacentExcluding(char currentRoom, const std::vector<char>& excludedRooms);
};

