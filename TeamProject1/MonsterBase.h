#pragma once
#include <string>

using namespace std;

class Character;
class Inventory;

class Monster {

public:
	// 생성자
	virtual~Monster() = default;

	// 정보 확인 함수
	virtual string GetName() = 0;
	virtual int GetHP() = 0;
	virtual int GetAttack() = 0;
	virtual int GetExperience() = 0;
	virtual int GetGold() = 0;


	// 행동 함수
	virtual void TakeDamage(int damage) = 0;
	virtual bool IsDead() = 0;
	virtual void DropItem(Character* player, Inventory* inventory) = 0;
};
