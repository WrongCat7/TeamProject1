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

	experience = 50;

	uniform_int_distribution<int> randomgold(10, 20);
	gold = randomgold(gen);
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
	return experience;
}

int Slime::GetGold()
{
	return gold;
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
		cout << "�������� óġ������ �������� ������ �ʾҽ��ϴ�....." << endl;
	}

}