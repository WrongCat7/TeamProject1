#pragma once
#include <string>

using namespace std;

class Monster {

public:
	// 생성자
	virtual~Monster()

	// 정보 확인 함수
	virtual string GetName()const;
	virtual int GetHP()const;
	virtual int GetATK()const;

	// 행동 함수
	virtual void Takedamage(int damage) = 0;
	virtual void dropitem() = 0;
	virtual bool Isdead();
};
