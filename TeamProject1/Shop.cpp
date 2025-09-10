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
		cout << "----- ���� -----" << endl;
		cout << "----------------" << endl;
		cout << "���� ���� ��� : " << character->GetGold() << " ���" << endl;
		cout << "1. ������ ����" << endl;
		cout << "2. ������ �Ǹ�" << endl;
		cout << "3. ���� ������" << endl;
		cout << "----------------" << endl;
		cout << "----------------" << endl;
		cout << "��ȣ�� �Է����ּ��� : ";
		cin >> input;

		if (input == 1)
		{
			cout << "-------------------------" << endl;
			cout << "-------------------------" << endl;
			cout << "���� ������ ������ ���" << endl;
			for (int i = 0; i < shopitems.size(); i++)
			{
				cout << (i + 1) << ":" << shopitems[i]->GetName()
					<< " " << shopitems[i]->GetPrice() << " ���" << endl;
			}
			cout << shopitems.size() + 1 << ": �ڷΰ���" << endl;
			cout << "-------------------------" << endl;
			cout << "-------------------------" << endl;
			int buynum;
			cout << "��ȣ�� �Է��ϼ��� : ";
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
				cout << "�߸��� �Է��Դϴ�. 1~" << shopitems.size() << "�� �߿��� ����ּ���." << endl;
			}
		}
		else if (input == 2)
		{
			if (inventory->GetItemCount() == 0)
			{
				cout << "�Ǹ��� �������� �����ϴ�." << endl;
				system("pause");
				continue;
			}

			inventory->DisplayItems();
			int sellnum;
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> sellnum;

			if (sellnum == inventory->GetItemCount() + 1)
			{
				continue;
			}

			if (sellnum < 1 || sellnum > inventory->GetItemCount())
			{
				cout << "�߸��� ��ȣ�Դϴ�." << endl;
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
			cout << "�߸��� �Է��Դϴ�. 1 ~ 3 �� �߿��� ����ּ���." << endl;
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
		cout << item->GetName() << " ���� �Ϸ�!" << endl;
	}
	else
	{
		cout << "��尡 �����մϴ�!" << endl;
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
		cout << itemname << " �Ǹ� �Ϸ�! (+" << price << " ���)" << endl;
	}
	else
	{
		cout << "�Ǹ��� �������� �����ϴ�!" << endl;
	}
}
