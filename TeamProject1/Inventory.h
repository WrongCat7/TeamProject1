#pragma once
#include <vector>
#include "Item.h"

class Character;

class Inventory
{
private:
	vector<Item*> items;

public:

	void AddItem(Item* item);

	void UseItem(int index, Character* character);

	int DisplayItems();

	void UseRandomItem(Character* character);

	int GetItemCount();

	void RemoveItem(Item* item);

	Item* RandomItem();

	Item* GetItem(int index);
};
//¡÷ºÆ2
