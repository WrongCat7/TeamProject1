#include <iostream>
#include "MonsterBase.h"

// 생성자
Monster::Monster(string Name, int HP, int ATK)
{
	this->Name = Name;
	this-> HP = HP;
	this->ATK = ATK;
}

// 행동 함수
void Monster::Attack(Monster& target)
{
	target.Takedamage(this->ATK);
}

void Monster::Takedamage(int damage)
{
	this->HP -= damage;
	if (this->HP < 0) this->HP = 0;
}

// 정보 확인 함수
string Monster::GetName()const
{
	return Name; // 멤버 변수 Name 반환
}

int Monster::GetHP()const
{
	return HP; // 멤버 변수 HP 변환
}

int Monster::GetATK()const
{
	return ATK; // 멤버 변수 ATK 반환!
}
