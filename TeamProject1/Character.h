#pragma once
#include <string>
#include <vector>
using namespace std;

class Item;

class Character
{
private:

	Character();
	Character(string name);

	static Character* instance;
	string name;
	int level;
	int HP;
	int maxHP;
	int attack;
	int experience;
	int gold;
	vector <Item*> inventory; // ������ Ŭ���� ���漱��

public:

	Character(const Character&) = delete; //���� ������ �����Ͽ� ���� ����
	Character& operator=(const Character&) = delete; //���� ������ �����Ͽ� ���� ����

	static Character* GetInstance(string = "");
	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	void AddGold(int amount);
	void SpendGold(int amount);
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

	//setter
	void SetName(string name);
	void SetLevel(int level);
	void SetHP(int HP);
	void SetMaxHP(int maxHP);
	void SetAttack(int attack);
	void SetExprience(int experience);
	void SetGold(int gold);
};

