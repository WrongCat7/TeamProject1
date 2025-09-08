#pragma once
#include <string>
#include <vector>

class Inventory;
class Item;
class Character;

class Shop
{
private:
	string name;	//���� �̸�
	vector<Item*> shopitems;	//������ ����Ʈ
	int maxitems;	//�������� �ִ� ���� ��
public:
	Shop(string n) : name(n), maxitems(100) {}
	void BuyItem(Item* item, Character* character, Inventory* inventory);	//������ ����
	void PriceCheck(Item* item);
	void ShowItems(Inventory* inventory);	//��ǰ ��ü ��ϰ� ��� ����һ��̶� �Ű����� ����.
	int GetItemCount(Item* item, Inventory* inventory);
	void SellItem(Item* item, Character* character, Inventory* inventory);	//������ �Ǹ�
};
