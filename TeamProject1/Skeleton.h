#pragma once
#include "MonsterBase.h"

class Skeleton : public Monster
{
private:
	string name;
	int HP;
	int ATK;

public:
	Skeleton(int level);

	string GetName() override;
	int GetHP() override;
	int GetATK() override;

	void Takedamage(int damage) override;
	bool Isdead() override;
	void dropitem() override; //구현필요

};
