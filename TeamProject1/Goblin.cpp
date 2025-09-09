#include <iostream>
#include <random>
#include "Goblin.h"
#include "MonsterBase.h"
#include "Inventory.h"

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
void Goblin::DropItem(Inventory* inventory)
{
	Item* randomitem = inventory->RandomItem();
	inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "�� ����߽��ϴ�!" << endl;
}