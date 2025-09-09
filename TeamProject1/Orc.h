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
	int GetExperience() override;
	int GetGold() override;

	void TakeDamage(int damage) override;
	bool IsDead() override;
	void DropItem(Inventory* inventory) override;

};

