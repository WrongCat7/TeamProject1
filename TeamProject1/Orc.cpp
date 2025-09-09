#include <iostream>
#include <random>
#include "Orc.h"
#include "MonsterBase.h"
#include "Inventory.h"

using namespace std;


Orc::Orc(int level)
{
	name = "오크";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum1(20, 30);

	HP = level * randomnum1(gen);

	uniform_int_distribution<int> randomnum2(5, 10);

	attack = level * randomnum2(gen);
}

string Orc::GetName()
{
	return name;
}

int Orc::GetHP()
{
	return HP;
}

int Orc::GetAttack()
{
	return attack;
}

int Orc::GetExperience()
{
	int experience = 50;
	return experience;
}

int Orc::GetGold()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomgold(10, 20);
	return randomgold(gen);
}

void Orc::TakeDamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " 체력: " << HP << endl;
}

bool  Orc::IsDead() // 사망 여부 확인을 위한 함수
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
void Orc::DropItem(Inventory* inventory)
{
	Item* randomitem = inventory->RandomItem();
	inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "을 드롭했습니다!" << endl;
}