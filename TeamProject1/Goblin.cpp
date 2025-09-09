#include <iostream>
#include <random>
#include "Goblin.h"
#include "MonsterBase.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;


Goblin::Goblin(int level)
{
	name = "고블린";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum1(20, 30);

	HP = level * randomnum1(gen);

	uniform_int_distribution<int> randomnum2(5, 10);

	attack = level * randomnum2(gen);

	experience = 50;

	uniform_int_distribution<int> randomgold(10, 20);
	gold = randomgold(gen);

}

string Goblin::GetName()
{
	return name;
}

int Goblin::GetHP()
{
	return HP;
}

int Goblin::GetAttack()
{
	return attack;
}

int Goblin::GetExperience()
{
	return experience;
}

int Goblin::GetGold()
{
	return gold;
}

void Goblin::TakeDamage(int damage)
{
	HP -= damage;
}

bool  Goblin::IsDead() // 사망 여부 확인을 위한 함수
{
	// HP에 데미지 적용 후 액션
	if (HP <= 0)
	{
		HP = 0;
		return true;
	}
	else
	{
		return false;
	}
}

//구현필요
void Goblin::DropItem(Character* player, Inventory* inventory)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum(0, 100);

	if (randomnum(gen) > 50)
	{
		Item* randomitem = inventory->RandomItem();
		randomitem->Use(player);

		cout << randomitem->GetName() << "을 드롭하고 바로 사용했습니다!" << endl;
	}
	else
	{
		cout << "고블린을 처치했지만 아이템은 나오지 않았습니다....." << endl;
	}

}