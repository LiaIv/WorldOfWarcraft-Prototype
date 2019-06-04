#include <iostream>
#include <stdlib.h>
#include "StartingScreen.h"
using namespace std;


StartingScreen::StartingScreen() {
	welcomeMsg();
}

void StartingScreen::welcomeMsg() {
	cout << "\n W O R L D   O F  W A R C R A F T\n\n";
	cout << " Welcome to the game!\n";
	printCommands();
}

void StartingScreen::printCommands() {
	cout << "\n 1 = Start new game\n 2 = Load game\n 3 = List players\n 4 = Exit\n" << endl;

	int commandNumber = 0;
	cout << " Please select a command: ";
	cin >> commandNumber;
	system("CLS");
	cout << endl;
	switch (commandNumber) {
	case 1: cout << " Starting game!\n" << endl;
		startGame();
		break;
	case 2:
		loadGame();
		break;
	case 3:
		listPlayers();
		break;
	case 4: return;
		break;
	default: cout << " Enter a valid number of command!" << endl;
		printCommands();
		break;
	}
}

void StartingScreen::printHeroTypes() {
	cout << "\n Heroes:\n 1 = Warrior\n 2 = Mage\n 3 = Paladin\n\n 4 = Back to menu\n" << endl;
}

void StartingScreen::startGame() {
	String playerName;
	cin.ignore();
	cout << " Enter player name: ";
	cin >> playerName;
	printHeroTypes();
	int heroNum;
	cout << " It's your time to choose a hero: ";
	cin >> heroNum;
	system("CLS");
	if (heroNum >= 1 && heroNum < 4) {
		Gameplay game(playerName, heroNum);
	}
	else if (heroNum == 4) {
		printCommands();
	}
	else {
		cout << "\n Enter a valid number of hero!\n" << endl;
		startGame();
	}
}

void StartingScreen::loadGame() {
	String playerName;
	cout << " Enter player name: ";
	cin.ignore();
	cin >> playerName;
	cout << " Loading the game of " << playerName << "...\n";

	fstream ioFile;
	ioFile.open("games.txt", ios::app | ios::binary);
	if (!ioFile) {
		cerr << "File couldn’t be opened!\n";
		return;
	}


	ioFile.close();
}

void StartingScreen::listPlayers() {
	cout << " Players list: " << endl;
	//?
}
