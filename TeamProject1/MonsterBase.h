#pragma once
#include <string>

using namespace std;

class Monster {
private:
	string Name;
	int HP;
	int ATK;

public:
	// ������
	Monster(string Name, int HP, int ATK);

	// �ൿ �Լ�
	void Attack(Monster& target);
	void Takedamage(int damage);

	// ���� Ȯ�� �Լ�
	string GetName()const;
	int GetHP()const;
	int GetATK()const;
};
