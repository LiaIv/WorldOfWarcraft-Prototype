#pragma once
#include <iostream>
#include "Hero.h"

using namespace std;

class Monster {
	String name;
	double hp;
public:
	String getName();
	void setName(String name);
	double getHp();
	void setHp(double hp);
	Monster();
	bool isAlive();
	virtual ~Monster() {}
	virtual double attackPower(Hero& enemy) = 0;
	virtual double defend(double damage) = 0;
};

class Goblin : public Monster {
public:
	Goblin();
	double attackPower(Hero& enemy);
	double defend(double damage);
};

class Dragonkin : public Monster {
	short counterDefend;
public:
	Dragonkin();
	double attackPower(Hero& enemy);
	double defend(double damage);
};


class DeathKnight : public Monster {
	bool isLikeGoblin;
	short counterDefend;
public:
	DeathKnight();
	double attackPower(Hero& enemy);
	double defend(double damage);
};

