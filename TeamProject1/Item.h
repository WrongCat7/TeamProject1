#pragma once
#include <iostream>

class Character;
using namespace std;

class Item
{

protected:

	string name;
	int price;

public:

	Item(string name = "", int price = 0) :name(name), price(price) 
	{

	}
	virtual ~Item() {}

	virtual string GetName() = 0;
	virtual void Use(Character* character) = 0;

	int GetPrice() const { return price; }

};


