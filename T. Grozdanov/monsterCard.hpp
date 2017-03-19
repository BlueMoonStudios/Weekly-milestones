#pragma once 

class MonsterCard
{
public:
	enum monsterType
	{	
		warrior,
		range
	};

	//constructor
	MonsterCard(char _name[30], int nameLen, char _type, int _health, int _attack, int _mana);
	MonsterCard();
	//accesors
	const char* get_name() const;
	int get_attack() const;
	int get_mana() const;
	int get_health() const;
	int get_nameLen() const;
	bool is_Freezed();
	//mutators
	void set_health(int new_health);
	void set_freeze(bool freezeOrNot);


private:
	monsterType type;
	int nameLen;
	bool isFreezed;
	char name[30];
	int health;
	int attack;
	int mana;	
};