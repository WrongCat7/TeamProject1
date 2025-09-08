#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"
#include "Inventory.h"


void Shop::BuyItem(Item* item, Character* character, Inventory* inventory)
{
	if (character->GetGold() >= item->GetPrice())	//��尡 ����ϸ�
	{
		character->SetGold(character->GetGold() - item->GetPrice());	//��� ����, ������ - ������ ���� = ���� ���
		inventory->AddItem(item);					//�κ��丮�� ������ �߰� 
		cout << item->GetName() << "���� �Ϸ�!" << endl;
	}
	else {											//��尡 ������� ���� ��
		cout << "��尡 �����մϴ�!" << endl;
	}
}
void Shop::SellItem(Item* item, Character* character, Inventory* inventory)	//�����۰� ĳ������ Ŭ������ ����
{
	if (inventory->GetItemCount(item) > 0)	//������ ��� ����������
	{
		character->SetGold(character->GetGold() + item->GetPrice());		//���� ���(Getgold)�� ������ ����(GetPrice)�� ���ؼ� Setgold�� ����
		inventory->RemoveItem(item);					//�κ��丮�� �ִ� ������ ����
		cout << item->GetName() << "�Ǹ� �Ϸ�!" << endl;
	}
	else {
		cout << "�������� �����ϴ�!" << endl;
	}
}
void Shop::PriceCheck(Item* item)
{
	cout << item->GetName() << "���� : " << item->GetPrice() << "���" << endl;
}
int Shop::GetItemCount(Item* item, Inventory* inventory)
{
	return inventory->GetItemCount(item);
}
void Shop::ShowItems(Inventory* inventory)
{
	cout << "������ ���� ���� ȯ���մϴ�!" << endl;

	for (auto& item : shopitems)
	{
		cout << item->GetName()
			<< " : " << item->GetPrice()
			<< "���"
			<< " / ���" << inventory->GetItemCount(item)
			<< "��\n";
	}
}

