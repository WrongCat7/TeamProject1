//#include "Monster.h"
//#include "Shop.h"
//#include "Charcter.h"
//#include "Item.h"
#include "GameManager.h"
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;


int GameManager::PlayerAction() {
	ActionNum = 0;
	cout << "======================================" << endl
		<< "1. 스테이터스 확인" << endl
		<< "2. 상점 열기" << endl
		<< "3. 전투 시작" << endl
		<< "4. 게임 종료" << endl
		<< "--------------------------------------" << endl
		<< "행동을 선택해주세요: ";
	cin >> ActionNum;
	cout << "======================================" << endl;
	return ActionNum;
}

int main() {
	string nickname = "";
	GameManager* GM = new GameManager();
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
	cout << "환영합니다 " << nickname << "님!" << endl;
	cout << "기본 소지금 지급(15G)" << endl;
	switch (GM->PlayerAction()) {
	case 1: {
		//스테이터스
		break;
	}
	case 2: {
		//상점
		break;
	}
	case 3: {
		//전투시작
		break;
	}
	case 4: {
		cout << "프로그램을 종료합니다" << endl;
		break;
	}
	default: {
		cout << "잘못된 선택입니다. 다시 입력해주세요" << endl;
		break;
	}
	}
}