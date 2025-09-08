#pragma once
#include <string>
#include <vector>

class Inventory;
class Item;
class Character;

class Shop
{
private:
	string name;	//상점 이름
	vector<Item*> shopitems;	//아이템 리스트
	int maxitems;	//아이템의 최대 소지 수
public:
	Shop(string n) : name(n), maxitems(100) {}
	void BuyItem(Item* item, Character* character, Inventory* inventory);	//아이템 구매
	void PriceCheck(Item* item);
	void ShowItems(Inventory* inventory);	//상품 전체 목록과 재고를 출력할뿐이라 매개변수 없음.
	int GetItemCount(Item* item, Inventory* inventory);
	void SellItem(Item* item, Character* character, Inventory* inventory);	//아이템 판매
};
