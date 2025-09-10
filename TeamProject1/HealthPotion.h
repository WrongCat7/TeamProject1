#pragma once
#include "Item.h"

class Character;
class HealthPotion :
    public Item
{
private:
    string name;
    int price;
    int count;

public:
    HealthPotion();
    string GetName() override;
    int GetPrice() override;
    void Use(Character* character) override;
    int GetCount();
    void SetCount(int num);


};

//주석2