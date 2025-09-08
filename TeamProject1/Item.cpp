#include "Item.h"
#include <iostream>
#include "Character.h"

void Item::ItemsName(int choice)
{
	Item* shopitems;
	switch (choice)
	{
	case 0: shopitems = new HealthPotion(); break;
	case 1: shopitems = new AttackBoost(); break;
	}

	return shopitems;
}

//주석1