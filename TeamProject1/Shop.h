#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"
#include "Inventory.h"

class Shop
{
private:
	string name;	//���� �̸�
	vector<Item*> shopitems;	//������ ����Ʈ, ���� ������ Ŭ������ ����
	int maxItems;	//�������� �ִ� ���� ��
public:
	Shop(string n) : name(n), maxItems(100) {}
	void BuyItem(Item* item, Character* character, Inventory* inventory);	//������ ����
	void PriceCheck(Item* item);
	void ShowItems(Inventory* inventory);	//��ǰ ��ü ��ϰ� ��� ����һ��̶� �Ű����� ����.
	int GetItemCount(Item* item, Inventory* inventory);
	void SellItem(Item* item, Character* character, Inventory* inventory);	//������ �Ǹ�
};
