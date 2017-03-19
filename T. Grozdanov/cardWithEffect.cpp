#include "cardWithEffect.hpp"
#include <assert.h>

//constructor
CardWithEffect::CardWithEffect(Type _type, char _name[30], int _nameLen,char _descrip[200],int _descripLen)
{
	type = _type;
	nameLen = _nameLen;
	descripLen = _descripLen;
	for (int i = 0; i <= nameLen; i++)
	{
		assert(i < 30);
		name[i] = _name[i];
	}
	name[nameLen] = '\0';
	for (int i = 0; i < descripLen; i++)
	{
		assert(i < 200);
		descrip[i] = _descrip[i];
	}
	descrip[descripLen] = '\0';
}
CardWithEffect::CardWithEffect()
{
	type = spell;
	name[0] = '\0';
	descrip[0] = '\0';
}
//accessors
const char* CardWithEffect::get_name() const
{
	return name;
}
const char* CardWithEffect::get_descrip() const
{
	return descrip;
}
int CardWithEffect::get_descripLen()
{
	return descripLen;
}
int CardWithEffect::get_nameLen()
{
	return nameLen;
}
//methodes
void CardWithEffect::decreaseHealth(int damage, MonsterCard &monster)
{
	monster.set_health(monster.get_health() - damage);
}
void CardWithEffect::freezeMonster(MonsterCard &monster)
{
	monster.set_freeze(1);
}
void CardWithEffect::unfreezeMonster(MonsterCard &monster)
{
	monster.set_freeze(0);
}