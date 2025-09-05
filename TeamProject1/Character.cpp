#include "Character.h"
#include <iostream>
using namespace std;

Character::Character() // 기본 생성자 정의
{
	name = "Player";
	level = 1;
	HP = 200;
	maxHP = 200;
	attack = 30;
	experience = 0;
	gold = 15;
}

Character::Character(string name) // 생정자 정의
{
	this->name = name;
	this->level = 1;
	this->HP = 200;
	this->maxHP = 200;
	this->attack = 30;
	this->experience = 0;
	this->gold = 15;
}

Character* Character::Getinstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}
	return instance;
}
Character* Character::instance = nullptr;

void Character::Levelup() // 레벨업 할 경우 능력치 상승 및 체력 100% 회복
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
		cout << "최대 레벨에 도달했습니다." << '\n';
	}

}

void Character::UseItem(int index)
{
	inventory[index]->Use(); // 아이템 사용
	cout << inventory[index]->Getname() << " 아이템을 사용했습니다. \n";

	delete inventory[index];
	inventory[index] = nullptr;
}

void Character::Addgold(int amount) // 골드 증가 
{
	if (amount > 0)
	{
		gold += amount;
		cout << "골드를 얻었습니다." << amount << " 현재 골드 : " << gold << '\n';
	}
}

void Character::Spendgold(int amount) // 골드 감소
{
	if (amount > 0)
		gold -= amount;
	cout << "골드를 소비하였습니다. " << amount << " 남은 골드 : " << gold << '\n';
}

void Character::Takedamage(int damage) // 캐릭터가 데미지 받는 함수
{
	if (damage <= 0) // 음수 데미지 방지
	{
		return;
	}
	// 데미지 적용
	HP -= damage;
	cout << name << "이(가)" << damage << "만큼의 데미지를 받았다." << '\n';
}

bool Character::Isdead() // 사망 여부 확인을 위한 함수
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

int Character::Getgold() const
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
	this->experience += experience; // 경험치 누적
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