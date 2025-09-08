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

	void DisplayItems();

	void UseRandomItem(Character* character);

	int GetItemCount(Item* item);

	void RemoveItem(Item* item);

	Item* RandomItem();
};
//¡÷ºÆ2
