#include <iostream>
#include <random>
#include "Skeleton.h"
#include "MonsterBase.h"

using namespace std;


Skeleton::Skeleton(int level)
{
	name = "스켈레톤";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum1(20, 30);
	
	HP = level * randomnum1(gen);

	uniform_int_distribution<int> randomnum2(5, 10);

	ATK = level* randomnum2(gen);
}

string Skeleton::GetName()
{
	return name;
}

int Skeleton::GetHP()const
{
	return HP;
}
int Skeleton::GetATK()const
{
	return ATK;
}


void Skeleton::Takedamage(int damage)
{
	HP -= damage;
	if (HP < 0) HP = 0;
	cout << name << " 체력: " << HP << endl;
}

bool  Skeleton::Isdead() // 사망 여부 확인을 위한 함수
{
	// HP에 데미지 적용 후 액션
	if (HP <= 0)
	{
		HP = 0;
		return true;
	}
	else
	{
		return false;
	}
}

//구현필요
void Skeleton::dropitem()
{

}