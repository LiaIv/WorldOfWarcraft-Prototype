#include "Player.h"

void Player::Free()
{
	delete chosenHero;
}

void Player::CopyFrom(const Player & other)
{
	this->name = other.name;
	this->chosenHero = other.chosenHero;
	this->countOfWins = other.countOfWins;
	for (int i = 0; i < 2; i++) {
		this->currentCondinates[i] = other.currentCondinates[i];
	}
}

String Player::getName() {
	return name;
}

void Player::setName(char* name) {
	this->name = name;
}

Hero * Player::getHero()
{
	return chosenHero;
}

Player::Player() {
	this->name = "unknown";
	countOfWins = 0;
	currentCondinates[0, 0];
}

Player::Player(String name, int heroNumber) {
	this->name = name;
	Free();
	switch (heroNumber)
	{
	case 1:
		chosenHero = new Warrior();
		break;
	case 2:
		chosenHero = new Mage();
		break;
	case 3:
		chosenHero = new Paladin();
		break;
	default:
		cout << " Enter valid hero number!" << endl;
		break;
	}
	this->countOfWins = 0;
	this->currentCondinates[0, 0];
}

Player & Player::operator=(const Player & other)
{
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
