#pragma once
#include "Item.h"
#include "Character.h"

class HealthPotion :
    public Item
{
private:
    string name;
    int healthRestore;

public:
    HealthPotion();
    string GetName();
    void Use(Character* character);

};

