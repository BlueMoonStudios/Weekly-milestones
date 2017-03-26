#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Card.h"

class Battlefield
{
public:
    Battlefield();

    void damage_(int, int);
   	void putACardOnTheField(Card, Card, unsigned int, unsigned int);

	Card takeACardFromTheField(Card, unsigned int, unsigned int) const;
    Card takeACardFromTheDeck(int) const;

    ~Battlefield();

private:
	Player player1;
	Player player2;
	Card field_[4][5];
};

#endif // BATTLEFIELD_H
