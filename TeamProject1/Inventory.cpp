#include "Inventory.h"
#include <iostream>
#include "Character.h"

using namespace std;


void Inventory::AddItem(Item* item)
{
	items.push_back(item);
}

void Inventory::UseItem(int index, Character* character)
{
	if ( index < 0 ) return;
	items[index]->Use(character);
	delete items[index];
	items.erase(items.begin() + index);
}

void Inventory::DisplayItems()
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << i << ": " << items[i]->GetName() << "  " << items[i]->GetPrice() << "골드" << endl;
	}
}