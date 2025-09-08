#pragma once
#include "Item.h"

class Character;
class Item;
class AttackBoost :
    public Item
{

private:
    string name;
    int price;

public:

    AttackBoost();
    string GetName() override;
    int GetPrice() override;
    void Use(Character* character) override;

};

//주석1