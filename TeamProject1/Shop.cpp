
#include "Shop.h"
#include <iostream>
#include "Character.h"
#include "Item.h"


void Shop::BuyItem(Item* item, Character* character, Inventory* inventory)	//�����۰� ĳ������ Ŭ������ ����
{
	if (character->Getgold() >= item->GetPrice())	//��尡 �����̶� ���ų� �� Ŭ��
	{
		character->Spendgold(item->GetPrice());	//��� ����
		inventory->AddItem(item);					//������ �߰�, AddItem�� ���� �κ��丮 Ŭ�������� ���� ����
		cout << item->GetName() << "���� �Ϸ�!" << endl;
	}
	else {											//��尡 ������� ���� ��
		cout << "��尡 �����մϴ�!" << endl;
	}
}
void Shop::SellItem(Item* item, Character* character, Inventory* inventory)	//�����۰� ĳ������ Ŭ������ ����
{
	if (inventory->GetItemCount(item) > 0)						//�������� ������ ������ ����
	{
		character->Addgold(item->GetPrice());		//�������� ���ݸ�ŭ ��尡 ����
		inventory->RemoveItem(item);					//�κ��丮���� ������ ����, ���� �κ��丮 Ŭ�������� DeleteItem ���� ����
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

