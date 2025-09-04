#include "HealthPotion.h"
#include <iostream>
//#include "Character.h"
using namespace std;

// �������� ü�� +50 �Ǵ� ���ݷ� +10�� ���ִ� ���� ȿ��!
// ���� �߿��� "�̷� �� ������!" �ϰ� �����ϰ� ���˴ϴ�

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	healthRestore = 50;
}

string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	string CharacterName = character->name;
	character->health += healthRestore;
	cout << CharacterName << "��" << name << "�� ����߽��ϴ�." << CharacterName << "ü��:" << character->health << endl;
}


