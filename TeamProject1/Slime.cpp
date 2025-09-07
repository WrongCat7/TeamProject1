#include <iostream>
#include <random>
#include "Slime.h"
#include "MonsterBase.h"

using namespace std;


Slime::Skeleton(int level)
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


void Slime::TakeDamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " ü��: " << HP << endl;
}

bool  Slime::Isdead() // ��� ���� Ȯ���� ���� �Լ�
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
void Slime::DropItem(Inventory& inventory)
{
	Item* randomitem = Inventory->RandomItem();
	Inventory->AddItem(randomitem);

	cout << randomitem->GetName() << "�� ����߽��ϴ�!" << endl;
}