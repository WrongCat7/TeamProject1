#pragma once
#include <string>

using namespace std;

class Monster {
private:
	string Name;
	int HP;
	int ATK;

public:
	// 생성자
	Monster(string Name, int HP, int ATK);

	// 행동 함수
	void Attack(Monster& target);
	void Takedamage(int damage);

	// 정보 확인 함수
	string GetName()const;
	int GetHP()const;
	int GetATK()const;
};
