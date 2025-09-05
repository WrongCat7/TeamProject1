#pragma once
#include <vector>
#include "Item.h"

//인벤토리 : 소지여부, 추가 / 제거, 재고 수량
class Character;

class Inventory 
{
private:
	vector<Item*> items;

public:
	
	void AddItem(Item* item);

	void UseItem(int index, Character* character);

	void DisplayItems();

};

