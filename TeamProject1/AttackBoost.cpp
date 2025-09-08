#include "AttackBoost.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;

AttackBoost::AttackBoost():Item("AttackBoost", 20)
{
	attackincrease = 10;
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
	int newattack = character->GetAttack() += attackincreasr;
	character->SetAttack(newattack);
	cout << character->GetName() << "ê° " << name << "ì ì¬ì©íìµëë¤." << character->GetName() << "ì " << "ê³µê²©ë ¥:" << character->GetAttack() << endl;
}
//주석1
