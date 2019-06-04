#include <iostream>
#include "Gameplay.h"
using namespace std;

//Constructor of Gameplay 
Gameplay::Gameplay(String name, int heroNum) {
	Player currentPlayer(name, heroNum);
	player = currentPlayer;
	printMovementCommands();
}


void Gameplay::printMovementCommands() {
	int direction;
	bool keepMoving = true;
	do {
		map.printMap();
		cout << " Select direction: ";
		cin >> direction;
		system("CLS");
		keepMoving = move(direction);
	} while (direction >= 1 && direction < 5);
	if (direction == 5) {
		saveGame();
		system("CLS");
		StartingScreen sc;
		return;
	}
	else if (direction == 6 || !keepMoving) {
		system("CLS");
		StartingScreen sc;
		return;
	}
	else {
		printMovementCommands();
	}
}

bool Gameplay::move(int movementCommand) {
	char nextChar = ' ';
	switch (movementCommand)
	{
	case 1: nextChar = map.moveUp();
		break;
	case 2: nextChar = map.moveDown();
		break;
	case 3: nextChar = map.moveLeft();
		break;
	case 4: nextChar = map.moveRight();
		break;
	}

	if (nextChar == ' ') {
		return true;
	}
	else if (nextChar == 'G') {
		Goblin enemy;
		fight(*(player.getHero()), enemy);
	}
	else if (nextChar == 'D') {
		Dragonkin enemy;
		fight(*(player.getHero()), enemy);
	}
	else if (nextChar == 'K') {
		DeathKnight enemy;
		fight(*(player.getHero()), enemy);
	}
	else if (nextChar == '?') {
		cout << "\n Wrong direction -> out of maze!\n" << endl;
	}
	else if (nextChar == '!') {
		winGame();
		return false;
	}
	else {
		cout << "\n Wrong direction -> there is a wall!\n" << endl;
	}
	return true;
}


//fight methods

void Gameplay::fight(Hero & hero, Monster & monster) {
	cout << "\n A fight against " << monster.getName() << " has started!\n\n";
	while (hero.isAlive() && monster.isAlive()) {
		fightCommmand('f');
		monster.setHp(monster.getHp() - monster.defend(hero.getAttackPower()));
		if (monster.getHp() < 0) {
			monster.setHp(0);
			cout << "\n " << monster.getName() << " died!\n\n";
			system("pause");
		}
		if (monster.isAlive()) {
			hero.setHp(hero.getHp() - monster.attackPower(hero));
			fightCommmand('d');
			cout << "\n You defend yourself!\n";
			continue;
		}
		if (hero.getHp() < 0) {
			hero.setHp(0);
		}
	}
	endOfAttack(hero.isAlive(), monster.isAlive());
}



void Gameplay::fightCommmand(char attackOrDef) {
	String command;
	if (attackOrDef == 'f') {
		do {
			cout << "\n Type 'A' to attack ";
			cin >> command;
		} while (!(command == "A" || command == "a"));
	}
	else {
		do {
			cout << "\n Type 'D' to defend yourself ";
			cin >> command;
		} while (!(command == "D" || command == "d"));
	}
}

void Gameplay::endOfAttack(bool isAliveHero, bool isAliveMonster)
{
	if (isAliveHero) {
		cout << "\n You won this fight!\n\n";
		system("CLS");
		player.getHero()->endOfFight();
		map.deadMonster();
	}
	else {
		gameOver();
	}
}

void Gameplay::gameOver() {
	cout << "\n You died!\n" << endl;
	cout << " GAME OVER\n\n";
	system("pause");
	system("CLS");
}

void Gameplay::winGame() {
	cout << "\n Congratulations!\n YOU WON!\n\n";
	system("pause");
	system("CLS");
}

void Gameplay::saveGame() {
	ofstream ioFile;
	ofstream ioFilePlayers;
	ioFile.open("games.txt", ios::app | ios::binary);

	if (!ioFile) {
		cerr << "File couldn’t be opened!\n";
		return;
	}

	ioFilePlayers.open("players.txt", ios::app);

	if (!ioFile) {
		cerr << "File couldn’t be opened!\n";
		return;
	}

	ioFile.seekp(ios::end);


	ioFile.write((char*)&player, sizeof(Player));
	ioFile.write((char*)&map, sizeof(Map));

	ioFilePlayers.seekp(0, ios::end);

	if (ioFilePlayers.tellp() == 0) {
		ioFilePlayers << player.getName();
	}
	else {
		ioFilePlayers << ',' << endl << player.getName();
	}

	ioFilePlayers.close();
	ioFile.close();
	cout << "\n Game saved!\n\n ";
	system("pause");
}
