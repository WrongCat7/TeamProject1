#pragma once
#include "MonsterBase.h"

class Goblin : public Monster
{
public:
	Goblin() : Monster("Goblin", 30, 5) {} // 이름, HP , ATK 기본값
};
