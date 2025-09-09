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
		cout << "----- ���� -----" << endl;
		cout << "���� ���� ��� : " << character->GetGold() << " ���" << endl;
		cout << "1. ������ ����" << endl;
		cout << "2. ������ �Ǹ�" << endl;
		cout << "3. ���� ������" << endl;
		cin >> input;

		if (input == 1)
		{
			cout << "���� ������ ������ ���" << endl;
			for (int i = 0; i < shopitems.size(); i++)
			{
				cout << i << ":" << shopitems[i]->GetName()
					<< " " << shopitems[i]->GetPrice() << " ���" << endl;
			}
			int buynum;
			cout << "��ȣ�� �Է��ϼ��� (��� 3) : " << endl;
			cin >> buynum;

			if (buynum > 0 && buynum <= 3)
			{
				BuyItem(character, inventory, shopitems[buynum - 1]);
			}
			else
			{
				cout << "�߸��� �Է��Դϴ� 1~4�� �߿��� ����ּ���." << endl;
			}
		}
		else if (input == 2)
		{
			if (inventory->GetItemCount() == 0)	//GetItemCount �Լ��� ��ü ������ ���� ��ȯ�ϰ� �ٲٸ� ��밡��
			{
				cout << "�Ǹ��� �������� �����ϴ�." << endl;
			}
			else
			{
				inventory->DisplayItems();
				int sellnum;
				cout << "��ȣ�� �Է��ϼ��� (��� 3) : " << endl;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
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
		character->SetGold(character->GetGold() + item->GetPrice());
		inventory->RemoveItem(item);
		cout << item->GetName() << " �Ǹ� �Ϸ�! (+" << item->GetPrice() << " ���)" << endl;
	}
	else
	{
		cout << "�Ǹ��� �������� �����ϴ�!" << endl;
	}
}

