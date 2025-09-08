#include "Inventory.h"
#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void Inventory::AddItem(Item* item)
{
	items.push_back(item);
}

void Inventory::UseItem(int index, Character* character)
{
	if ( index < 0 ) return;
	items[index]->Use(character);
	delete items[index];
	items.erase(items.begin() + index);
}

void Inventory::DisplayItems()
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << i << ": " << items[i]->GetName() << "  " << items[i]->GetPrice() << " 골드" << endl;
	}
}

void Inventory::UseRandomItem(Character* character)
{
	if (items.empty())
	{
		cout << "인벤토리가 비어있습니다." << endl;
	}

	int random = rand() % 100;

	if (random < 30)
	{
		int index = rand() % items.size();
		cout << items[index]->GetName() << "이 30% 확률로 사용됩니다." << endl;
		items[index]->Use(character);
		delete items[index];
		items.erase(items.begin() + index);
	}

	else
	{
		cout << "아이템 사용에 실패 했습니다." << endl;
	}
}

int Inventory::GetItemCount(Item* item)
{
	int count = 0;
	for (auto& i : items)
	{
		if (i->GetName() == item->GetName())
		{
			count++;
		}
	}
	return count;
}

void Inventory::RemoveItem(Item* item)
{
	auto it = std::find(items.begin(), items.end(), item);
	if (it != items.end())
	{
		delete* it;
		items.erase(it);
	}
}

Item* Inventory::RandomItem()
{
	Item* randomitem = nullptr;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 1);

	switch (dist(gen))
	{
	case 0: randomitem = new HealthPotion(); break;
	case 1: randomitem = new AttackBoost(); break;

	}

	return randomitem;
}
//주석1