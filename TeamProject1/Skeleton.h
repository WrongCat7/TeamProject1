#pragma once
#include "MonsterBase.h"

class Character;
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
	int GetExperience() override;
	int GetGold() override;

	void TakeDamage(int damage) override;
	bool IsDead() override;
	void DropItem(Character* player, Inventory* inventory) override;

};
