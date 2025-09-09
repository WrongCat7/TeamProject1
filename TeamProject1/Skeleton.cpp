#include <iostream>
#include <random>
#include "Skeleton.h"
#include "MonsterBase.h"
#include "Inventory.h"

using namespace std;


Skeleton::Skeleton(int level)
{
	name = "스켈레톤";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum1(20, 30);
	
	HP = level * randomnum1(gen);

	uniform_int_distribution<int> randomnum2(5, 10);

	attack = level* randomnum2(gen);
}

string Skeleton::GetName()
{
	return name;
}

int Skeleton::GetHP()
{
	return HP;
}

int Skeleton::GetAttack()
{
	return attack;
}

int Skeleton::GetExperience()
{
	int experience = 50;
	return experience;
}

int Skeleton::GetGold()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomgold(10, 20);
	return randomgold(gen);
}


void Skeleton::TakeDamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " 체력: " << HP << endl;
}

bool  Skeleton::IsDead() // 사망 여부 확인을 위한 함수
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
void Skeleton::DropItem(Inventory* inventory)
{
	Item* randomitem = inventory->RandomItem();
	inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "을 드롭했습니다!" << endl;
}