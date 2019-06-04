#include <iostream>
#include <fstream>
#include "Map.h"
using namespace std;

char* Map::getMap()
{
	return *map;
}

int Map::getCurrentRowOfHero()
{
	return currentRowOfHero;
}

void Map::setCurrentRowOfHero(int row)
{
	this->currentRowOfHero = row;
}

int Map::getCurrentColOfHero()
{
	return currentColOfHero;
}

void Map::setCurrentColOfHero(int col)
{
	this->currentColOfHero = col;
}

Map::Map() {
	fillMap();
	currentRowOfHero = 0;
	currentColOfHero = MAP_COLUMNS - 3;
}

void Map::fillMap() {
	ifstream file;
	file.open("karta.txt", ios::in);
	file >> noskipws;
	if (!file) {
		cerr << " ! Map couldn’t be loaded !\n";
		return;
	}
	else {
		for (int i = 0; i < MAP_ROWS; i++) {
			for (int j = 0; j < MAP_COLUMNS; j++) {
				file >> map[i][j];
			}
		}
	}
}

//void Map::printMap() {
//	for (int i = 0; i < MAP_ROWS; i++) {
//		for (int j = 0; j < MAP_COLUMNS; j++) {
//			cout << map[i][j];
//		}
//	}
//	cout << endl << endl;
//	cin.ignore();
//
//}

void Map::printMap() {
	cout << "\n Map legend: \n @ = You\n G = Goblin, D = Dragonkin, K = Death Knight\n * = Dead monster\n\n";
	for (int row = 0; row < MAP_ROWS; row++) {
		for (int col = 0; col < MAP_COLUMNS; col++) {
			if (row == currentRowOfHero && col == currentColOfHero) {
				cout << "@";
			}
			else {
				cout << map[row][col];
			}
		}
	}
	cout << "\n\n Directions: \n";
	cout << " 1 = Up\n 2 = Down\n 3 = Left\n 4 = Right\n\n 5 = Save game\n 6 = Back to start screen\n\n";

}

char Map::moveUp() {
	int row = currentRowOfHero - 1;
	int col = currentColOfHero;
	if (row < 0) {
		return '?';
	}
	char nextChar = map[row][col];
	if (nextChar == '|' || nextChar == '=') {
		return nextChar;
	}
	currentRowOfHero -= 1;
	return nextChar;
}


char Map::moveLeft() {
	int row = currentRowOfHero;
	int col = currentColOfHero - 1;
	char nextChar = map[row][col];
	if (nextChar == '|' || nextChar == '=') {
		return nextChar;
	}
	currentColOfHero -= 1;
	return nextChar;
}

char Map::moveDown() {
	int row = currentRowOfHero + 1;
	int col = currentColOfHero;
	if (row == MAP_ROWS - 1) {
		return '!';
	}
	char nextChar = map[row][col];
	if (nextChar == '|' || nextChar == '=') {
		return nextChar;
	}
	currentRowOfHero += 1;
	return nextChar;
}

char Map::moveRight() {
	int row = currentRowOfHero;
	int col = currentColOfHero + 1;
	char nextChar = map[row][col];
	if (nextChar == '|' || nextChar == '=') {
		return nextChar;
	}
	currentColOfHero += 1;
	return nextChar;
}

void Map::deadMonster() {
	map[currentRowOfHero][currentColOfHero] = '*';
}
