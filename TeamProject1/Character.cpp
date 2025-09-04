#include "Character.h"
#include <iostream>
using namespace std;

Character::Character()
{
	name = "Player";
	level = 1;
	HP = 100;
	maxHP = 100;
	attack = 50;
	experience = 0;
	gold = 15;
}

Character::Character(string name)
{
	this->name = name;
	this->level = 1;
	this->HP = 100;
	this->maxHP = 100;
	this->attack = 50;
	this->experience = 0;
	this->gold = 15;

}

Character* Character::Getinstance(string)
{
	return nullptr;
}

void Character::Levelup() // ������ �� ��� �ɷ�ġ ��� �� ü�� 100% ȸ��
{
	if (experience == 100)
	{
		this->level += 1;
		this->HP += maxHP;
		this->maxHP += 50;
		this->attack += 10;
		this->experience = 0;
	}
}

void Character::UseItem(int index)
{

}


void Character::Displaystatus() // ĳ���� ����
{
	cout << "---------Statsus---------" << '\n';
	cout << " �̸� : " << name << '\n';
	cout << "Lv. : " << level << '\n';
	cout << "HP / �ִ�HP : / " << HP << " / " << maxHP << '\n';
	cout << "���ݷ� : " << attack << '\n';
	cout << "����ġ : " << experience << '\n';
	cout << "���� ��� : " << gold << '\n';
	cout << "" << '\n'; // ������ ���� ��Ȳ
	cout << "=========================" << '\n';
}

// getter �Լ�
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


//setter �Լ�
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
