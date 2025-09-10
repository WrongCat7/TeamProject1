#pragma once
#include <string>
#include <vector>

class Character;
class Item;
class Inventory;

class Shop
{
private:
	void BuyItem(Character* character, Inventory* inventory, Item* item);	//아이템 구매
	void SellItem(Character* character, Inventory* inventory, Item* item);	//아이템 판매
	std::vector<Item*> shopitems;	//아이템 리스트

public:
	Shop();
	~Shop();
	void ShowItems(Inventory* inventory, Character* character);
};
