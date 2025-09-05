#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"
#include "Inventory.h"

class Shop
{
private:
	string name;	//상점 이름
	vector<Item*> shopitems;	//아이템 리스트, 추후 아이템 클래스와 연동
	int maxItems;	//아이템의 최대 소지 수
public:
	Shop(string n) : name(n), maxItems(100) {}
	void BuyItem(Item* item, Character* character, Inventory* inventory);	//아이템 구매
	void PriceCheck(Item* item);
	void ShowItems(Inventory* inventory);	//상품 전체 목록과 재고를 출력할뿐이라 매개변수 없음.
	int GetItemCount(Item* item, Inventory* inventory);
	void SellItem(Item* item, Character* character, Inventory* inventory);	//아이템 판매
};
