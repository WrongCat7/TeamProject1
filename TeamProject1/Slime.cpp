#include <iostream>
#include <random>
#include "Slime.h"
#include "MonsterBase.h"

using namespace std;


Slime::Skeleton(int level)
{
	name = "슬라임";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum1(20, 30);

	HP = level * randomnum1(gen);

	uniform_int_distribution<int> randomnum2(5, 10);

	attack = level * randomnum2(gen);
}

string Slime::GetName()
{
	return name;
}

int Slime::GetHP()
{
	return HP;
}

int Slime::GetAttack()
{
	return attack;
}


void Slime::TakeDamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " 체력: " << HP << endl;
}

bool  Slime::Isdead() // 사망 여부 확인을 위한 함수
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
void Slime::DropItem(Inventory& inventory)
{
	Item* randomitem = Inventory->RandomItem();
	Inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "을 드롭했습니다!" << endl;
}