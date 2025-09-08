#pragma once
#include <string>

using namespace std;

class Inventory;

class Monster {

public:
	// 생성자
	virtual~Monster() = default;

	// 정보 확인 함수
	virtual string GetName() = 0;
	virtual int GetHP() = 0;
	virtual int GetAttack() = 0;

	// 행동 함수
	virtual void TakeDamage(int damage) = 0;
	virtual bool IsDead() = 0;
	virtual void DropItem(Inventory* inventory) = 0;
	int RandomGold();
};
