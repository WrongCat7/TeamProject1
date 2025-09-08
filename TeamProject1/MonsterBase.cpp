#include <iostream>
#include <random>
#include "MonsterBase.h"
#include "Inventory.h"

int Monster::RandomGold()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomgold(10, 20);
	return randomgold;
}

