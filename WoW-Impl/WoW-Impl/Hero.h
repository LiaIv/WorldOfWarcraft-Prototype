#pragma once
#include <iostream>
#include "String.h"
using namespace std;

const int WARRIOR_START_STRENGTH = 13;
const int WARRIOR_START_INTELLECT = 2;
const int MAGE_START_STRENGTH = 4;
const int MAGE_START_INTELLECT = 11;
const int PALADIN_START_STRENGTH = 9;
const int PALADIN_START_INTELLECT = 6;


class Hero {
	String name;
	double hp;
	int strength;
	int intellect;
	int level;
	int killedMonsters;
public:
	String getName() const;
	void setName(const String name);
	double getHp() const;
	void setHp(double hp);
	int getStrength() const;
	void setStrength(int strength);
	int getIntellect() const;
	void setIntellect(int intellect);
	int getLevel() const;
	void setLevel(int level);

	Hero();
	virtual ~Hero() = 0;
	virtual double getAttackPower() = 0;
	virtual void defend();
	virtual void endOfFight();

	bool isAlive();
	virtual void levelUp(int killedMonsters);
};

//1st type Hero - Warrior (declarations)
class Warrior : public Hero {
	int rage;
public:
	Warrior();
	double getAttackPower();
	void defend();
	void levelUp(int killedMonsters);
};


//2nd type Hero - Mage (declarations)
class Mage : public Hero {
	int mana;
public:
	Mage();
	double getAttackPower();
	void endOfFight();
	void levelUp(int killedMonsters);
};


//3rd type Hero - Paladin (declarations)
class Paladin : public Hero {
	int countAttacks;
public:
	Paladin();
	double getAttackPower();
	void levelUp(int killedMonsters);
};
