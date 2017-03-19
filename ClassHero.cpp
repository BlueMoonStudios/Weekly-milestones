#include "classHero.h"
#include <iostream>


Hero::Hero(int lifePoints, HeroType type)
{
	lifePoints = 3;
	type = Priest;
}



int Hero::get_lifePoints() const
{
	return _lifePoints;
}

const char* Hero::get_type() const
{
	switch (_type)
	{
	case HeroType::Mage: return "Mage";
	case HeroType::Paladin: return "Paladin";
	case HeroType::Priest: return "Priest";
	case HeroType::Hunter: return "Hunter";
	case HeroType::Warrior: return "Warrior";
	case HeroType::Rogue: return "Rogue";
	case HeroType::Shaman: return "Shaman";
	case HeroType::Droid: return "Droid";
	case HeroType::Witch: return "Witch";
	}
}
int Hero::set_lifePoints(int damage)
{
	_lifePoints = _lifePoints - damage;
	return _lifePoints;
}



