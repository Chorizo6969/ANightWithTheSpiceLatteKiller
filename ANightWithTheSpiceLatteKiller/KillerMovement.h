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

	void MoveKiller();
private:
	char GetRandomAdjacent(char key);
	pair<float, float> GetRandomPosInRoom(char key);

};

