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

void Character::Levelup() // ������ �� ��� �ɷ�ġ ��� �� ü�� 100% ȸ��
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
	inventory[index]->Use(); // ������ ���
	cout << inventory[index]->Getname() << " �������� ����߽��ϴ�. \n";

	delete inventory[index];
	inventory[index] = nullptr;
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


/*
	//ĳ���� ���� �� ����(���� �ڵ�)

int main()
{
	const size_t maxnamelength = 10;
	string charactername;

	cout << "ĳ���� �̸��� �Է��ϼ��� (�ִ� " << maxnamelength << "��): ";
	getline(cin, charactername);

	if (charactername.length() > maxnamelength)
	{
		cout << "�̸��� �ʹ� ��ϴ�." << maxnamelength << "�� ���Ϸ� �Է����ּ���. \n";
	}
	else
		cout << "�Էµ� �̸� : " << charactername << '\n';

	return 0;
}

//������ ��� �Լ� Ȯ��!

*/