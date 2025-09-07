#pragma once
#include "Item.h"

class Character;
class HealthPotion :
    public Item
{
private:
    string name;
    int healthrestore;

public:
    HealthPotion();
    string GetName();
    void Use(Character* character);

};

