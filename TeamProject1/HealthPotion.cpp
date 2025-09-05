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
	string CharacterName = character->Getname();
	int newHP = character->GetHP() += healthRestore;
	if (newHP > character->GetmaxHP()) newHP = character->GetmaxHP();
	character->SetHP(newHP);
	cout  << character->Getname()<< "ê° " << name << "ì ì¬ì©íìµëë¤." << character->Getname()<< "ì " << "ì²´ë ¥:" << character->GetHP() << endl;
}


