#include <iostream>
#include <random>
#include "Goblin.h"
#include "MonsterBase.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;


Goblin::Goblin(int level)
{
	name = "���";

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

bool  Goblin::IsDead() // ��� ���� Ȯ���� ���� �Լ�
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

//�����ʿ�
void Goblin::DropItem(Character* player, Inventory* inventory)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum(0, 100);

	if (randomnum(gen) > 50)
	{
		Item* randomitem = inventory->RandomItem();
		randomitem->Use(player);

		cout << randomitem->GetName() << "�� ����ϰ� �ٷ� ����߽��ϴ�!" << endl;
	}
	else
	{
		cout << "����� óġ������ �������� ������ �ʾҽ��ϴ�....." << endl;
	}

}