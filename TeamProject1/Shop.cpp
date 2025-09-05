
#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"


void Shop::BuyItem(Item* item, Character* character, Inventory* inventory)	//아이템과 캐릭터의 클래스를 참조
{
	if (character->Getgold() >= item->GetPrice())	//골드가 가격이랑 같거나 더 클때
	{
		character->Spendgold(item->GetPrice());	//골드 차감
		inventory->AddItem(item);					//아이템 추가, AddItem은 추후 인벤토리 클래스에서 연결 예정
		cout << item->GetName() << "구매 완료!" << endl;
	}
	else {											//골드가 충분하지 않을 때
		cout << "골드가 부족합니다!" << endl;
	}
}
void Shop::SellItem(Item* item, Character* character, Inventory* inventory)	//아이템과 캐릭터의 클래스를 참조
{
	if (inventory->GetItemCount(item) > 0)						//아이템을 가지고 있으면 동작
	{
		character->Addgold(item->GetPrice());		//아이템의 가격만큼 골드가 증가
		inventory->RemoveItem(item);					//인벤토리에서 아이템 삭제, 추후 인벤토리 클래스에서 DeleteItem 연결 예정
		cout << item->GetName() << "판매 완료!" << endl;
	}
	else {
		cout << "아이템이 없습니다!" << endl;
	}
}
void Shop::PriceCheck(Item* item)
{
	cout << item->GetName() << "가격 : " << item->GetPrice() << "골드" << endl;
}
int Shop::GetItemCount(Item* item, Inventory* inventory)
{
	return inventory->GetItemCount(item);
}
void Shop::ShowItems(Inventory* inventory)
{
	cout << "상점에 오신 것을 환영합니다!" << endl;

	for (auto& item : shopitems)
	{
		cout << item->GetName()
			<< " : " << item->GetPrice()
			<< "골드"
			<< " / 재고" << inventory->GetItemCount(item)
			<< "개\n";
	}
}

