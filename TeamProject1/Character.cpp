#include "Character.h"
#include <iostream>
#include "Inventory.h"
using namespace std;

Character::Character(string name) // ������ ����
{
	this->name = name;
	this->level = 1;
	this->HP = 200;
	this->maxHP = 200;
	this->attack = 30;
	this->experience = 0;
	this->gold = 100;
}

Character* Character::GetInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}
	return instance;
}
Character* Character::instance = nullptr;

void Character::LevelUp() // ������ �� ��� �ɷ�ġ ��� �� ü�� 100% ȸ��
{
	if (level < 10)
	{
		if (this->experience == 100)
		{
			this->level += 1;
			this->maxHP += (level * 20);
			this->HP = maxHP;
			this->attack += (level * 5);
			this->experience = 0;

			cout << "�����մϴ�. �������Ͽ����ϴ�!" << '\n';
			cout << "���� ���� : " << level << '\n';
		}
	}
	else
	{
		this->experience = 0;
		cout << "�ִ� ������ �����߽��ϴ�." << '\n';
	}

}

void Character::TakeDamage(int damage) // ĳ���Ͱ� ������ �޴� �Լ�
{
	if (damage <= 0) // ���� ������ ����
	{
		return;
	}
	// ������ ����
	HP -= damage;
}

bool Character::IsDead() // ��� ���� Ȯ���� ���� �Լ�
{
	if (HP <= 0)
	{
		HP = 0;
		return true; // ����� Ʈ��
	}
	else
	{
		return false; // ������ ����
	}
}

void Character::DisplayStatus() // ĳ���� ����
{
	cout << "---------Statsus---------" << '\n';
	cout << " �̸� : " << name << '\n';
	cout << "Lv. : " << level << '\n';
	cout << "HP / �ִ�HP : / " << HP << " / " << maxHP << '\n';
	cout << "���ݷ� : " << attack << '\n';
	cout << "����ġ : " << experience << '\n';
	cout << "���� ��� : " << gold << '\n';
	cout << "=========================" << '\n';
}

// getter �Լ�
string Character::GetName()
{
	return name;
}

int Character::GetLevel()
{
	return level;
}

int Character::GetHP()
{
	return HP;
}

int Character::GetMaxHP()
{
	return maxHP;
}

int Character::GetAttack()
{
	return attack;
}

int Character::GetExperience()
{
	return experience;
}

int Character::GetGold() const
{
	return gold;
}

Inventory* Character::GetInventory() const
{
	return this->INV;
}

//setter �Լ�
void Character::SetName(string name)
{
	this->name = name;
}

void Character::SetLevel(int level)
{
	this->level = level;
}

void Character::SetHP(int HP)
{
	this->HP = HP;
}
void Character::SetMaxHP(int maxHP)
{
	this->maxHP = maxHP;
}

void Character::SetAttack(int attack)
{
	this->attack = attack;
}

void Character::SetExprience(int experience)
{
	this->experience += experience; // ����ġ ����
	LevelUp();
}

void Character::SetGold(int gold)
{
	this->gold += gold; // ��� ����, ��ǰ ���� �� ������ ��� ����
}

void Character::SetInventory(Inventory* invnetory) {
	this->INV = invnetory;
}