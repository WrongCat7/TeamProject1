#include "AttackBoost.h"
#include <iostream>
#include "Character.h"
using namespace std;

AttackBoost::AttackBoost()
{
	name = "AttackBoost";
	attackincreasr = 10;
}

string AttackBoost::GetName()
{
	return name;
}

void AttackBoost::Use(Character* character)
{
	string CharacterName = character->name;
	character->GetAttack() += attackincreasr;
	character->SetAttack();
	cout << name << "�� ����߽��ϴ�." <<  "���ݷ�:" << character->GetAttack() << endl;
}