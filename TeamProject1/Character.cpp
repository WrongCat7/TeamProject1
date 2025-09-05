#include "Character.h"
#include <iostream>
using namespace std;

Character::Character()
{
	name = "Player";
	level = 1;
	HP = 200;
	maxHP = 200;
	attack = 30;
	experience = 0;
	gold = 15;
}

Character::Character(string name)
{
	this->name = name;
	this->level = 1;
	this->HP = 200;
	this->maxHP = 200;
	this->attack = 30;
	this->experience = 0;
	this->gold = 15;

}

Character* Character::Getinstance(string)
{
	return nullptr;
}

void Character::Levelup() // 레벨업 할 경우 능력치 상승 및 체력 100% 회복
{
	if (experience == 100)
	{
		this->level += 1;
		this->HP += maxHP + (level * 20);
		this->maxHP += (level * 20);
		this->attack += (level *5);
		this->experience = 0;
	}
}

void Character::UseItem(int index)
{
	inventory[index]->Use(); // 아이템 사용
	cout << inventory[index]->Getname() << " 아이템을 사용했습니다. \n";

	delete inventory[index];
	inventory[index] = nullptr;
}


void Character::Displaystatus() // 캐릭터 상태
{
	cout << "---------Statsus---------" << '\n';
	cout << " 이름 : " << name << '\n';
	cout << "Lv. : " << level << '\n';
	cout << "HP / 최대HP : / " << HP << " / " << maxHP << '\n';
	cout << "공격력 : " << attack << '\n';
	cout << "경험치 : " << experience << '\n';
	cout << "보유 골드 : " << gold << '\n';
	cout << "" << '\n'; // 아이템 보유 현황
	cout << "=========================" << '\n';
}

// getter 함수
string Character::Getname()
{
	return string();
}

int Character::Getlevel()
{
	return level;
}

int Character::GetHP()
{
	return HP;
}

int Character::GetmaxHP()
{
	return maxHP;
}

int Character::Getattack()
{
	return attack;
}

int Character::Getexperience()
{
	return experience;
}

int Character::Getgold()
{
	return gold;
}


//setter 함수
void Character::Setname(string name)
{
	this->name = name;
}

void Character::Setlevel(int level)
{
	this->level = level;
}

void Character::SetHP(int HP)
{
	this->HP = HP;
}
void Character::SetmaxHP(int maxHP)
{
	this->maxHP = maxHP;
}

void Character::Setattack(int attack)
{
	this->attack = attack;
}

void Character::Setexprience(int experience)
{
	this->experience = experience;
}

void Character::Setgold(int gold)
{
	this->gold = gold;
}


/*
	//캐릭터 글자 수 제한(참고 코드)

int main()
{
	const size_t maxnamelength = 10;
	string charactername;

	cout << "캐릭터 이름을 입력하세요 (최대 " << maxnamelength << "자): ";
	getline(cin, charactername);

	if (charactername.length() > maxnamelength)
	{
		cout << "이름이 너무 깁니다." << maxnamelength << "자 이하로 입력해주세요. \n";
	}
	else
		cout << "입력된 이름 : " << charactername << '\n';

	return 0;
}

//아이템 사용 함수 확인!

*/