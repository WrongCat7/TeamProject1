#include "Character.h"
#include <iostream>
#include "Inventory.h"
using namespace std;

Character::Character(string name) // 생정자 정의
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

void Character::LevelUp() // 레벨업 할 경우 능력치 상승 및 체력 100% 회복
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
		}
	}
	else
	{
		this->experience = 0;
		cout << "최대 레벨에 도달했습니다." << '\n';
	}

}

void Character::TakeDamage(int damage) // 캐릭터가 데미지 받는 함수
{
	if (damage <= 0) // 음수 데미지 방지
	{
		return;
	}
	// 데미지 적용
	HP -= damage;
}

bool Character::IsDead() // 사망 여부 확인을 위한 함수
{
	if (HP <= 0)
	{
		HP = 0;
		return true; // 사망시 트루
	}
	else
	{
		return false; // 생존시 폴스
	}
}

void Character::DisplayStatus() // 캐릭터 상태
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

//setter 함수
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
	this->experience += experience; // 경험치 누적
	LevelUp();
}

void Character::SetGold(int gold)
{
	this->gold += gold; // 골드 누적, 상품 구매 시 음수로 골드 차감
}

void Character::SetInventory(Inventory* invnetory) {
	this->INV = invnetory;
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