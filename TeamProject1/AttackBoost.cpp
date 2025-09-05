#include "AttackBoost.h"
#include <iostream>
#include "Character.h"
using namespace std;

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
	cout << character->Getname() << "ê° " << name << "ì ì¬ì©íìµëë¤." << character->Getname() << "ì " << "ê³µê²©ë ¥:" << character->GetAttack() << endl;

}