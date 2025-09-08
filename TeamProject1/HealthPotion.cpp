#include "HealthPotion.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;


HealthPotion::HealthPotion():Item("HealthPotion", 20)
{
	healthrestore = 50;
}

string HealthPotion::GetName()
{
	return name;
}

int HealthPotion::GetPrice()
{
	return price;
}

void HealthPotion::Use(Character* character)
{
	string CharacterName = character->GetName();
	int newHP = character->GetHP() += healthrestore;
	if (newHP > character->GetmaxHP()) newHP = character->GetmaxHP();
	character->SetHP(newHP);
	cout  << character->Getname()<< "ê° " << name << "ì ì¬ì©íìµëë¤." << character->Getname()<< "ì " << "ì²´ë ¥:" << character->GetHP() << endl;

}

//주석1
