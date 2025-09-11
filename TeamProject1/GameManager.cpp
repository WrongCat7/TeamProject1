#include "MonsterBase.h"
#include "Shop.h"
#include "Orc.h"
#include "Skeleton.h"
#include "Goblin.h"
#include "Slime.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "GameManager.h"
#include "Image.h"   ////    ����2    ////
#include "Melody.h"
#include <vector>
#include <iostream>
#include <random>

using namespace std;
vector<Monster*> monster;

GameManager::GameManager() {

}

string GameManager::PlayerAction() {
	ActionNUM = "";
	cout << "\n"
		<< "======================================\n"
		<< "�ൿ ����â\n"
		<< "======================================\n"
		<< "1. �������ͽ� Ȯ��\n"
		<< "2. ������ ����ϱ�\n"
		<< "3. ���� ����\n"
		<< "4. ���� ����\n"
		<< "5. ���� ����\n"
		<< "--------------------------------------" << endl
		<< "�ൿ�� �������ּ���: ";
	cin >> ActionNUM;
	cout << "======================================" << endl;
	return ActionNUM;
}
vector<Monster*> monsters;

Monster* GenerateMonster(int level) {
	Monster* m = nullptr;
	std::random_device rd;  // �õ� ����
	std::mt19937 gen(rd()); // Mersenne Twister ����
	uniform_int_distribution<int> dist(1, 4);
	int i = dist(gen);
		switch (i) {
		case 1: {
			m = new Orc(level);
			break;
			}
		case 2: {
			m = new Goblin(level);
			break;
		}
		case 3: {
			m = new Slime(level);
			break;
		}
		case 4: {
			m = new Skeleton(level);
			break;
		}
		}
		return m;
}



void GameManager::Battle(Character* player) {
	Monster* monster = GenerateMonster(player->GetLevel());
	Image imageManager;     ////    ����2    ////

	imageManager.ShowImage(monster->GetName());     ////    ����2    ////

	cout << "���� " << monster->GetName() << "����! ü��: " << monster->GetHP() << "���ݷ�: " << monster->GetAttack() << endl;
		while(true){
			monster->TakeDamage(player->GetAttack());
			if (monster->IsDead() == 1) 
			{
				cout << player->GetName() << "��(��) �����մϴ�! " << monster->GetName() << " óġ!" << endl;
				player->SetExprience(50);
				player->SetGold(monster->GetGold());
				cout << player->GetName() << "��(��) 50 EXP�� " << monster->GetGold() << "��带 ȹ���߽��ϴ�. "
					<< "���� EXP: " << player->GetExperience() << "/100, ���: " << player->GetGold() << endl;
				delete monster;
				monster = nullptr;
				break;
			}
			else 
			{
				cout << player->GetName() << "��(��) " << monster->GetName() << "�� �����մϴ�!" << monster->GetName() << " ü��: " << monster->GetHP() << endl;
			}
			monster->TakeDamage(player->GetAttack());
			if (player->IsDead() == 1)
			{
				cout << monster->GetName() << "��(��) �����մϴ�! " << player->GetName() << " ü��: " << player -> GetHP() << " -> 0" << endl;
				cout << player->GetName() <<"�� ����߽��ϴ�. ���� ����!" << endl;
				delete monster;
				monster = nullptr;
				break;
			}
			else {
				cout << monster->GetName() << "��(��) " << player->GetName() << "�� �����մϴ�!" << player->GetName() << " ü��: " << player->GetHP() << endl;
			}
		}
}
void GameManager::VisitShop(Character* player, Inventory* inventory) {
	//Shop* shop = new Shop;
	//Inventory* INV = new Inventory;
	//shop->ShowItems(INV, player);
	//delete shop;
	//delete INV;
	//shop = nullptr;
	//INV = nullptr;
	Shop shop;
	shop.ShowItems(inventory, player);
}

int main() {
	Melody bgm;
	Inventory playerInventory;
	string nickname = "";
	GameManager* GM = new GameManager;
	cout << "�г����� �Է����ּ���: ";
	while (true)
	{
		int boolcheck = 0;
		getline(cin, nickname);
		if (nickname == "") {
			system("cls");
			cout << "�Է��� ���� �ʾҽ��ϴ�.\n�г����� �ٽ� �Է����ּ���: ";
			continue;
		}
		else {
			for (char c : nickname) {
				if (c == ' ') {
					system("cls");
					cout << "������ �ֽ��ϴ�.\n�г����� �ٽ� �Է����ּ���: ";
					boolcheck = 1;
					break;
				}
			}
		}
		if (boolcheck == 0) {
			break;
		}
	}
	Character* player = Character::GetInstance(nickname);
	cout << "ȯ���մϴ� " << player->GetName() << "��!" << endl;
	cout << "�⺻ ������ ����(15G)" << endl;
	while (true) {
		system("cls"); ////   ������ �κ�    ////
		Image images;     ////    ����2    ////

		images.ShowImage("����");     ////    ����2    ////
		string SNUM = GM->PlayerAction();
			if (SNUM == "1") {
				system("cls"); ////   ������ �κ�    ////
				player->DisplayStatus();
				//cout << player->GetExperience() << endl;
				//�������ͽ�
				system("pause"); ////   ������ �κ�    ////
			}
			else if (SNUM == "2") {//������ ���
				system("cls"); ////   ������ �κ�    ////
				images.ShowImage("����");     ////   ����4    ////
				int actionNUM;
				cout << "\n"
					<< "======================================\n"
					<< "�κ��丮\n"
					<< "--------------------------------------" << endl;

				int noItem = playerInventory.DisplayItems(); ////   ����3    ////

				cout << "======================================" << endl;
				if (noItem == 1) ////   ����3    ////
				{
					system("pause");
				}
				else
				{
					cout << "�������� ��ȣ�� �Է����ּ���: ";
					cin >> actionNUM;
					playerInventory.UseItem(actionNUM, player);

					cout << "======================================" << endl;
					system("pause"); ////   ������ �κ�    ////
				}
			}
			else if (SNUM == "3") {
				bgm.ShopInBGM();
				GM->VisitShop(player, &playerInventory);//����
			}
			else if (SNUM == "4") {
				bgm.BattelBGM();
				system("cls"); ////   ������ �κ�    ////
				GM->Battle(player);//��������
				if (player->IsDead() == 1) return 0;
				system("pause"); ////   ������ �κ�    ////
			}
			else if (SNUM == "5") {
				cout << "���α׷��� �����մϴ�" << endl;
				return 0;
			}
			else cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���" << endl;
			if (player->GetLevel() == 10) {
				cout << "���� 10�� �޼��ϼ̽��ϴ�. �¸�!";
				return 0;
			}
	}
}