#pragma once
#include <string>
#include <vector>

class Character;
class Item;
class Inventory;

class Shop
{
private:
	void BuyItem(Character* character, Inventory* inventory, Item* item);	//������ ����
	void SellItem(Character* character, Inventory* inventory, Item* item);	//������ �Ǹ�
	std::vector<Item*> shopitems;	//������ ����Ʈ

public:
	Shop();
	~Shop();
	void ShowItems(Inventory* inventory, Character* character);
};
