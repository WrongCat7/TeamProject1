#pragma once
#include "MonsterBase.h"

class Skeleton : public Monster
{
public:
	Skeleton() : Monster("Skeleton", 40, 5) {} // 이름, HP , ATK 기본값
};
