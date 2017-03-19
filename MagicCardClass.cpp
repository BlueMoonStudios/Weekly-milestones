#include "MagicCardClass.h"
#include <iostream>



MagicCard::MagicCard(int duration, int value, Magic magic)
{
	duration = 2;
	value = 1;
	magic = IncreaseCreatureAttack;
}

MagicCard::MagicCard()  //Default constructor
{
};


int MagicCard::get_duration() const
{
	return _duration;
}

int MagicCard::get_value() const
{
	return _value;
}
const char* MagicCard::get_magic() const
{
	switch (_magic)
	{
	case Magic::IncreaseCreatureAttack: return "IncreaseCreatureAttack";
	case Magic::IncreaseCreatureDefence: return "IncreaseCreatureDefence";
	case Magic::DecreaseEnemyCreatureAttack: return "DecreaseEnemyCreatureAttack";
	case Magic::DecreaseEnemyCreatureDefence: return "DecreaseEnemyCreatureDefence";
	case Magic::IncreaseLifePoints: return "IncreaseLifePoints";
	case Magic::DecreaseEnemyLifePoints: return "DecreaseEnemyLifePoints";
	}
}
