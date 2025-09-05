#include "Character.h"
#include <iostream>
#include "Item.h"
using namespace std;

Character::Character() // �⺻ ������ ����
{
	name = "Player";
	level = 1;
	HP = 200;
	maxHP = 200;
	attack = 30;
	experience = 0;
	gold = 15;
}

Character::Character(string name) // ������ ����
{
	this->name = name;
	this->level = 1;
	this->HP = 200;
	this->maxHP = 200;
	this->attack = 30;
	this->experience = 0;
	this->gold = 15;
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
		if (experience == 100)
		{
			this->level += 1;
			this->maxHP += (level * 20);
			this->HP += this->maxHP;
			this->attack += (level * 5);
			this->experience = 0;
		}
	}
	else
	{
		cout << "�ִ� ������ �����߽��ϴ�." << '\n';
	}

}

void Character::UseItem(int index)
{
	inventory[index]->Use(); // ������ ���
	cout << inventory[index]->GetName() << " �������� ����߽��ϴ�. \n";

	delete inventory[index];
	inventory[index] = nullptr;
}

void Character::AddGold(int amount) // ��� ���� 
{
	if (amount > 0)
	{
		gold += amount;
		cout << "��带 ������ϴ�." << amount << " ���� ��� : " << gold << '\n';
	}
}

void Character::SpendGold(int amount) // ��� ����
{
	if (amount > 0)
		gold -= amount;
	cout << "��带 �Һ��Ͽ����ϴ�. " << amount << " ���� ��� : " << gold << '\n';
}

void Character::TakeDamage(int damage) // ĳ���Ͱ� ������ �޴� �Լ�
{
	if (damage <= 0) // ���� ������ ����
	{
		return;
	}
	// ������ ����
	HP -= damage;
	cout << name << "��(��)" << damage << "��ŭ�� �������� �޾Ҵ�." << '\n';
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
	cout << "" << '\n'; // ������ ���� ��Ȳ
	cout << "=========================" << '\n';
}

// getter �Լ�
string Character::GetName()
{
	return string();
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
}

void Character::SetGold(int gold)
{
	this->gold += gold; // ��� ����, ��ǰ ���� �� ������ ��� ����
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