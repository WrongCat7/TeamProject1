#pragma once
#include "Item.h"

class Character;
class AttackBoost :
    public Item
{

private:
    int attackincrease;

public:

    AttackBoost();
    string GetName() override;
    int GetPrice() override;
    void Use(Character* character) override;

};

