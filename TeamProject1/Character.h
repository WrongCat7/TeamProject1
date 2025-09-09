#pragma once
#include <string>
#include <vector>
using namespace std;
class Inventory;
class Character
{
private:

	Character(string name);

	static Character* instance;
	string name;
	int level;
	int HP;
	int maxHP;
	int attack;
	int experience;
	int gold;
	Inventory* INV;

public:

	Character(const Character&) = delete; //���� ������ �����Ͽ� ���� ����
	Character& operator=(const Character&) = delete; //���� ������ �����Ͽ� ���� ����

	static Character* GetInstance(string = "");
	void DisplayStatus();
	void LevelUp();
	void TakeDamage(int damage);
	bool IsDead();

	//getter
	string GetName();
	int GetLevel();
	int GetHP();
	int GetMaxHP();
	int GetAttack();
	int GetExperience();
	int GetGold() const;
	Inventory* GetInventory() const;

	//setter
	void SetName(string name);
	void SetLevel(int level);
	void SetHP(int HP);
	void SetMaxHP(int maxHP);
	void SetAttack(int attack);
	void SetExprience(int experience);
	void SetGold(int gold);
	void SetInventory(Inventory* inventory);
};

