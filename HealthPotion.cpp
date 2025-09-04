#include "HealthPotion.h"
#include <iostream>
#include "Character.h"
using namespace std;


HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	healthRestore = 50;
}

string HealthPotion::GetName()
{
	return name;
}

void HealthPotion::Use(Character* character)
{
	character->GetHP() += healthRestore;
	character->SetHP();
	cout  << name << "�� ����߽��ϴ�."  << "ü��:" << character->GetHP() << endl;
}


