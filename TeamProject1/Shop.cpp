#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Inventory.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
using namespace std;


Shop::Shop()
{
	shopitems.push_back(new HealthPotion());
	shopitems.push_back(new AttackBoost());
}
Shop::~Shop()
{
	for (auto item : shopitems)
	{
		delete item;
	}
	shopitems.clear();
}

void Shop::ShowItems(Inventory* inventory, Character* character)
{
	int input = 0;

	while (true)
	{
		system("cls");
		cout << "----- 상점 -----" << endl;
		cout << "현재 보유 골드 : " << character->GetGold() << " 골드" << endl;
		cout << "1. 아이템 구매" << endl;
		cout << "2. 아이템 판매" << endl;
		cout << "3. 상점 나가기" << endl;
		cin >> input;

		if (input == 1)
		{
			cout << "구매 가능한 아이템 목록" << endl;
			for (int i = 0; i < shopitems.size(); i++)
			{
				cout << i << ":" << shopitems[i]->GetName()
					<< " " << shopitems[i]->GetPrice() << " 골드" << endl;
			}
			int buynum;
			cout << "번호를 입력하세요 (취소 3) : " << endl;
			cin >> buynum;

			if (buynum > 0 && buynum <= 3)
			{
				BuyItem(character, inventory, shopitems[buynum - 1]);
			}
			else
			{
				cout << "잘못된 입력입니다 1~4번 중에서 골라주세요." << endl;
			}
		}
		else if (input == 2)
		{
			if (inventory->GetItemCount() == 0)	//GetItemCount 함수를 전체 아이템 수를 반환하게 바꾸면 사용가능
			{
				cout << "판매할 아이템이 없습니다." << endl;
			}
			else
			{
				inventory->DisplayItems();
				int sellnum;
				cout << "번호를 입력하세요 (취소 3) : " << endl;
				cin >> sellnum;
				if (sellnum > 0 && sellnum <= 3)
				{
					SellItem(character, inventory, shopitems[sellnum - 1]);
				}
			}
		}
		else if (input == 3)
		{
			return;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
		}

		system("pause");
	}
}
void Shop::BuyItem(Character* character, Inventory* inventory, Item* item)
{
	if (character->GetGold() >= item->GetPrice())
	{
		character->SetGold(character->GetGold() - item->GetPrice());
		Item* newItem = nullptr;
		if (item->GetName() == "HealthPotion")
			newItem = new HealthPotion();
		else if (item->GetName() == "AttackBoost")
			newItem = new AttackBoost();
		inventory->AddItem(newItem);
		cout << item->GetName() << " 구매 완료!" << endl;
	}
	else
	{
		cout << "골드가 부족합니다!" << endl;
	}
}

void Shop::SellItem(Character* character, Inventory* inventory, Item* item)
{
	if (inventory->GetItemCount() > 0)
	{
		character->SetGold(character->GetGold() + item->GetPrice());
		inventory->RemoveItem(item);
		cout << item->GetName() << " 판매 완료! (+" << item->GetPrice() << " 골드)" << endl;
	}
	else
	{
		cout << "판매할 아이템이 없습니다!" << endl;
	}
}

