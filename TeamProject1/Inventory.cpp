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
	items.push_back(item);
}

void Inventory::UseItem(int index, Character* character)
{
	if (index < 0 || index >= items.size()) return;
	items[index]->Use(character);
	delete items[index];
	items.erase(items.begin() + index);
}

void Inventory::DisplayItems()
{
	if (items.empty())
	{
		cout << "�κ��丮�� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < items.size(); i++)
	{
		cout << i << ": " << items[i]->GetName() << "  " << items[i]->GetPrice() << " ���" << endl;
	}
}

void Inventory::UseRandomItem(Character* character)
{
	if (items.empty())
	{
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return;
	}

	int random = rand() % 100;

	if (random < 30)
	{
		int index = rand() % items.size();
		cout << items[index]->GetName() << "�� 30% Ȯ���� ���˴ϴ�." << endl;
		items[index]->Use(character);
		delete items[index];
		items.erase(items.begin() + index);
	}

	else
	{
		cout << "������ ��뿡 ���� �߽��ϴ�." << endl;
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
}
//�ּ�1