
#include "ClassDeck.h"
#include "CardHero.h"
#include "MagicCardClass.h"



Deck::Deck() //Default constructor
{
};


MagicCard Deck::get_magicCard()
{
	return (_DeckMagic[(0 + 15) / 2]);
}

Card Deck::get_creatureCard()
{
	return (_DeckCreature[(0 + 15) / 2]);
}
