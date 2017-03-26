#include "Battlefield.h"
#include "Card.h"

Battlefield::Battlefield()
	{
	}

	void Battlefield::putACardOnTheField(Card field[4][5], Card card,unsigned int i, unsigned int j)
	{
		field_[i][j] = card;
	}

	Card Battlefield::takeACardFromTheField(Card card, unsigned int i, unsigned int j) const
	{
		return field_[i][j];
	}

	Card Battlefield::takeACardFromTheDeck(int player) const
	{
	    switch (player)
	    {
            case 1: return player1.drawCard(); break;
            case 2: return player2.drawCard(); break;
        }
	}

	void Battlefield::damage_(int player, int dmg)
	{
	    switch (player)
	    {
            case 1: player1.damage(dmg); break;
            case 2: player2.damage(dmg); break;
        }
    }
    Battlefield::~Battlefield()
	{
	}
