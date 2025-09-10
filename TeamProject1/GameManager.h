#pragma once
class Character;
class Item;
class Shop;
class Monster;


class GameManager {
private:
	string ActionNUM;
public:
	GameManager();
	string PlayerAction();
	void VisitShop(Character* player, Inventory* inventory);
	void Battle(Character* player);
};