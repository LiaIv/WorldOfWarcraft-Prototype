#pragma once
#include <iostream>
#include "String.h"
using namespace std;

const int XY = 2;
const int COUNT_OF_MONSTERS = 30;
const int MAP_ROWS = 23;
const int MAP_COLUMNS = 38;

class Map {
	char map[MAP_ROWS][MAP_COLUMNS];
	int cordinatesOfMontser[COUNT_OF_MONSTERS][XY];
	int currentRowOfHero;
	int currentColOfHero;
public:
	char* getMap();
	int getCurrentRowOfHero();
	void setCurrentRowOfHero(int row);
	int getCurrentColOfHero();
	void setCurrentColOfHero(int col);

	Map();
	void fillMap();
	void printMap();
	char moveUp();
	char moveLeft();
	char moveDown();
	char moveRight();
	void deadMonster();


};