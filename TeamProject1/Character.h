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
	vector <item*> inventory; //아이템 클래스 전방선언

public:

	static Character* Getinstance(string = "");
	void Displaystatus();
	void Levelup();
	void UseItem(int index);
	void Addgold(int amount);
	void Spendgold(int amount);

	//getter
	string Getname();
	int Getlevel();
	int GetHP();
	int GetmaxHP();
	int Getattack();
	int Getexperience();
	int Getgold() const;

	//setter
	void Setname(string name);
	void Setlevel(int level);
	void SetHP(int HP);
	void SetmaxHP(int maxHP);
	void Setattack(int attack);
	void Setexprience(int experience);
	void Setgold(int gold);
};

