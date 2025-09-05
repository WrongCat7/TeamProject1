#include "AttackBoost.h"
#include <iostream>
#include "Character.h"
using namespace std;

AttackBoost::AttackBoost():Item("AttackBoos", 20)
{
	attackincreasr = 10;
}

string AttackBoost::GetName()
{
	return name;
}

void AttackBoost::Use(Character* character)
{
	string CharacterName = character->Getname();
	int newattack = character->GetAttack() += attackincreasr;
	character->SetAttack(newattack);
	cout << character->Getname() << "가 " << name << "을 사용했습니다." << character->Getname() << "의 " << "공격력:" << character->GetAttack() << endl;
}