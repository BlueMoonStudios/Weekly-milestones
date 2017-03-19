#pragma once

class Hero
{
public:

	int _lifePoints;
	enum HeroType
	{
		Mage,
		Paladin,
		Priest,
		Hunter,
		Warrior,
		Rogue,
		Shaman,
		Droid,
		Witch,
	};

	///Constructor
	Hero(int lifePoints, HeroType type);

	///Akasesors
	int get_lifePoints() const;
	const char* get_type() const;

	///mutators
	int set_lifePoints(int damage);




private:
	HeroType _type;

};
