#pragma once
#include "MonsterBase.h"

class Slime : public Monster
{
public:
	Slime() : Monster("Slime", 20, 3) {} // 이름, HP , ATK 기본값
};
