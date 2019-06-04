#pragma once
#include <fstream>
#include "Gameplay.h"
using namespace std;

class StartingScreen {
public:
	StartingScreen();
	void welcomeMsg();
	void printCommands();
	void printHeroTypes();
	void startGame();
	void loadGame();
	void listPlayers();
};
