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
	cout  << character->Getname()<< "가 " << name << "을 사용했습니다." << character->Getname()<< "의 " << "체력:" << character->GetHP() << endl;
}


