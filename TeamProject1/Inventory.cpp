#include "Inventory.h"
#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Item.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void Inventory::AddItem(Item* item)
{
	int boolcheck = 0;
	if (items.empty()) {
		items.push_back(item);
		items[0]->SetCount(1);
	}
	else {
		for (int i = 0; i < items.size(); i++) {
			if (items[i]->GetName() == item->GetName()) {
				boolcheck += 1;
			}
		}
		if (boolcheck == 0) {
			items.push_back(item);
			for (int i = 0; i < items.size(); i++) {
				if (items[i]->GetName() == item->GetName()) {
					items[i]->SetCount(1);
				}
			}
		}
		else {
			for (int i = 0; i < items.size(); i++) {
				if (items[i]->GetName() == item->GetName()) {
					items[i]->SetCount(1);
				}
			}
		}
	}
}

void Inventory::UseItem(int index, Character* character)
{
	if (index > 0) {
		if (index-1 < items.size()) {
			items[index - 1]->Use(character);
			items[index - 1]->SetCount(-1);
			if (items[index - 1]->GetCount() < 1) {
				delete items[index - 1];
				items.erase(items.begin() + index - 1);
			}
		}
	}
}
int Inventory::DisplayItems()
{
	if (items.empty())
	{
		cout << "인벤토리에 아무것도 없습니다." << endl;
		return 1;
	}
	for (int i = 0; i < items.size(); i++)
	{
		cout << i+1 << ": " << items[i]->GetName() << "  " << items[i]->GetCount()<<"개 " << items[i]->GetPrice() << " 골드" << endl;
	}
	cout << items.size() + 1 << ": 뒤로가기" << endl;
	return 0;
}

void Inventory::UseRandomItem(Character* character)
{
	if (items.empty())
	{
		cout << "인벤토리가 비어있습니다." << endl;
		return;
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

int Inventory::GetItemCount()
{
	int count = 0;
	for (auto& i : items)
	{
		count++;
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
	delete randomitem;
	randomitem = nullptr;
}
//주석1