#pragma once

class MagicCard
{
public:
	enum Magic
	{
		IncreaseCreatureAttack,
		IncreaseCreatureDefence,
		DecreaseEnemyCreatureAttack,
		DecreaseEnemyCreatureDefence,
		IncreaseLifePoints,
		DecreaseEnemyLifePoints,
	};

	MagicCard(int duration, int value, Magic magic);
	MagicCard();

	int get_duration() const;
	int get_value() const;
	const char* get_magic() const;





private:
	int _duration; ///How many turns does the magic of the card lasts
	int _value; ///How many points are added/taken with the magic
	Magic _magic; ///What kind of magic

};






