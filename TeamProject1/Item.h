#pragma once
#include <iostream>

class Character;
using namespace std;

class Item
{

public:

	virtual string GetName() = 0;
	virtual void Use(Character* character) = 0;

};


