#pragma once

#include "MagicCardClass.h"
#include "CardHero.h"
class Deck
{
public:
	

	Deck();


	Card _DeckCreature [15];
	MagicCard _DeckMagic [15];
	
	MagicCard get_magicCard();
	Card get_creatureCard();
};
