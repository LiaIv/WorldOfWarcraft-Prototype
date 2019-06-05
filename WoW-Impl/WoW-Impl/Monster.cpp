#include <iostream>
#include "Monster.h"
using namespace std;

String Monster::getName() {
	return name;
}
void Monster::setName(String name) {
	this->name = name;
}
double Monster::getHp() {
	return hp;
}
void Monster::setHp(double hp) {
	this->hp = hp;
}

Monster::Monster() {
	name = " ";
	hp = 10;
}

bool Monster::isAlive() {
	return hp;
}

Goblin::Goblin() : Monster() {
	setName("Goblin");
	setHp(10);
}

double Goblin::attackPower(Hero & enemy) {
	cout << "\n ~ " << getName() << " attacks!\n ";
	return 3 + 0.1*enemy.getIntellect();
}

double Goblin::defend(double damage) {
	cout << "\n ~ " << getName() << " defends itself! \n";
	return damage;
}

Dragonkin::Dragonkin() : Monster() {
	this->counterDefend = 0;
	setName("Dragonkin");
	setHp(20);
}

double Dragonkin::attackPower(Hero & enemy)
{
	cout << "\n ~ " << getName() << " attacks!\n ";
	return 8;
}

double Dragonkin::defend(double damage) {
	cout << "\n ~ " << getName() << " defends itself! \n";
	if (counterDefend % 3 == 0) {
		damage -= 10;
		if (damage < 0) {
			damage = 0;
		}
	}
	return damage;
}

DeathKnight::DeathKnight() : Monster() {
	this->isLikeGoblin = true;
	setName("Death Knight");
	setHp(20);
	counterDefend = 0;
}

double DeathKnight::attackPower(Hero & enemy) {
	cout << "\n ~ " << getName() << " attacks!\n ";
	if (isLikeGoblin) {
		isLikeGoblin = false;
		return 3 + 0.1*enemy.getIntellect();
	}
	isLikeGoblin = true;
	return 8;
}

double DeathKnight::defend(double damage)
{
	cout << "\n ~ " << getName() << " defends itself! \n";
	if (counterDefend % 3 == 0) {
		damage -= 10;
		if (damage < 0) {
			damage = 0;
		}
	}
	return damage;
}
