#pragma once

class Character;
class Item;
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

//주석1