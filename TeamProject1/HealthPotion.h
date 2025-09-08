#pragma once
#include "Item.h"

class Character;
class HealthPotion :
    public Item
{
private:
    int healthrestore;

public:
    HealthPotion();
    string GetName() override;
    int GetPrice() override;
    void Use(Character* character) override;


};

