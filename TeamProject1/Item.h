#pragma once
#include <iostream>

class Character;
using namespace std;

class Item
{
private:

public:

	virtual~Item() = default;

	virtual string GetName() = 0;
	virtual void Use(Character* character) = 0;
	virtual int GetPrice() = 0;
	void ItemsName(int choice);
};
//¡÷ºÆ1

