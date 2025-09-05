#pragma once
#include "MonsterBase.h"

class Orc : public Monster
{
public:
	Orc() : Monster("Orc", 50, 10) {} // 이름, HP , ATK 기본값
};
