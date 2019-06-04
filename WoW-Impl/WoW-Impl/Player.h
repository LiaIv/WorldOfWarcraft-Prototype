#pragma once
#include "Hero.h"
using namespace std;

class Player {
	String name;
	Hero* chosenHero;
	int countOfWins;
	int currentCondinates[2];
	void Free();
	void CopyFrom(const Player& other);
public:
	Hero* getHero();
	Player();
	Player(String name, int heroNumber);
	Player& operator=(const Player& other);
};



