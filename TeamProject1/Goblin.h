#pragma once
#include "MonsterBase.h"

class Goblin : public Monster
{
private:
	string name;
	int HP;
	int attack;

public:
	Goblin(int level);

	string GetName() override;
	int GetHP() override;
	int GetAttack() override;

	void TakeDamage(int damage) override;
	bool Isdead() override;
	void DropItem(Inventory& inventory) override;

};
