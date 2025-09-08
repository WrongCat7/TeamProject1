#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
#include "Inventory.h"


void Shop::BuyItem(Item* item, Character* character, Inventory* inventory)
{
	if (character->GetGold() >= item->GetPrice())	//골드가 충분하면
	{
		character->SetGold(character->GetGold() - item->GetPrice());	//골드 차감, 현재골드 - 아이템 가격 = 남는 골드
		inventory->AddItem(item);					//인벤토리에 아이템 추가 
		cout << item->GetName() << "구매 완료!" << endl;
	}
	else {											//골드가 충분하지 않을 때
		cout << "골드가 부족합니다!" << endl;
	}
}
void Shop::SellItem(Item* item, Character* character, Inventory* inventory)	//아이템과 캐릭터의 클래스를 참조
{
	if (inventory->GetItemCount(item) > 0)	//아이템 재고가 남아있을때
	{
		character->SetGold(character->GetGold() + item->GetPrice());		//현재 골드(Getgold)에 아이템 가격(GetPrice)를 더해서 Setgold의 갱신
		inventory->RemoveItem(item);					//인벤토리에 있던 아이템 삭제
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

