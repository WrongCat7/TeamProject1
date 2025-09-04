#pragma once
#include <string>
#include <vector>
using namespace std;

class Character
{
private:

	static Character* instance;
	string name;
	int level;
	int HP;
	int maxHP;
	int attack;
	int experience;
	int gold;
	vector <item*> inventory;

public:
	Character();
	Character(string name);

	static Character* Getinstance(string = "");
	void Displaystatus();
	void Levelup();
	void UseItem(index:int);


	//getter
	string Getname();
	int Getlevel();
	int GetHP();
	int GetmaxHP();
	int Getattack();
	int Getexperience();
	int Getgold();

	//setter
	void Setname(string name);
	void Setlevel(int level);
	void SetHP(int HP);
	void SetmaxHP(int maxHP);
	void Setattack(int attack);
	void Setexprience(int experience);
	void Setgold(int gold);
};


