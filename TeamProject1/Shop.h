#pragma once
#include <string>
#include <vector>
using namespace std;

class Shop
{
private:
	string name;	//상점 이름
	vector<Item> item;	//아이템 리스트, 추후 아이템 클래스와 연동
	int MaxItems;	//아이템의 최대 소지 수
public:
	Shop(string N) : name(N) {}
	void BuyItem(string ItmeName, float gold);	//아이템 구매
	void PriceCheck(string ItemName);
	void ShowItems();	//상품 전체 목록과 재고를 출력할뿐이라 매개변수 없음.
	void GetItemCount(string ItemName);
	void SellItem(string ItemName);	//아이템 판매
};
