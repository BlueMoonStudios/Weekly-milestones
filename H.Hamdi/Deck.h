#ifndef DECK_HPP
#define DECK_HPP

#include "Card.h"

class Deck
{
public:
    Deck();

    Card takeACard() const;

    void returnACard(Card, Card, int);

    ~Deck();

private:
    Card deck_[30];

};

#endif // DECK_HPP
