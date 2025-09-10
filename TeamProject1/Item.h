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
	virtual int GetCount() = 0;
	virtual void SetCount(int num) = 0;

};
//¡÷ºÆ1

