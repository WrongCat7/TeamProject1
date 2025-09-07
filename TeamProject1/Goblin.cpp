#include <iostream>
#include <random>
#include "Goblin.h"
#include "MonsterBase.h"

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
	if (HP < 0) HP = 0;
	cout << name << " ü��: " << HP << endl;
}

bool  Goblin::Isdead() // ��� ���� Ȯ���� ���� �Լ�
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
void Goblin::DropItem(Inventory& inventory)
{
	Item* randomitem = Inventory->RandomItem();
	Inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "�� ����߽��ϴ�!" << endl;
}