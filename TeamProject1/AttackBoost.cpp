#include "AttackBoost.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;

AttackBoost::AttackBoost()
{
	name = "AttackBoost";
	price = 20;
	count = 0;
}

string AttackBoost::GetName()
{
	return name;
}

int AttackBoost::GetPrice()
{
	return price;
}

void AttackBoost::Use(Character* character)
{
	string CharacterName = character->GetName();
	int newattack = character->GetAttack() + 10;
	character->SetAttack(newattack);
	cout << character->GetName() << " 이" << name << "을 사용했습니다." << character->GetName() << " 의" << " 공격력: " << character->GetAttack() << endl;
}
//주석2

int AttackBoost::GetCount() {
	return count;
}
void AttackBoost::SetCount(int num) {
	count += num;
}