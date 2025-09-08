#pragma once

class Character;
class Item;
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

//주석1