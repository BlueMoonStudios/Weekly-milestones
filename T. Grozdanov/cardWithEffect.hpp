#pragma once
#include "monsterCard.hpp"

class CardWithEffect
{
public:
	enum Type
	{
		spell,
		trap
	};
	//constructor
	CardWithEffect(Type _type, char _name[30],int _nameLen, char _descrip[200], int _descripLen);
	CardWithEffect();
	//accessors
	const char* get_name() const;
	const char* get_descrip() const;
	int get_descripLen();
	int get_nameLen();
	//methodes
	void decreaseHealth(int damage, MonsterCard &monster);
	void freezeMonster(MonsterCard &monster);
	void unfreezeMonster(MonsterCard &monster);

private:
	int nameLen;
	int descripLen;
	Type type;
	char name[30];
	char descrip[200];
};