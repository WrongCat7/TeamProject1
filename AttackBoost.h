#pragma once
#include "Item.h"
#include "Character.h"

class AttackBoost :
    public Item
{

private:

    string name;
    int attackincreasr;

public:

    AttackBoost();
    string GetName();
    void Use(Character* character);

};

