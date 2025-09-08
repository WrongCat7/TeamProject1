#pragma once
#include <iostream>
#include "Character.h"

using namespace std;

class Item
{

public:

	virtual string GetName() = 0;
	virtual void Use(Character* character) = 0;

};


