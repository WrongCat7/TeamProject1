#pragma once
#include "MonsterBase.h"

class Inventory;

class Skeleton : public Monster
{
private:
	string name;
	int HP;
	int attack;

public:
	Skeleton(int level);

	string GetName() override;
	int GetHP() override;
	int GetAttack() override;

	void TakeDamage(int damage) override;
	bool Isdead() override;
	void DropItem(Inventory& inventory) override;

};
