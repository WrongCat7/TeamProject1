#include "Shop.h"
#include <iostream>


void Shop::BuyItem(string ItemName, float Money)
{
	cout << ItemName << " 구매" << endl;
}
void Shop::SellItem(string ItemName)
{
	cout << ItemName << " 판매" << endl;
}
void Shop::PriceCheck(string ItemName)
{
	cout << ItemName << "가격 : " << endl;
}
void Shop::GetItemCount(string ItemName)
{
	cout << ItemName << " 수량 : " << endl;
}
void Shop::ShowItems()
{
	//추후 연결예정
}

