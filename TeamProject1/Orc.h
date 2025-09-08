#pragma once
#include "MonsterBase.h"

class Inventory;

class Orc : public Monster
{
private:
	string name;
	int HP;
	int attack;

public:
	Orc(int level);

	string GetName() override;
	int GetHP() override;
	int GetAttack() override;

	void TakeDamage(int damage) override;
	bool Isdead() override;
	void DropItem(Inventory& inventory) override;

};

