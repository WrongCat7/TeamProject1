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
		item = nullptr;
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
		cout << "----------------" << endl;
		cout << "현재 보유 골드 : " << character->GetGold() << " 골드" << endl;
		cout << "1. 아이템 구매" << endl;
		cout << "2. 아이템 판매" << endl;
		cout << "3. 상점 나가기" << endl;
		cout << "----------------" << endl;
		cout << "----------------" << endl;
		cout << "번호를 입력해주세요 : ";
		cin >> input;

		if (input == 1)
		{
			cout << "-------------------------" << endl;
			cout << "-------------------------" << endl;
			cout << "구매 가능한 아이템 목록" << endl;
			for (int i = 0; i < shopitems.size(); i++)
			{
				cout << (i + 1) << ":" << shopitems[i]->GetName()
					<< " " << shopitems[i]->GetPrice() << " 골드" << endl;
			}
			cout << shopitems.size() + 1 << ": 뒤로가기" << endl;
			cout << "-------------------------" << endl;
			cout << "-------------------------" << endl;
			int buynum;
			cout << "번호를 입력하세요 : ";
			cin >> buynum;
			cout << "-------------------------" << endl;
			cout << "-------------------------" << endl;

			if (buynum == shopitems.size() + 1)
			{
				continue;
			}

			if (buynum > 0 && buynum <= shopitems.size())
			{
				BuyItem(character, inventory, shopitems[buynum - 1]);
			}
			else
			{
				cout << "잘못된 입력입니다. 1~" << shopitems.size() << "번 중에서 골라주세요." << endl;
			}
		}
		else if (input == 2)
		{
			if (inventory->GetItemCount() == 0)
			{
				cout << "판매할 아이템이 없습니다." << endl;
				system("pause");
				continue;
			}

			inventory->DisplayItems();
			int sellnum;
			cout << "번호를 입력하세요 : ";
			cin >> sellnum;

			if (sellnum == inventory->GetItemCount() + 1)
			{
				continue;
			}

			if (sellnum < 1 || sellnum > inventory->GetItemCount())
			{
				cout << "잘못된 번호입니다." << endl;
				system("pause");
				continue;
			}
			Item* item = inventory->GetItem(sellnum - 1);
			if (item != nullptr)
			{
				SellItem(character, inventory, item);
			}
		}
		else if (input == 3)
		{
			return;
		}
		else
		{
			cout << "잘못된 입력입니다. 1 ~ 3 번 중에서 골라주세요." << endl;
		}

		system("pause");
	}
}
void Shop::BuyItem(Character* character, Inventory* inventory, Item* item)
{
	if (character->GetGold() >= item->GetPrice())
	{
		character->SetGold(-item->GetPrice());
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
		string itemname = item->GetName();
		int price = item->GetPrice();
		character->SetGold(price);
		item->SetCount(-1);
		if (item->GetCount() <= 0)
		{
			inventory->RemoveItem(item);
		}
		cout << itemname << " 판매 완료! (+" << price << " 골드)" << endl;
	}
	else
	{
		cout << "판매할 아이템이 없습니다!" << endl;
	}
}
