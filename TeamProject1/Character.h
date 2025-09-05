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

	Character(const Character&) = delete; //복사 생성자 삭제하여 복사 방지?
	Character& operator=(const Character&) = delete; //대입 연산자 삭제하여 대입 방지?

	static Character* Getinstance(string = "");
	void Displaystatus();
	void Levelup();
	void UseItem(int index);
	void Addgold(int amount);
	void Spendgold(int amount);
	void Takedamage(int damage);
	bool Isdead() const;

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

