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
		<< "1. �������ͽ� Ȯ��" << endl
		<< "2. ���� ����" << endl
		<< "3. ���� ����" << endl
		<< "4. ���� ����" << endl
		<< "--------------------------------------" << endl
		<< "�ൿ�� �������ּ���: ";
	cin >> ActionNum;
	cout << "======================================" << endl;
	return ActionNum;
}

int main() {
	string nickname = "";
	GameManager* GM = new GameManager();
	cout << "�г����� �Է����ּ���: ";
	while (true)
	{
		cin >> nickname;
		if (nickname == "") {
			cout << "�Է��� ���� �ʾҽ��ϴ�. �Է����ּ���: ";
			nickname = "";
		}
		else break;
	}
	cout << "ȯ���մϴ� " << nickname << "��!" << endl;
	cout << "�⺻ ������ ����(15G)" << endl;
	switch (GM->PlayerAction()) {
	case 1: {
		//�������ͽ�
		break;
	}
	case 2: {
		//����
		break;
	}
	case 3: {
		//��������
		break;
	}
	case 4: {
		cout << "���α׷��� �����մϴ�" << endl;
		break;
	}
	default: {
		cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���" << endl;
		break;
	}
	}
}