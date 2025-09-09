#include <iostream>
#include <random>
#include "Slime.h"
#include "MonsterBase.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;


Slime::Slime(int level)
{
	name = "������";

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

int Slime::GetExperience()
{
	int experience = 50;
	return experience;
}

int Slime::GetGold()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomgold(10, 20);
	return randomgold(gen);
}


void Slime::TakeDamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " ü��: " << HP << endl;
}

bool  Slime::IsDead() // ��� ���� Ȯ���� ���� �Լ�
{
	// HP�� ������ ���� �� �׼�
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

void Slime::DropItem(Character* player, Inventory* inventory)
{
	Item* randomitem = inventory->RandomItem();
	randomitem->Use(player);

	cout << randomitem->GetName() << "�� ����ϰ� �ٷ� ����߽��ϴ�!" << endl;
}