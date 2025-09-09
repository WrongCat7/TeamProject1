#include <iostream>
#include <random>
#include "Goblin.h"
#include "MonsterBase.h"
#include "Inventory.h"

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
void Goblin::DropItem(Inventory* inventory)
{
	Item* randomitem = inventory->RandomItem();
	inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "을 드롭했습니다!" << endl;
}