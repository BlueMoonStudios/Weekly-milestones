#include "monsterCard.hpp"

MonsterCard::MonsterCard(char _name[30],int _nameLen, char _type, int _health, int _attack, int _mana)
{
	for (int i = 0; i<_nameLen; i++)
	{
		name[i] = _name[i];
	}
	nameLen = _nameLen;
	name[_nameLen] = '\0';
	if(_type=='w')type = warrior;
	if (_type == 'r')type = range;
	health = _health;
	attack = _attack;
	mana = _mana;
	isFreezed = false;
}
MonsterCard::MonsterCard()
{
	name[0] = '\0';
	type = warrior;
	health = 0;
	attack = 0;
	mana = 0;
}
const char* MonsterCard::get_name() const
{
	return name;
}
int MonsterCard::get_attack() const
{
	return attack;
}
int MonsterCard::get_mana() const
{
	return mana;
}
bool MonsterCard::is_Freezed()
{
	return isFreezed;
}
int MonsterCard::get_nameLen() const
{
	return nameLen;
}
int MonsterCard::get_health() const
{
	return health;
}

void MonsterCard::set_health(int new_health)
{
	health = new_health;
}
void MonsterCard::set_freeze(bool freezeOrNot)
{
	isFreezed = freezeOrNot;
}