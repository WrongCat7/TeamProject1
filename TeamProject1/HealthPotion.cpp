#include "HealthPotion.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;


HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	price = 20;
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
	int newHP = character->GetHP() + 50;
	if (newHP > character->GetMaxHP()) newHP = character->GetMaxHP();
	character->SetHP(newHP);
	cout  << character->GetName()<< " 이" << name << "을 사용했습니다." << character->GetName()<< " 의" << " 체력: " << character->GetHP() << endl;

}

//주석2
