#pragma once
#include <iostream>
#include "Hero.h"
#include "Monster.h"
#include "Map.h"
#include "Player.h"
#include "StartingScreen.h"
using namespace std;

class Gameplay {
	Player player;
	Map map;
public:
	Gameplay(String name, int heroNum);
	void printMovementCommands();
	bool move(int movementCommand);
	void fight(Hero& hero, Monster& monster);
	void fightCommmand(char attackOrDef);
	void endOfAttack(bool isAliveHero, bool isAliveMonster);
	void gameOver();
	void winGame();
	void saveGame();

};
