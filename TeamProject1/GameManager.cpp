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
		<< "행동 선택창\n"
		<< "======================================\n"
		<< "1. 스테이터스 확인\n"
		<< "2. 아이템 사용하기\n"
		<< "3. 상점 열기\n"
		<< "4. 전투 시작\n"
		<< "5. 게임 종료\n"
		<< "--------------------------------------" << endl
		<< "행동을 선택해주세요: ";
	cin >> ActionNUM;
	cout << "======================================" << endl;
	return ActionNUM;
}
vector<Monster*> monsters;

Monster* GenerateMonster(int level) {
	Monster* m = nullptr;
	std::random_device rd;  // 시드 생성
	std::mt19937 gen(rd()); // Mersenne Twister 엔진
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
	cout << "몬스터 " << monster->GetName() << "등장! 체력: " << monster->GetHP() << "공격력: " << monster->GetAttack() << endl;
		while(true){
			monster->TakeDamage(player->GetAttack());
			if (monster->IsDead() == 1) {
				cout << player->GetName() << "이(가) 공격합니다! " << monster->GetName() << " 처치!" << endl;
				cout << player->GetName() << "이(가) 50 EXP와 "<<endl;
				player->SetExprience(50);
				delete monster;
				monster = nullptr;
				break;
			}
			else {
				cout << player->GetName() << "이(가) " << monster->GetName() << "를 공격합니다!" << monster->GetName() << " 체력: " << monster->GetHP() << endl;
			}
			monster->TakeDamage(player->GetAttack());
			if (player->IsDead() == 1) {
				cout << monster->GetName() << "이(가) 공격합니다! " << player->GetName() << " 체력: " << player -> GetHP() << " -> 0" << endl;
				cout << player->GetName() <<"가 사망했습니다. 게임 오버!" << endl;
				delete monster;
				monster = nullptr;
				break;
			}
			else {
				cout << monster->GetName() << "이(가) " << player->GetName() << "를 공격합니다!" << player->GetName() << " 체력: " << player->GetHP() << endl;
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
	Inventory playerInventory;
	string nickname = "";
	GameManager* GM = new GameManager;
	cout << "닉네임을 입력해주세요: ";
	while (true)
	{
		cin >> nickname;
		if (nickname == "") {
			cout << "입력을 하지 않았습니다. 입력해주세요: ";
			nickname = "";
		}
		else break;
	}
	Character* player = Character::GetInstance(nickname);
	cout << "환영합니다 " << player->GetName() << "님!" << endl;
	cout << "기본 소지금 지급(15G)" << endl;
	while (true) {
		string SNUM = GM->PlayerAction();
			if (SNUM == "1") {
				player->DisplayStatus();
				cout << player->GetExperience() << endl;
				//스테이터스
			}
			else if (SNUM == "2") {//아이템 사용
				
				int actionNUM;
				cout << "\n"
					<< "======================================\n"
					<< "인벤토리\n"
					<< "--------------------------------------" << endl;
				playerInventory.DisplayItems();
				cout << "======================================" << endl;
				cin >> actionNUM;
				playerInventory.UseItem(actionNUM, player);
			}
			else if (SNUM == "3") {
				GM->VisitShop(player, &playerInventory);//상점
			}
			else if (SNUM == "4") {
				GM->Battle(player);//전투시작
				if (player->IsDead() == 1) return 0;
			}
			else if (SNUM == "5") {
				cout << "프로그램을 종료합니다" << endl;
			}
			else cout << "잘못된 선택입니다. 다시 입력해주세요" << endl;
			if (player->GetLevel() == 10) {
				cout << "레벨 10을 달성하셨습니다. 승리!";
				return 0;
			}
	}
}