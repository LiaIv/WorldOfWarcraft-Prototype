#include <iostream>
#include "Hero.h"
using namespace std;

//Hero getters and setters

String Hero::getName() const {
	return name;
}

void Hero::setName(const String name) {
	this->name = name;
}

double Hero::getHp() const {
	return hp;
}

void Hero::setHp(double hp) {
	this->hp = hp;
}

int Hero::getStrength() const {
	return strength;
}

void Hero::setStrength(int strength) {
	this->strength = strength;
}

int Hero::getIntellect() const {
	return intellect;
}

void Hero::setIntellect(int intellect) {
	this->intellect = intellect;
}

int Hero::getLevel() const {
	return level;
}

void Hero::setLevel(int level) {
	this->level = level;
}

Hero::~Hero() {}


void Hero::endOfFight() {
	killedMonsters += 1;
	levelUp(killedMonsters);
}

//Hero default constructor
Hero::Hero() {
	level = 0;
	hp = 100;
	killedMonsters = 0;
}

bool Hero::isAlive() {
	return hp;
}

void Hero::levelUp(int killedMonsters) {
	if (killedMonsters == (2 ^ level)) {
		hp += (hp * 0.1);
		level++;
	}
}


//1st type Hero - Warrior (definitions)
Warrior::Warrior() : Hero() {
	cout << "\n You are now a Warrior!" << endl;
	setName("Warrior");
	setStrength(WARRIOR_START_STRENGTH);
	setIntellect(WARRIOR_START_INTELLECT);
	rage = 100;
}

void Warrior::defend() {
	rage += 3;
}

void Warrior::levelUp(int killedMonsters) {
	if (killedMonsters == (2 ^ getLevel())) {
		setStrength(getStrength() + WARRIOR_START_STRENGTH / 3);
		setIntellect(getIntellect() + WARRIOR_START_INTELLECT / 3);
	}
}

double Warrior::getAttackPower() {
	double ragePower = rage / 5;
	if (rage == 100) {
		rage = 0;
	}
	rage += 2;
	return getStrength() + 0.3*getIntellect() + (getStrength() + 0.3*getIntellect())*(ragePower / 100);
}


//2nd type Hero - Mage (definitions)
Mage::Mage() : Hero() {
	cout << "\n You are now a Mage!" << endl;
	setName("Mage");
	setStrength(MAGE_START_STRENGTH);
	setIntellect(MAGE_START_INTELLECT);
	mana = 100;
}

double Mage::getAttackPower() {
	double power = getIntellect() + (mana / 100) * 3;
	mana -= 10;
	return power;
}

void Mage::endOfFight() {
	mana = 100;
}

void Mage::levelUp(int killedMonsters) {
	if (killedMonsters == (2 ^ getLevel())) {
		setStrength(getStrength() + MAGE_START_STRENGTH / 3);
		setIntellect(getIntellect() + MAGE_START_INTELLECT / 3);
	}
}



//3rd type Hero - Paladin (definitions)
Paladin::Paladin() : Hero() {
	cout << "\n You are now a Paladin!" << endl;
	setName("Palading");
	setStrength(9);
	setIntellect(6);
	countAttacks = 0;
}

double Paladin::getAttackPower() {
	double power = 0.5*getStrength() + 0.5*getIntellect();
	if ((countAttacks + 1) % 3 == 0) {
		power += power * 0.5;
	}
	countAttacks++;
	return power;
}

void Paladin::levelUp(int killedMonsters) {
	if (killedMonsters == (2 ^ getLevel())) {
		setStrength(getStrength() + PALADIN_START_STRENGTH / 3);
		setIntellect(getIntellect() + PALADIN_START_INTELLECT / 3);
	}
}

