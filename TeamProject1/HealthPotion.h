#pragma once
#include "Item.h"

class Character;
class HealthPotion :
    public Item
{
private:
    string name;
    int price;

public:
    HealthPotion();
    string GetName() override;
    int GetPrice() override;
    void Use(Character* character) override;


};

//주석2